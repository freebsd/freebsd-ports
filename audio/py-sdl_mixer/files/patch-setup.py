--- setup.py.orig	Fri Oct 28 00:13:10 2005
+++ setup.py	Fri Oct 28 00:14:18 2005
@@ -17,12 +17,14 @@
 
 INCDIR = [
   "/usr/include",
-  "/usr/local/include",
+  "%%LOCALBASE%%/include",
+  "%%X11BASE%%/include",
   "/sw/include", # For Mac OS X
   ]
 LIBDIR = [
   "/usr/lib",
-  "/usr/local/lib",
+  "%%LOCALBASE%%/lib",
+  "%%X11BASE%%/lib",
   "/sw/lib/", # For Mac OS X
   ]
 
