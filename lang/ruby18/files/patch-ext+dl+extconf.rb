--- ext/dl/extconf.rb.orig	Mon Oct 21 23:52:24 2002
+++ ext/dl/extconf.rb	Sun Jul 20 00:55:25 2003
@@ -183,6 +183,16 @@
 ]
 
 create_makefile('dl')
+
+if (Config::CONFIG['CC'] =~ /gcc/) && (Config::CONFIG['arch'] =~ /i.86/)
+  open('Makefile', 'r+') {|f|
+    s = f.read
+    f.rewind
+    f.print s.gsub(/^(CFLAGS\s*=.*\s)-m(cpu|arch)=\S+/, "\\1")
+    f.truncate f.tell
+  }
+end
+
 rescue SystemExit
   # do nothing
 end
