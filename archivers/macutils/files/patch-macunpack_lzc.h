--- macunpack/lzc.h.orig	1993-10-02 20:16:00 UTC
+++ macunpack/lzc.h
@@ -12,7 +12,7 @@
 #define C_AUTHOFF	36
 #define C_FLAGOFF	40
 
-typedef struct fileHdr {
+struct fileHdr {
 	unsigned long	magic1;
 	unsigned long	dataLength;
 	unsigned long	dataCLength;
