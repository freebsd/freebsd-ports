--- swreceiver/swdecoders/mfskdecoder/mfskdecoder.cpp.orig
+++ swreceiver/swdecoders/mfskdecoder/mfskdecoder.cpp
@@ -32,8 +32,12 @@
 #include	"mfskdecoder.h"
 #include	"oscillator.h"
 #ifndef	__MINGW32__
+#ifdef __FreeBSD__
+#include	<stdlib.h>
+#else
 #include	"alloca.h"
 #endif
+#endif
 
 #define	BitIsContained(pat, bit) ((pat) & (1 << (mfskNumBits - (bit + 1))))
 /*
