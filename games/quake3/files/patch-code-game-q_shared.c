--- code/game/q_shared.c.orig	Thu May 25 13:42:26 2006
+++ code/game/q_shared.c	Thu May 25 13:44:30 2006
@@ -99,29 +99,29 @@
 
 ============================================================================
 */
-/*
+
 // can't just use function pointers, or dll linkage can
 // mess up when qcommon is included in multiple places
-static short	(*_BigShort) (short l);
-static short	(*_LittleShort) (short l);
-static int		(*_BigLong) (int l);
-static int		(*_LittleLong) (int l);
+static int16_t	(*_BigShort) (int16_t l);
+static int16_t	(*_LittleShort) (int16_t l);
+static int32_t		(*_BigLong) (int32_t l);
+static int32_t		(*_LittleLong) (int32_t l);
 static qint64	(*_BigLong64) (qint64 l);
 static qint64	(*_LittleLong64) (qint64 l);
 static float	(*_BigFloat) (const float *l);
 static float	(*_LittleFloat) (const float *l);
 
-short	BigShort(short l){return _BigShort(l);}
-short	LittleShort(short l) {return _LittleShort(l);}
-int		BigLong (int l) {return _BigLong(l);}
-int		LittleLong (int l) {return _LittleLong(l);}
-qint64 	BigLong64 (qint64 l) {return _BigLong64(l);}
-qint64 	LittleLong64 (qint64 l) {return _LittleLong64(l);}
-float	BigFloat (const float *l) {return _BigFloat(l);}
-float	LittleFloat (const float *l) {return _LittleFloat(l);}
-*/
+int16_t	BigShort(int16_t l){return _BigShort(l);}
+int16_t	LittleShort(int16_t l) {return _LittleShort(l);}
+int32_t	BigLong (int32_t l) {return _BigLong(l);}
+int32_t	LittleLong (int32_t l) {return _LittleLong(l);}
+qint64	BigLong64 (qint64 l) {return _BigLong64(l);}
+qint64	LittleLong64 (qint64 l) {return _LittleLong64(l);}
+float	BigFloat (float l) {return _BigFloat(&l);}
+float	LittleFloat (float l) {return _LittleFloat(&l);}
 
-short   ShortSwap (short l)
+
+int16_t	ShortSwap (int16_t l)
 {
 	byte    b1,b2;
 
@@ -131,12 +131,12 @@
 	return (b1<<8) + b2;
 }
 
-short	ShortNoSwap (short l)
+int16_t	ShortNoSwap (int16_t l)
 {
 	return l;
 }
 
-int    LongSwap (int l)
+int32_t	LongSwap (int32_t l)
 {
 	byte    b1,b2,b3,b4;
 
@@ -145,15 +145,15 @@
 	b3 = (l>>16)&255;
 	b4 = (l>>24)&255;
 
-	return ((int)b1<<24) + ((int)b2<<16) + ((int)b3<<8) + b4;
+	return ((int32_t)b1<<24) + ((int32_t)b2<<16) + ((int32_t)b3<<8) + b4;
 }
 
-int	LongNoSwap (int l)
+int32_t	LongNoSwap (int32_t l)
 {
 	return l;
 }
 
-qint64 Long64Swap (qint64 ll)
+qint64	Long64Swap (qint64 ll)
 {
 	qint64	result;
 
@@ -199,7 +199,7 @@
 Swap_Init
 ================
 */
-/*
+
 void Swap_Init (void)
 {
 	byte	swaptest[2] = {1,0};
@@ -229,7 +229,7 @@
 	}
 
 }
-*/
+
 
 /*
 ============================================================================
