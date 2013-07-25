--- swreceiver/swdecoders/domino/dominodecoder.cpp.orig
+++ swreceiver/swdecoders/domino/dominodecoder.cpp
@@ -39,8 +39,12 @@
 #include	"gui.h"
 #include	"dominodecoder.h"
 #ifndef	__MINGW32__
+#ifdef __FreeBSD__
+#include	<stdlib.h>
+#else
 #include	"alloca.h"
 #endif
+#endif
 
 /*
  *	Standard Nasa coefficients for the viterbi decoder
