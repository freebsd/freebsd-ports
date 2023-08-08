--- src/quaqut.h.orig	2023-04-13 09:01:23 UTC
+++ src/quaqut.h
@@ -114,7 +114,7 @@ int quaqut_utils_bufferize4bytes( unsigned char* , uns
 int quaqut_utils_bufferizestring( unsigned char* , unsigned char* , int );
 
 
-struct {
+extern struct quaqut {
 
   char command;
   unsigned int options;
