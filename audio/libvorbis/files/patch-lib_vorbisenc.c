CVE-2018-10392: Sanity check number of channels in setup.
https://gitlab.xiph.org/xiph/vorbis/-/commit/112d3bd0aaacad51305e1464d4b381dabad0e88b
--- lib/vorbisenc.c.orig	2020-06-28 19:38:54 UTC
+++ lib/vorbisenc.c
@@ -684,6 +684,7 @@ int vorbis_encode_setup_init(vorbis_info *vi){
   highlevel_encode_setup *hi=&ci->hi;
 
   if(ci==NULL)return(OV_EINVAL);
+  if(vi->channels<1||vi->channels>255)return(OV_EINVAL);
   if(!hi->impulse_block_p)i0=1;
 
   /* too low/high an ATH floater is nonsensical, but doesn't break anything */
