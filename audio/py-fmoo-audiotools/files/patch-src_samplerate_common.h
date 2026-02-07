--- src/samplerate/common.h.orig	2014-12-31 18:30:53 UTC
+++ src/samplerate/common.h
@@ -25,13 +25,7 @@
 #ifndef COMMON_H_INCLUDED
 #define COMMON_H_INCLUDED
 
-#ifdef HAVE_STDINT_H
 #include <stdint.h>
-#elif (SIZEOF_INT == 4)
-typedef	int		int32_t ;
-#elif (SIZEOF_LONG == 4)
-typedef	long	int32_t ;
-#endif
 
 #define	SRC_MAX_RATIO			256
 #define	SRC_MAX_RATIO_STR		"256"
