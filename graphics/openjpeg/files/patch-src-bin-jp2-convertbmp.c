Fix CVE-2018-5785 and CVE-2018-6616

Obtained from:	https://github.com/uclouvain/openjpeg/commit/ca16fe55014c57090dd97369256c7657aeb25975
		https://github.com/uclouvain/openjpeg/commit/8ee335227bbcaf1614124046aa25e53d67b11ec3

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
@@ -519,14 +534,14 @@ static OPJ_BOOL bmp_read_raw_data(FILE* 
 static OPJ_BOOL bmp_read_rle8_data(FILE* IN, OPJ_UINT8* pData,
                                    OPJ_UINT32 stride, OPJ_UINT32 width, OPJ_UINT32 height)
 {
-    OPJ_UINT32 x, y;
+    OPJ_UINT32 x, y, written;
     OPJ_UINT8 *pix;
     const OPJ_UINT8 *beyond;
 
     beyond = pData + stride * height;
     pix = pData;
 
-    x = y = 0U;
+    x = y = written = 0U;
     while (y < height) {
         int c = getc(IN);
         if (c == EOF) {
@@ -546,6 +561,7 @@ static OPJ_BOOL bmp_read_rle8_data(FILE*
             for (j = 0; (j < c) && (x < width) &&
                     ((OPJ_SIZE_T)pix < (OPJ_SIZE_T)beyond); j++, x++, pix++) {
                 *pix = c1;
+                written++;
             }
         } else {
             c = getc(IN);
@@ -583,6 +599,7 @@ static OPJ_BOOL bmp_read_rle8_data(FILE*
                     }
                     c1 = (OPJ_UINT8)c1_int;
                     *pix = c1;
+                    written++;
                 }
                 if ((OPJ_UINT32)c & 1U) { /* skip padding byte */
                     c = getc(IN);
@@ -593,6 +610,12 @@ static OPJ_BOOL bmp_read_rle8_data(FILE*
             }
         }
     }/* while() */
+
+    if (written != width * height) {
+        fprintf(stderr, "warning, image's actual size does not match advertized one\n");
+        return OPJ_FALSE;
+    }
+
     return OPJ_TRUE;
 }
 
@@ -831,6 +854,12 @@ opj_image_t* bmptoimage(const char *file
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
