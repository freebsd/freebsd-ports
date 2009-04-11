--- Source/NativeTypes.h.orig	2009-04-03 18:06:31.690567244 +0000
+++ Source/NativeTypes.h	2009-04-03 18:10:54.166588917 +0000
@@ -5,7 +5,7 @@
 		#include <stdint.h>
 	#endif
 	
-	#if !defined(_STDINT_H) && !defined(_SN_STDINT_H)
+	#if !defined(_STDINT_H) && !defined(_SN_STDINT_H) && !defined(_SYS_STDINT_H_)
 		typedef unsigned char         uint8_t;
 		typedef unsigned short        uint16_t;
 		typedef unsigned int          uint32_t;
