--- bwt_lite.c.orig	2014-05-19 13:11:41 UTC
+++ bwt_lite.c
@@ -48,7 +48,7 @@ bwtl_t *bwtl_seq2bwtl(int len, const uin
 	}
 	{ // generate cnt_table
 		for (i = 0; i != 256; ++i) {
-			u_int32_t j, x = 0;
+			uint32_t j, x = 0;
 			for (j = 0; j != 4; ++j)
 				x |= (((i&3) == j) + ((i>>2&3) == j) + ((i>>4&3) == j) + (i>>6 == j)) << (j<<3);
 			b->cnt_table[i] = x;
