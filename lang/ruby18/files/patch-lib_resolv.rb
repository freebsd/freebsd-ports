--- lib/resolv.rb.orig	2008-08-10 14:36:37.000000000 +0400
+++ lib/resolv.rb	2008-08-10 14:38:09.000000000 +0400
@@ -194,6 +194,11 @@
 require 'timeout'
 require 'thread'
 
+begin
+  require 'securerandom'
+rescue LoadError
+end
+
 class Resolv
   def self.getaddress(name)
     DefaultResolver.getaddress(name)
@@ -388,13 +393,6 @@
       @mutex.synchronize {
         unless @initialized
           @config.lazy_initialize
-
-          if nameserver = @config.single?
-            @requester = Requester::ConnectedUDP.new(nameserver)
-          else
-            @requester = Requester::UnconnectedUDP.new
-          end
-
           @initialized = true
         end
       }
@@ -404,8 +402,6 @@
     def close
       @mutex.synchronize {
         if @initialized
-          @requester.close if @requester
-          @requester = nil
           @initialized = false
         end
       }
@@ -464,7 +460,7 @@
 
     def each_resource(name, typeclass, &proc)
       lazy_initialize
-      q = Queue.new
+      requester = make_requester
       senders = {}
       begin
         @config.resolv(name) {|candidate, tout, nameserver|
@@ -473,11 +469,9 @@
           msg.add_question(candidate, typeclass)
           unless sender = senders[[candidate, nameserver]]
             sender = senders[[candidate, nameserver]] =
-              @requester.sender(msg, candidate, q, nameserver)
+              requester.sender(msg, candidate, nameserver)
           end
-          sender.send
-          reply = reply_name = nil
-          timeout(tout, ResolvTimeout) { reply, reply_name = q.pop }
+          reply, reply_name = requester.request(sender, tout)
           case reply.rcode
           when RCode::NoError
             extract_resources(reply, reply_name, typeclass, &proc)
@@ -489,7 +483,15 @@
           end
         }
       ensure
-        @requester.delete(q)
+        requester.close
+      end
+    end
+
+    def make_requester # :nodoc:
+      if nameserver = @config.single?
+        Requester::ConnectedUDP.new(nameserver)
+      else
+        Requester::UnconnectedUDP.new
       end
     end
 
@@ -524,45 +526,105 @@
       }
     end
 
+    if defined? SecureRandom
+      def self.random(arg) # :nodoc:
+        begin
+          SecureRandom.random_number(arg)
+        rescue NotImplementedError
+          rand(arg)
+        end
+      end
+    else
+      def self.random(arg) # :nodoc:
+        rand(arg)
+      end
+    end
+
+    def self.rangerand(range) # :nodoc:
+      base = range.begin
+      len = range.end - range.begin
+      if !range.exclude_end?
+        len += 1
+      end
+      base + random(len)
+    end
+
+    RequestID = {}
+    RequestIDMutex = Mutex.new
+
+    def self.allocate_request_id(host, port) # :nodoc:
+      id = nil
+      RequestIDMutex.synchronize {
+        h = (RequestID[[host, port]] ||= {})
+        begin
+          id = rangerand(0x0000..0xffff)
+        end while h[id] 
+        h[id] = true
+      }
+      id
+    end
+
+    def self.free_request_id(host, port, id) # :nodoc:
+      RequestIDMutex.synchronize {
+        key = [host, port]
+        if h = RequestID[key]
+          h.delete id
+          if h.empty?
+            RequestID.delete key
+          end
+        end
+      }
+    end
+
+    def self.bind_random_port(udpsock) # :nodoc:
+      begin
+        port = rangerand(1024..65535)
+        udpsock.bind("", port)
+      rescue Errno::EADDRINUSE
+        retry
+      end
+    end
+
     class Requester
       def initialize
         @senders = {}
+        @sock = nil
       end
 
-      def close
-        thread, sock, @thread, @sock = @thread, @sock
-        begin
-          if thread
-            thread.kill
-            thread.join
+      def request(sender, tout)
+        timelimit = Time.now + tout
+        sender.send
+        while (now = Time.now) < timelimit
+          timeout = timelimit - now
+          if !IO.select([@sock], nil, nil, timeout)
+            raise ResolvTimeout
+          end
+          reply, from = recv_reply
+          begin
+            msg = Message.decode(reply)
+          rescue DecodeError
+            next # broken DNS message ignored
+          end
+          if s = @senders[[from,msg.id]]
+            break
+          else
+            # unexpected DNS message ignored
           end
-        ensure
-          sock.close if sock
         end
+        return msg, s.data
       end
 
-      def delete(arg)
-        case arg
-        when Sender
-          @senders.delete_if {|k, s| s == arg }
-        when Queue
-          @senders.delete_if {|k, s| s.queue == arg }
-        else
-          raise ArgumentError.new("neither Sender or Queue: #{arg}")
-        end
+      def close
+        sock = @sock
+        @sock = nil
+        sock.close if sock
       end
 
-      class Sender
-        def initialize(msg, data, sock, queue)
+      class Sender # :nodoc:
+        def initialize(msg, data, sock)
           @msg = msg
           @data = data
           @sock = sock
-          @queue = queue
-        end
-        attr_reader :queue
-
-        def recv(msg)
-          @queue.push([msg, @data])
         end
       end
 
@@ -570,45 +632,38 @@
         def initialize
           super()
           @sock = UDPSocket.new
-          @sock.fcntl(Fcntl::F_SETFD, 1) if defined? Fcntl::F_SETFD
-          @id = {}
-          @id.default = -1
-          @thread = Thread.new {
-            DNSThreadGroup.add Thread.current
-            loop {
-              reply, from = @sock.recvfrom(UDPSize)
-              msg = begin
-                Message.decode(reply)
-              rescue DecodeError
-                STDERR.print("DNS message decoding error: #{reply.inspect}\n")
-                next
-              end
-              if s = @senders[[[from[3],from[1]],msg.id]]
-                s.recv msg
-              else
-                #STDERR.print("non-handled DNS message: #{msg.inspect} from #{from.inspect}\n")
-              end
-            }
-          }
+          @sock.fcntl(Fcntl::F_SETFD, Fcntl::FD_CLOEXEC) if defined? Fcntl::F_SETFD
+          DNS.bind_random_port(@sock)
+        end
+
+        def recv_reply
+          reply, from = @sock.recvfrom(UDPSize)
+          return reply, [from[3],from[1]]
         end
 
-        def sender(msg, data, queue, host, port=Port)
+        def sender(msg, data, host, port=Port)
           service = [host, port]
-          id = Thread.exclusive {
-            @id[service] = (@id[service] + 1) & 0xffff
-          }
+          id = DNS.allocate_request_id(host, port)
           request = msg.encode
           request[0,2] = [id].pack('n')
           return @senders[[service, id]] =
-            Sender.new(request, data, @sock, host, port, queue)
+            Sender.new(request, data, @sock, host, port)
+        end
+
+        def close
+          super
+          @senders.each_key {|service, id|
+            DNS.free_request_id(service[0], service[1], id)
+          }
         end
 
         class Sender < Requester::Sender
-          def initialize(msg, data, sock, host, port, queue)
-            super(msg, data, sock, queue)
+          def initialize(msg, data, sock, host, port)
+            super(msg, data, sock)
             @host = host
             @port = port
           end
+          attr_reader :data
 
           def send
             @sock.send(@msg, 0, @host, @port)
@@ -622,42 +677,38 @@
           @host = host
           @port = port
           @sock = UDPSocket.new(host.index(':') ? Socket::AF_INET6 : Socket::AF_INET)
+          DNS.bind_random_port(@sock)
           @sock.connect(host, port)
-          @sock.fcntl(Fcntl::F_SETFD, 1) if defined? Fcntl::F_SETFD
-          @id = -1
-          @thread = Thread.new {
-            DNSThreadGroup.add Thread.current
-            loop {
-              reply = @sock.recv(UDPSize)
-              msg = begin
-                Message.decode(reply)
-              rescue DecodeError
-                STDERR.print("DNS message decoding error: #{reply.inspect}")
-                next
-              end
-              if s = @senders[msg.id]
-                s.recv msg
-              else
-                #STDERR.print("non-handled DNS message: #{msg.inspect}")
-              end
-            }
-          }
+          @sock.fcntl(Fcntl::F_SETFD, Fcntl::FD_CLOEXEC) if defined? Fcntl::F_SETFD
+        end
+
+        def recv_reply
+          reply = @sock.recv(UDPSize)
+          return reply, nil
         end
 
-        def sender(msg, data, queue, host=@host, port=@port)
+        def sender(msg, data, host=@host, port=@port)
           unless host == @host && port == @port
             raise RequestError.new("host/port don't match: #{host}:#{port}")
           end
-          id = Thread.exclusive { @id = (@id + 1) & 0xffff }
+          id = DNS.allocate_request_id(@host, @port)
           request = msg.encode
           request[0,2] = [id].pack('n')
-          return @senders[id] = Sender.new(request, data, @sock, queue)
+          return @senders[[nil,id]] = Sender.new(request, data, @sock)
+        end
+
+        def close
+          super
+          @senders.each_key {|from, id|
+            DNS.free_request_id(@host, @port, id)
+          }
         end
 
         class Sender < Requester::Sender
           def send
             @sock.send(@msg, 0)
           end
+          attr_reader :data
         end
       end
 
@@ -666,39 +717,25 @@
           super()
           @host = host
           @port = port
-          @sock = TCPSocket.new
-          @sock.connect(host, port)
-          @sock.fcntl(Fcntl::F_SETFD, 1) if defined? Fcntl::F_SETFD
-          @id = -1
+          @sock = TCPSocket.new(@host, @port)
+          @sock.fcntl(Fcntl::F_SETFD, Fcntl::FD_CLOEXEC) if defined? Fcntl::F_SETFD
           @senders = {}
-          @thread = Thread.new {
-            DNSThreadGroup.add Thread.current
-            loop {
-              len = @sock.read(2).unpack('n')
-              reply = @sock.read(len)
-              msg = begin
-                Message.decode(reply)
-              rescue DecodeError
-                STDERR.print("DNS message decoding error: #{reply.inspect}")
-                next
-              end
-              if s = @senders[msg.id]
-                s.push msg
-              else
-                #STDERR.print("non-handled DNS message: #{msg.inspect}")
-              end
-            }
-          }
         end
 
-        def sender(msg, data, queue, host=@host, port=@port)
+        def recv_reply
+          len = @sock.read(2).unpack('n')[0]
+          reply = @sock.read(len)
+          return reply, nil
+        end
+
+        def sender(msg, data, host=@host, port=@port)
           unless host == @host && port == @port
             raise RequestError.new("host/port don't match: #{host}:#{port}")
           end
-          id = Thread.exclusive { @id = (@id + 1) & 0xffff }
+          id = DNS.allocate_request_id(@host, @port)
           request = msg.encode
           request[0,2] = [request.length, id].pack('nn')
-          return @senders[id] = Sender.new(request, data, @sock, queue)
+          return @senders[[nil,id]] = Sender.new(request, data, @sock)
         end
 
         class Sender < Requester::Sender
@@ -706,6 +743,14 @@
             @sock.print(@msg)
             @sock.flush
           end
+          attr_reader :data
+        end
+
+        def close
+          super
+          @senders.each_key {|from,id|
+            DNS.free_request_id(@host, @port, id)
+          }
         end
       end
 
