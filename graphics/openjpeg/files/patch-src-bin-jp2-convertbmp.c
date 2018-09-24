Fix CVE-2018-5785

Obtained from:	https://github.com/uclouvain/openjpeg/commit/ca16fe55014c57090dd97369256c7657aeb25975

--- src/bin/jp2/convertbmp.c.orig	2017-10-04 22:23:14 UTC
+++ src/bin/jp2/convertbmp.c
@@ -435,16 +435,31 @@ static OPJ_BOOL bmp_read_info_header(FIL
         header->biRedMask |= (OPJ_UINT32)getc(IN) << 16;
         header->biRedMask |= (OPJ_UINT32)getc(IN) << 24;
 
+        if (!header->biRedMask) {
+            fprintf(stderr, "Error, invalid red mask value %d\n", header->biRedMask);
+            return OPJ_FALSE;
+        }
+
         header->biGreenMask  = (OPJ_UINT32)getc(IN);
         header->biGreenMask |= (OPJ_UINT32)getc(IN) << 8;
         header->biGreenMask |= (OPJ_UINT32)getc(IN) << 16;
         header->biGreenMask |= (OPJ_UINT32)getc(IN) << 24;
 
+        if (!header->biGreenMask) {
+            fprintf(stderr, "Error, invalid green mask value %d\n", header->biGreenMask);
+            return OPJ_FALSE;
+        }
+
         header->biBlueMask  = (OPJ_UINT32)getc(IN);
         header->biBlueMask |= (OPJ_UINT32)getc(IN) << 8;
         header->biBlueMask |= (OPJ_UINT32)getc(IN) << 16;
         header->biBlueMask |= (OPJ_UINT32)getc(IN) << 24;
 
+        if (!header->biBlueMask) {
+            fprintf(stderr, "Error, invalid blue mask value %d\n", header->biBlueMask);
+            return OPJ_FALSE;
+        }
+
         header->biAlphaMask  = (OPJ_UINT32)getc(IN);
         header->biAlphaMask |= (OPJ_UINT32)getc(IN) << 8;
         header->biAlphaMask |= (OPJ_UINT32)getc(IN) << 16;
@@ -831,6 +846,12 @@ opj_image_t* bmptoimage(const char *file
         bmpmask32toimage(pData, stride, image, 0x00FF0000U, 0x0000FF00U, 0x000000FFU,
                          0x00000000U);
     } else if (Info_h.biBitCount == 32 && Info_h.biCompression == 3) { /* bitmask */
+        if ((Info_h.biRedMask == 0U) && (Info_h.biGreenMask == 0U) &&
+                (Info_h.biBlueMask == 0U)) {
+            Info_h.biRedMask   = 0x00FF0000U;
+            Info_h.biGreenMask = 0x0000FF00U;
+            Info_h.biBlueMask  = 0x000000FFU;
+        }
         bmpmask32toimage(pData, stride, image, Info_h.biRedMask, Info_h.biGreenMask,
                          Info_h.biBlueMask, Info_h.biAlphaMask);
     } else if (Info_h.biBitCount == 16 && Info_h.biCompression == 0) { /* RGBX */
