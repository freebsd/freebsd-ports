--- ./setup.py.orig	2005-07-29 16:16:50.000000000 +0200
+++ ./setup.py	2008-04-13 21:35:05.000000000 +0200
@@ -17,12 +17,12 @@
 
 INCDIR = [
   "/usr/include",
-  "/usr/local/include",
+  "%%LOCALBASE%%/include",
   "/sw/include", # For Mac OS X
   ]
 LIBDIR = [
   "/usr/lib",
-  "/usr/local/lib",
+  "%%LOCALBASE%%/lib",
   "/sw/lib/", # For Mac OS X
   ]
 
