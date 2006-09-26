--- Makefile.PL.orig	Sun Sep 10 23:56:49 2006
+++ Makefile.PL	Sun Sep 10 23:57:27 2006
@@ -14,6 +14,8 @@
 # installed.
 
 #$LZO_LIB     = '-L/usr/local/lib';
+$LZO_INCLUDE = '-I%%LOCALBASE%%/include';
+$LZO_LIB     = '-L%%LOCALBASE%%/lib';
 
 
 # It shouldn't be necessary to change anything from here on.
