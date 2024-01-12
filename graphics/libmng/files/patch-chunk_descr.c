--- libmng_chunk_descr.c	2012-07-29 15:26:34.000000000 -0400
+++ libmng_chunk_descr.c	2024-01-08 14:32:15.916979000 -0500
@@ -2751,5 +2751,5 @@
       mng_get_chunkheader (MNG_UINT_sRGB, &chunk_srgb);
                                        /* pretend it's an sRGB chunk then ! */
-      iRetcode = mng_read_general (pData, &chunk_srgb, 1, (mng_ptr)"0", &pDummy);
+      iRetcode = mng_read_general (pData, &chunk_srgb, 1, (mng_ptr)"0", (void **)&pDummy);
       if (iRetcode)                    /* on error bail out */
         return iRetcode;
