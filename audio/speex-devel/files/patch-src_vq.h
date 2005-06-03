--- libspeex/vq.h.orig	Fri Jun  3 13:39:38 2005
+++ libspeex/vq.h	Fri Jun  3 13:39:47 2005
@@ -41,9 +41,9 @@
 int vq_index(float *in, const float *codebook, int len, int entries);
 #ifdef _USE_SSE
 #include <xmmintrin.h>
-void vq_nbest(spx_word16_t *in, const __m128 *codebook, int len, int entries, __m128 *E, int N, int *nbest, spx_word32_t *best_dist, char *stack);
+// void vq_nbest(spx_word16_t *in, const __m128 *codebook, int len, int entries, __m128 *E, int N, int *nbest, spx_word32_t *best_dist, char *stack);
 
-void vq_nbest_sign(spx_word16_t *in, const __m128 *codebook, int len, int entries, __m128 *E, int N, int *nbest, spx_word32_t *best_dist, char *stack);
+// void vq_nbest_sign(spx_word16_t *in, const __m128 *codebook, int len, int entries, __m128 *E, int N, int *nbest, spx_word32_t *best_dist, char *stack);
 #else
 void vq_nbest(spx_word16_t *in, const spx_word16_t *codebook, int len, int entries, spx_word32_t *E, int N, int *nbest, spx_word32_t *best_dist, char *stack);
 
