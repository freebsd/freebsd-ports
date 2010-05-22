--- ./libmpcenc/encode_sv7.c.orig	2009-02-23 19:15:46.000000000 +0100
+++ ./libmpcenc/encode_sv7.c	2010-05-16 17:59:52.000000000 +0200
@@ -24,6 +24,8 @@
 #include "libmpcenc.h"
 #include <mpc/minimax.h>
 
+#define log2(x)             ( log (x) * (1./M_LN2) )
+
 void Klemm ( void );
 void Init_Skalenfaktoren ( void );
 
@@ -437,11 +439,11 @@
 			total_cnt += sym[j][i].Count;
 			total_size += sym[j][i].Count * sym[j][i].Bits;
 			if (sym[j][i].Count != 0)
-				optim_size += sym[j][i].Count * __builtin_log2(sym[j][i].Count);
+				optim_size += sym[j][i].Count * log2(sym[j][i].Count);
 		}
 		full_count += total_cnt;
 		full_size += total_size;
-		optim_size = total_cnt * __builtin_log2(total_cnt) - optim_size;
+		optim_size = total_cnt * log2(total_cnt) - optim_size;
 		full_optim += optim_size;
 		size[j] = total_size;
 		cnt[j] = total_cnt;
