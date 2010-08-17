--- src/disorder.c.orig	2010-08-17 16:15:30.000000000 +0800
+++ src/disorder.c	2010-08-17 16:22:27.000000000 +0800
@@ -25,6 +25,10 @@
 #include <stdio.h> //for NULL
 #include "../include/disorder.h"
 
+#if defined(__FreeBSD__)
+#define	log2(x)	(log((x)) * (1./M_LN2))
+#endif
+
 /** Frequecies for each byte */
 static int m_token_freqs[LIBDO_MAX_BYTES]; //frequency of each token in sample
 static float m_token_probs[LIBDO_MAX_BYTES]; //P(each token appearing)
