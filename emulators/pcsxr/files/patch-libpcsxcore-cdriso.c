Use zlib's uncompress() function

--- libpcsxcore/cdriso.c.orig	2017-01-21 13:51:48.486985000 +0000
+++ libpcsxcore/cdriso.c	2017-01-21 13:53:55.623314000 +0000
@@ -1210,6 +1210,7 @@
 	return ret;
 }
 
+#if 0
 static int uncompress2(void *out, unsigned long *out_size, void *in, unsigned long in_size)
 {
 	static z_stream z;
@@ -1240,6 +1241,7 @@
 	*out_size -= z.avail_out;
 	return ret == 1 ? 0 : ret;
 }
+#endif
 
 static int cdread_compressed(FILE *f, unsigned int base, void *dest, int sector)
 {
@@ -1289,7 +1291,7 @@
 	if (is_compressed) {
 		cdbuffer_size_expect = sizeof(compr_img->buff_raw[0]) << compr_img->block_shift;
 		cdbuffer_size = cdbuffer_size_expect;
-		ret = uncompress2(compr_img->buff_raw[0], &cdbuffer_size, compr_img->buff_compressed, size);
+		ret = uncompress(compr_img->buff_raw[0], &cdbuffer_size, compr_img->buff_compressed, size);
 		if (ret != 0) {
 			SysPrintf("uncompress failed with %d for block %d, sector %d\n",
 					ret, block, sector);
