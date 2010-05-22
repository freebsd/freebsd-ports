--- ./common/huffman-bcl.c.orig	2007-03-17 00:25:28.000000000 +0100
+++ ./common/huffman-bcl.c	2010-05-16 18:01:56.000000000 +0200
@@ -30,9 +30,12 @@
 * marcus.geelnard at home.se
 *************************************************************************/
 
+#include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
 
+#define log2(x)             ( log (x) * (1./M_LN2) )
+
 typedef struct {
     int Symbol;
     unsigned int Count;
@@ -265,9 +268,9 @@
 				total_cnt += sym[i].Count;
 				total_size += sym[i].Count * sym[i].Bits;
 				if (sym[i].Count != 0)
-					optim_size += sym[i].Count * __builtin_log2(sym[i].Count);
+					optim_size += sym[i].Count * log2(sym[i].Count);
 			}
-			optim_size = total_cnt * __builtin_log2(total_cnt) - optim_size;
+			optim_size = total_cnt * log2(total_cnt) - optim_size;
 			printf("\ncount : %u huff : %f bps ", total_cnt, (float)total_size / total_cnt);
 			printf("opt : %f bps ", (float)optim_size / total_cnt);
 			printf("loss : %f bps (%f %%)\n", (float)(total_size - optim_size) / total_cnt, (float)(total_size - optim_size) * 100 / optim_size);
