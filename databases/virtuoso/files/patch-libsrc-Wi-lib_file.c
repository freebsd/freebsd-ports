--- libsrc/Wi/bif_file.c-old	2011-10-26 15:54:19.000000000 +0200
+++ libsrc/Wi/bif_file.c	2012-01-16 17:27:07.294200532 +0100
@@ -6161,7 +6161,7 @@
 }
 
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define fseeko64 fseeko
 #define ftello64 ftello
 #define fopen64  fopen
