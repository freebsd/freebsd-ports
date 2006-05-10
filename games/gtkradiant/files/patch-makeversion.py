--- ./makeversion.py.orig	Sun Feb 12 16:47:01 2006
+++ ./makeversion.py	Thu Mar 16 16:09:46 2006
@@ -82,7 +82,7 @@
     line = f.readline()
     f.close()
   else:
-    line = "Custom build based on revision " + str(svn.getRevision(os.getcwd()))
+    line = "Custom build based on revision 1.0"
   # optional additional message
   if ( not append_about is None ):
     line += append_about
