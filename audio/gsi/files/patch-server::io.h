--- server/io.h.orig	2012-11-30 14:10:22.000000000 +0100
+++ server/io.h	2012-11-30 14:10:31.000000000 +0100
@@ -34,9 +34,9 @@
 #define msb_int32_at(buf)   msb_from_native_int32(*((int32 *) (buf)))
 #define msb_int16_at(buf)   msb_from_native_int16(*((int16 *) (buf)))
 
-#define next_msb_int32(buf) ( ((((byte *) (buf))++)[0] << 24) | ((((byte *) (buf))++)[1] << 16) | ((((byte *) (buf))++)[2] << 8) | (((byte *) (buf))++)[3] )
-#define next_msb_int16(buf) ( ((((byte *) (buf))++)[0] << 8) | (((byte *) (buf))++)[1] )
-#define next_byte(buf)      ((((byte *) (buf))++)[0])
+#define next_msb_int32(buf) (((buf)++)[0] << 24 | ((buf)++)[1] << 16 | ((buf)++)[2] << 8 | ((buf)++)[3])
+#define next_msb_int16(buf) (((buf)++)[0] << 8 | ((buf)++)[1])
+#define next_byte(buf)      (((buf)++)[0])
 
 
 /* writing to clients */
