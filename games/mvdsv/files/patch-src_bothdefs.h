--- src/bothdefs.h.orig	2011-10-06 07:24:17 UTC
+++ src/bothdefs.h
@@ -174,21 +174,21 @@ float	FloatSwap (float f);
 }  /* extern "C" */
 #endif
 
-#ifdef __BIG_ENDIAN__Q__
+#if _BYTE_ORDER == _BIG_ENDIAN
 #define BigShort(x)		(x)
 #define BigLong(x)		(x)
 #define BigFloat(x)		(x)
 #define LittleShort(x)	ShortSwap(x)
 #define LittleLong(x)	LongSwap(x)
 #define LittleFloat(x)	FloatSwap(x)
-#elif defined(__LITTLE_ENDIAN__Q__)
+#elif _BYTE_ORDER == _LITTLE_ENDIAN
 #define BigShort(x)		ShortSwap(x)
 #define BigLong(x)		LongSwap(x)
 #define BigFloat(x)		FloatSwap(x)
 #define LittleShort(x)	(x)
 #define LittleLong(x)	(x)
 #define LittleFloat(x)	(x)
-#elif defined(__PDP_ENDIAN__Q__)
+#elif _BYTE_ORDER == _PDP_ENDIAN
 int		LongSwapPDP2Big (int l);
 int		LongSwapPDP2Lit (int l);
 float	FloatSwapPDP2Big (float f);
