
$FreeBSD$

--- codecs/audio/ac3/exponent.c	2001/02/04 21:17:23	1.1
+++ codecs/audio/ac3/exponent.c	2001/02/04 21:18:06
@@ -30,7 +30,7 @@
 
 #include "exponent.h"
 
-extern int error;
+extern int ac3_error;
 
 static inline void exp_unpack_ch(uint16_t type,uint16_t expstr,uint16_t ngrps,uint16_t initial_exp, uint16_t exps[], uint16_t *dest);
 
@@ -126,6 +126,6 @@
 	return;
 error:
 	fprintf (stderr,"** Invalid exponent - skipping frame **\n");
-	error = 1;
+	ac3_error = 1;
 }
 
