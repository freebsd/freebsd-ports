--- ./code/game/q_shared.c.orig	Wed May 31 20:52:06 2006
+++ ./code/game/q_shared.c	Wed May 31 20:54:26 2006
@@ -38,14 +38,21 @@
 COM_StripExtension
 ============
 */
-void COM_StripExtension( const char *in, char *out ) {
-	while ( *in && *in != '.' ) {
-		*out++ = *in++;
+void COM_StripExtension( const char *in, char *out, int destsize ) {
+	int	length;
+
+	Q_strncpyz(out, in, destsize);
+
+	length = strlen(out)-1;
+	while (length > 0 && out[length] != '.') {
+		length--;
+		if (out[length] == '/')
+			return;		// no extension
 	}
-	*out = 0;
+	if (length)
+		out[length] = 0;
 }
 
-
 /*
 ==================
 COM_DefaultExtension
@@ -79,29 +86,28 @@
 
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
+static int32_t	(*_BigLong) (int32_t l);
+static int32_t	(*_LittleLong) (int32_t l);
 static qint64	(*_BigLong64) (qint64 l);
 static qint64	(*_LittleLong64) (qint64 l);
 static float	(*_BigFloat) (const float *l);
 static float	(*_LittleFloat) (const float *l);
 
-short	BigShort(short l){return _BigShort(l);}
-short	LittleShort(short l) {return _LittleShort(l);}
-int		BigLong (int l) {return _BigLong(l);}
-int		LittleLong (int l) {return _LittleLong(l);}
+int16_t	BigShort(int16_t l){return _BigShort(l);}
+int16_t	LittleShort(int16_t l) {return _LittleShort(l);}
+int32_t	BigLong (int32_t l) {return _BigLong(l);}
+int32_t	LittleLong (int32_t l) {return _LittleLong(l);}
 qint64 	BigLong64 (qint64 l) {return _BigLong64(l);}
 qint64 	LittleLong64 (qint64 l) {return _LittleLong64(l);}
-float	BigFloat (const float *l) {return _BigFloat(l);}
-float	LittleFloat (const float *l) {return _LittleFloat(l);}
-*/
+float	BigFloat (float l) {return _BigFloat(&l);}
+float	LittleFloat (float l) {return _LittleFloat(&l);}
 
-short   ShortSwap (short l)
+int16_t	ShortSwap (int16_t l)
 {
 	byte    b1,b2;
 
@@ -111,12 +117,12 @@
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
 
@@ -128,7 +134,7 @@
 	return ((int)b1<<24) + ((int)b2<<16) + ((int)b3<<8) + b4;
 }
 
-int	LongNoSwap (int l)
+int32_t	LongNoSwap (int32_t l)
 {
 	return l;
 }
@@ -179,7 +185,7 @@
 Swap_Init
 ================
 */
-/*
+
 void Swap_Init (void)
 {
 	byte	swaptest[2] = {1,0};
@@ -209,7 +215,7 @@
 	}
 
 }
-*/
+
 
 /*
 ============================================================================
