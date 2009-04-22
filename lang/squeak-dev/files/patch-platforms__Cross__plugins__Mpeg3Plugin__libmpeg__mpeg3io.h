--- platforms/Cross/plugins/Mpeg3Plugin/libmpeg/mpeg3io.h.orig	2006-04-15 01:17:20.000000000 +0200
+++ platforms/Cross/plugins/Mpeg3Plugin/libmpeg/mpeg3io.h	2009-04-11 14:54:38.000000000 +0200
@@ -35,7 +35,7 @@
 #endif
 
 #define mpeg3io_total_bytes(fs) (((mpeg3_fs_t *)(fs))->total_bytes)
-inline int mpeg3io_fgetc(mpeg3_fs_t *fs);
+int mpeg3io_fgetc(mpeg3_fs_t *fs);
 
 static inline unsigned int mpeg3io_read_int32(mpeg3_fs_t *fs)
 {
