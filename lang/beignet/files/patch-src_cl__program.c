--- src/cl_program.c.orig	2015-02-03 14:59:12.541061000 +0100
+++ src/cl_program.c	2015-02-03 15:00:05.989743000 +0100
@@ -166,7 +166,8 @@
   return err;
 }
 
-inline cl_bool isBitcodeWrapper(const unsigned char *BufPtr, const unsigned char *BufEnd)
+static inline cl_bool 
+isBitcodeWrapper(const unsigned char *BufPtr, const unsigned char *BufEnd)
 {
   // See if you can find the hidden message in the magic bytes :-).
   // (Hint: it's a little-endian encoding.)
@@ -177,7 +178,8 @@
     BufPtr[3] == 0x0B;
 }
 
-inline cl_bool isRawBitcode(const unsigned char *BufPtr, const unsigned char *BufEnd)
+static inline cl_bool 
+isRawBitcode(const unsigned char *BufPtr, const unsigned char *BufEnd)
 {
   // These bytes sort of have a hidden message, but it's not in
   // little-endian this time, and it's a little redundant.
