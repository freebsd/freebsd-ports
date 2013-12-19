--- pskmodem/pskmodem.c.orig	2013-12-13 20:07:01.214995855 -0500
+++ pskmodem/pskmodem.c	2013-12-13 20:07:04.005995698 -0500
@@ -262,7 +262,7 @@
 	}
 }
 
-extern inline int calcsync(int *toten, int *corren, cplxshort_t *samples)
+inline int calcsync(int *toten, int *corren, cplxshort_t *samples)
 {
 	const cplxshort_t *tr = traincorrrotated;
 	unsigned int i;
