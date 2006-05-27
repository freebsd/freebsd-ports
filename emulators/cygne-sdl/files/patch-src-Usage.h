--- Usage.h.orig	Tue Mar 26 09:55:20 2002
+++ Usage.h	Thu May  4 18:27:46 2006
@@ -1,13 +1,13 @@
 void Usage()
 {
 printf(
-"Usage: ./cygne romfile options
- Where options are:
-
- romfile           : Filename of the romfile. It can have several
-                     extensions (.ws/.wsc/.rom/.bin). Gzipped and
-                     zipped (.gz and .zip) are also supported.
- -double           : Scale the screen 2 times the normal size.
- -scanline         : Allows scanline output with scaling.
-");
+"Usage: ./cygne romfile options\n"
+" Where options are:\n"
+"\n"
+" romfile           : Filename of the romfile. It can have several\n"
+"                     extensions (.ws/.wsc/.rom/.bin). Gzipped and\n"
+"                     zipped (.gz and .zip) are also supported.\n"
+" -double           : Scale the screen 2 times the normal size.\n"
+" -scanline         : Allows scanline output with scaling.\n"
+);
 }
