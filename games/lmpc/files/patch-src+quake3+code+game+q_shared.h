--- src/quake3/code/game/q_shared.h.orig	Fri Mar  3 18:24:45 2006
+++ src/quake3/code/game/q_shared.h	Thu Mar 16 22:20:37 2006
@@ -122,9 +122,42 @@
 
 #define	QDECL
 
-short   ShortSwap (short l);
-int		LongSwap (int l);
-float	FloatSwap (const float *f);
+typedef unsigned char	byte;
+
+static short	ShortSwap (short l)
+{
+	byte b1, b2;
+
+	b1 = l & 255;
+	b2 = (l >> 8) & 255;
+	return ((b1 << 8) + b2);
+}
+
+static int	LongSwap (int l)
+{
+	byte b1, b2, b3, b4;
+
+	b1 = l & 255;
+	b2 = (l >> 8) & 255;
+	b3 = (l >> 16) & 255;
+	b4 = (l >> 24) & 255;
+	return (((int)b1 << 24) + ((int)b2 << 16) + ((int)b3 << 8) + b4);
+}
+
+typedef union {
+	float f;
+	unsigned int i;
+} _FloatByteUnion;
+
+static float	FloatSwap (const float *f)
+{
+	const _FloatByteUnion *in;
+	_FloatByteUnion out;
+
+	in = (_FloatByteUnion *)f;
+	out.i = LongSwap(in->i);
+	return (out.f);
+}
 
 /*======================= WIN32 DEFINES ================================= */
 
@@ -308,12 +341,14 @@
 
 /* bk010116 - omitted Q3STATIC (see Linux above), broken target */
 
-#if !idppc
+#include <machine/endian.h>
+
+#if BYTE_ORDER == LITTLE_ENDIAN
 static short BigShort( short l) { return ShortSwap(l); }
 #define LittleShort
-static int BigLong(int l) { LongSwap(l); }
+static int BigLong(int l) { return LongSwap(l); }
 #define LittleLong
-static float BigFloat(const float *l) { FloatSwap(l); }
+static float BigFloat(const float *l) { return FloatSwap(l); }
 #define LittleFloat
 #else
 #define BigShort
@@ -423,8 +458,6 @@
 #endif
 
 /*============================================================= */
-
-typedef unsigned char 		byte;
 
 typedef enum {qfalse, qtrue}	qboolean;
 
