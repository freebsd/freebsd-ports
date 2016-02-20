--- pammodem/pammodem.c.orig	2015-05-04 17:58:30 UTC
+++ pammodem/pammodem.c
@@ -160,7 +160,7 @@ struct rxstate {
 	unsigned int rxptr;
 };
 
-extern inline int rxgsfir(const int16_t *buf, const int *coeff)
+inline int rxgsfir(const int16_t *buf, const int *coeff)
 {
 	unsigned int i;
 	int s;
@@ -207,7 +207,7 @@ static void rxrewindsamples(struct rxsta
 	rx->rxphase -= ph;
 }
 
-only_inline int calcsync(int *toten, int *corren, int16_t *samples)
+inline int calcsync(int *toten, int *corren, int16_t *samples)
 {
 	const int *tr = trainsyms;
 	unsigned int i;
