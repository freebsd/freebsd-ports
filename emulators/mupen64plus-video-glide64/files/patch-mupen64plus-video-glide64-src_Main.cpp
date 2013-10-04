--- mupen64plus-video-glide64/src/Main.cpp	2013-10-04 03:40:24.000000000 -0500
+++ mupen64plus-video-glide64/src/Main.cpp	2013-10-04 03:41:24.000000000 -0500
@@ -634,11 +634,8 @@
   for (i=0; i<0x200; i++)
   {
     // cur = ~*(data++), byteswapped
-#if !defined(__GNUC__)
-     cur = _byteswap_ulong(~*(data++));
-#else
-     cur = __builtin_bswap32(~*(data++));
-#endif
+
+    cur = bswap32(~*(data++));
 
     for (b=0x80000000; b!=0; b>>=1)
     {
