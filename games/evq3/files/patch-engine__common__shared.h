--- ./engine/common/shared.h.orig	Wed Dec 20 20:29:46 2006
+++ ./engine/common/shared.h	Sat Dec 23 11:12:47 2006
@@ -365,7 +365,9 @@
 
 // bk010116 - omitted Q3STATIC (see Linux above), broken target
 
-#if !idppc
+#include <machine/endian.h>
+
+#if BYTE_ORDER == LITTLE_ENDIAN
 static short BigShort(short l)
 {
 	return ShortSwap(l);
@@ -384,7 +386,7 @@
 }
 
 #define LittleFloat
-#else
+#elif BYTE_ORDER == BIG_ENDIAN
 #define BigShort
 static short LittleShort(short l)
 {
@@ -402,6 +404,8 @@
 {
 	return FloatSwap(l);
 }
+#else
+#error Unknown endianess
 #endif
 
 #endif
@@ -542,7 +546,7 @@
 #endif
 
 // https://zerowing.idsoftware.com/bugzilla/show_bug.cgi?id=371 
-#if __linux__
+#if __unix__
 void Snd_Memset(void *dest, const int val, const size_t count);
 #else
 #define Snd_Memset memset
