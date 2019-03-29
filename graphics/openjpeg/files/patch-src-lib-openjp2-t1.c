Obtained from:	https://github.com/uclouvain/openjpeg/commit/d6b8aed5612e6be6d3a4053867fbd2ae0cb7c8af

--- src/lib/openjp2/t1.c.orig	2017-10-04 22:23:14 UTC
+++ src/lib/openjp2/t1.c
@@ -2168,9 +2168,18 @@ OPJ_BOOL opj_t1_encode_cblks(opj_t1_t *t
                         t1->data = tiledp;
                         t1->data_stride = tile_w;
                         if (tccp->qmfbid == 1) {
+                            /* Do multiplication on unsigned type, even if the
+                             * underlying type is signed, to avoid potential
+                             * int overflow on large value (the output will be
+                             * incorrect in such situation, but whatever...)
+                             * This assumes complement-to-2 signed integer
+                             * representation
+                             * Fixes https://github.com/uclouvain/openjpeg/issues/1053
+                             */
+                            OPJ_UINT32* OPJ_RESTRICT tiledp_u = (OPJ_UINT32*) tiledp;
                             for (j = 0; j < cblk_h; ++j) {
                                 for (i = 0; i < cblk_w; ++i) {
-                                    tiledp[tileIndex] *= (1 << T1_NMSEDEC_FRACBITS);
+                                    tiledp_u[tileIndex] <<= T1_NMSEDEC_FRACBITS;
                                     tileIndex++;
                                 }
                                 tileIndex += tileLineAdvance;
