Index: lib/tempfile.rb
===================================================================
RCS file: /src/ruby/lib/tempfile.rb,v
retrieving revision 1.6.2.2
retrieving revision 1.6.2.4
diff -u -r1.6.2.2 -r1.6.2.4
--- lib/tempfile.rb	11 Sep 2002 07:17:18 -0000	1.6.2.2
+++ lib/tempfile.rb	18 Nov 2002 07:26:44 -0000	1.6.2.4
@@ -1,31 +1,43 @@
 #
-# $Id: tempfile.rb,v 1.6.2.2 2002/09/11 07:17:18 knu Exp $
+# $Id: tempfile.rb,v 1.6.2.4 2002/11/18 07:26:44 knu Exp $
 #
-# The class for temporary files.
-#  o creates a temporary file, which name is "basename.pid.n" with mode "w+".
-#  o Tempfile objects can be used like IO object.
-#  o with tempfile.close(true) created temporary files are removed.
-#  o created files are also removed on script termination.
-#  o with Tempfile#open, you can reopen the temporary file.
-#  o file mode of the temporary files are 0600.
+# This is a class for managing temporary files.
+#
+#  o Tempfile::new("basename") creates a temporary file whose name is
+#    "basename.pid.n" and opens with mode "w+".
+#  o A Tempfile object can be treated as an IO object.
+#  o The temporary directory is determined by ENV['TMPDIR'],
+#    ENV['TMP'], and ENV['TEMP'] in the order named, and if none of
+#    them is available, it is set to /tmp.
+#  o When $SAFE > 0, you should specify a directory via the second argument
+#    of Tempfile::new(), or it will end up finding an ENV value tainted and
+#    pick /tmp.  In case you don't have it, an exception will be raised.
+#  o Tempfile#close(true) gets the temporary file removed immediately.
+#  o Otherwise, the removal is delayed until the object is finalized.
+#  o With Tempfile#open, you can reopen the temporary file.
+#  o The file mode for the temporary files is 0600.
+#  o This library is (considered to be) thread safe.
 
 require 'delegate'
 
 class Tempfile < SimpleDelegator
   Max_try = 10
+  @@cleanlist = []
 
-  def Tempfile.callback(path, data)
+  def Tempfile.callback(data)
     pid = $$
     lambda{
       if pid == $$ 
+	path, tmpfile, cleanlist = *data
+
 	print "removing ", path, "..." if $DEBUG
-	data[0].close if data[0]
-	if File.exist?(path)
-	  File.unlink(path) 
-	end
-	if File.exist?(path + '.lock')
-	  Dir.rmdir(path + '.lock')
-	end
+
+	tmpfile.close if tmpfile
+
+	# keep this order for thread safeness
+	File.unlink(path) if File.exist?(path)
+	cleanlist.delete(path) if cleanlist
+
 	print "done\n" if $DEBUG
       end
     }
@@ -35,30 +47,44 @@
     if $SAFE > 0 and tmpdir.tainted?
       tmpdir = '/tmp'
     end
-    n = 0
-    while true
+
+    lock = nil
+    n = failure = 0
+    
+    begin
+      Thread.critical = true
+
       begin
 	tmpname = sprintf('%s/%s%d.%d', tmpdir, basename, $$, n)
 	lock = tmpname + '.lock'
-	unless File.exist?(tmpname) or File.exist?(lock)
-	  Dir.mkdir(lock)
-	  break
-	end
-      rescue
-	raise "cannot generate tempfile `%s'" % tmpname if n >= Max_try
-	#sleep(1)
-      end
-      n += 1
+	n += 1
+      end while @@cleanlist.include?(tmpname) or
+	File.exist?(lock) or File.exist?(tmpname)
+
+      Dir.mkdir(lock)
+    rescue
+      failure += 1
+      retry if failure < Max_try
+      raise "cannot generate tempfile `%s'" % tmpname
+    ensure
+      Thread.critical = false
     end
 
-    @protect = []
-    @clean_files = Tempfile.callback(tmpname, @protect)
-    ObjectSpace.define_finalizer(self, @clean_files)
+    @data = [tmpname]
+    @clean_proc = Tempfile.callback(@data)
+    ObjectSpace.define_finalizer(self, @clean_proc)
 
     @tmpfile = File.open(tmpname, File::RDWR|File::CREAT|File::EXCL, 0600)
-    @protect[0] = @tmpfile
     @tmpname = tmpname
+    @@cleanlist << @tmpname
+    @data[1] = @tmpfile
+    @data[2] = @@cleanlist
+
     super(@tmpfile)
+
+    # Now we have all the File/IO methods defined, you must not
+    # carelessly put bare puts(), etc. after this.
+
     Dir.rmdir(lock)
   end
 
@@ -69,15 +95,15 @@
   def open
     @tmpfile.close if @tmpfile
     @tmpfile = File.open(@tmpname, 'r+')
-    @protect[0] = @tmpfile
+    @data[1] = @tmpfile
     __setobj__(@tmpfile)
   end
 
   def close(real=false)
     @tmpfile.close if @tmpfile
-    @protect[0] = @tmpfile = nil
+    @data[1] = @tmpfile = nil
     if real
-      @clean_files.call
+      @clean_proc.call
       ObjectSpace.undefine_finalizer(self)
     end
   end
