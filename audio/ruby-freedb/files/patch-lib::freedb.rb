--- lib/freedb.rb.orig	Wed Sep 25 15:05:37 2002
+++ lib/freedb.rb	Sat Oct  5 00:04:31 2002
@@ -58,34 +58,53 @@
   #  @tracks.clear
     @results[index] =~ /\S+ \S+/
     @handler.send_cmd("read", $&)
+
+    # swallow the whole response into a hash
+    response = Hash.new
+
     @handler.each_line { |line|
       case line
-	when /^4\d\d (.+)/
-	  raise(FreedbError, $1)
-	when /^210 (\S+)/
-	  @genre = $1
-	# #or 
-	when /^DGENRE=(.+)/
-	  @exact_genre = $1
-	when /^DYEAR=(\d+)/
-	  @year = $1.to_i
-        when /^DTITLE=(.*)/
-	  @artist, @title = $1.split(" / ")
-	  @title ||= @artist
-	when /^TTITLE(\d+)=(.*)/
-	  h = @tracks_ext[$1.to_i]
-	  h["title"] = $2
-	  @tracks[$1.to_i] = $2
-	when /^EXTD=(.*)/
-	  @ext_infos ||= ""
-	  @ext_infos += $1
-	when /^EXTT(\d+)=(.*)/
-	  h = @tracks_ext[$1.to_i]
-	  h["ext"] = $2
-	  #@tracks << md[1]
-	#when /^TTITLE\d+=/
+	when /^(\d+) (\S+)/, /^([A-Za-z0-9_]+)=(.*)/
+	  key = $1.upcase
+
+	  val = $2.gsub(/\\(.)/) {
+	    case $1
+	      when "t"
+		"\t"
+	      when "n"
+		"\n"
+	      else
+		$1
+	    end
+          }
+
+	  (response[key] ||= '') << val
       end
     }
+
+    @genre = response['210']
+    @exact_genre = response['DGENRE']
+    @year = response['DYEAR'].to_i
+    @ext_infos = response['EXTD']
+
+    # %r is to avoid ruby >= 1.7 warning
+    @artist, @title = response['DTITLE'].split(%r" / ", 2)
+    # A self-titled album may not have a title part
+    @title ||= @artist
+
+    response.each { |key, val|
+      case key
+	when /^4\d\d$/
+	  raise(FreedbError, val)
+	when /^TTITLE(\d+)$/
+	  i = $1.to_i
+	  @tracks_ext[i]["title"] = @tracks[i] = val
+	when /^EXTT(\d+)$/
+	  i = $1.to_i
+	  @tracks_ext[i]["ext"] = val
+      end
+    }
+
     self
   end
   
