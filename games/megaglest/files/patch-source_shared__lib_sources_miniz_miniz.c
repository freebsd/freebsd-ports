--- source/shared_lib/sources/miniz/miniz.c.orig	2015-04-13 04:50:02 UTC
+++ source/shared_lib/sources/miniz/miniz.c
@@ -2765,6 +2765,7 @@ mz_uint tdefl_create_comp_flags_from_zip
 // http://altdevblogaday.org/2011/04/06/a-smaller-jpg-encoder/.
 void *tdefl_write_image_to_png_file_in_memory(const void *pImage, int w, int h, int num_chans, size_t *pLen_out)
 {
+  static const mz_uint8 chans[] = {0x00, 0x00, 0x04, 0x02, 0x06};
   tdefl_compressor *pComp = (tdefl_compressor *)MZ_MALLOC(sizeof(tdefl_compressor)); tdefl_output_buffer out_buf; int i, bpl = w * num_chans, y, z; mz_uint32 c; *pLen_out = 0;
   if (!pComp) return NULL;
   MZ_CLEAR_OBJ(out_buf); out_buf.m_expandable = MZ_TRUE; out_buf.m_capacity = 57+MZ_MAX(64, (1+bpl)*h); if (NULL == (out_buf.m_pBuf = (mz_uint8*)MZ_MALLOC(out_buf.m_capacity))) { MZ_FREE(pComp); return NULL; }
@@ -2778,7 +2779,7 @@ void *tdefl_write_image_to_png_file_in_m
   *pLen_out = out_buf.m_size-41;
   {
     mz_uint8 pnghdr[41]={0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
-      0,0,(mz_uint8)(w>>8),(mz_uint8)w,0,0,(mz_uint8)(h>>8),(mz_uint8)h,8,"\0\0\04\02\06"[num_chans],0,0,0,0,0,0,0,
+      0,0,(mz_uint8)(w>>8),(mz_uint8)w,0,0,(mz_uint8)(h>>8),(mz_uint8)h,8,chans[num_chans],0,0,0,0,0,0,0,
       (mz_uint8)(*pLen_out>>24),(mz_uint8)(*pLen_out>>16),(mz_uint8)(*pLen_out>>8),(mz_uint8)*pLen_out,0x49,0x44,0x41,0x54};
     c=(mz_uint32)mz_crc32(MZ_CRC32_INIT,pnghdr+12,17); for (i=0; i<4; ++i, c<<=8) ((mz_uint8*)(pnghdr+29))[i]=(mz_uint8)(c>>24);
     memcpy(out_buf.m_pBuf, pnghdr, 41);
