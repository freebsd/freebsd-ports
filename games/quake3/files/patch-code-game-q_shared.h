--- code/game/q_shared.h.orig	Thu May 25 13:26:31 2006
+++ code/game/q_shared.h	Thu May 25 13:26:58 2006
@@ -150,12 +150,14 @@
 
 #define ID_INLINE __inline 
 
+#if 0
 static ID_INLINE short BigShort( short l) { return ShortSwap(l); }
 #define LittleShort
 static ID_INLINE int BigLong(int l) { LongSwap(l); }
 #define LittleLong
 static ID_INLINE float BigFloat(const float *l) { FloatSwap(l); }
 #define LittleFloat
+#endif
 
 #define	PATH_SEP '\\'
 
@@ -206,12 +208,14 @@
     return fi;
 }
 
+#if 0
 #define BigShort
 static inline short LittleShort(short l) { return ShortSwap(l); }
 #define BigLong
 static inline int LittleLong (int l) { return LongSwap(l); }
 #define BigFloat
 static inline float LittleFloat (const float l) { return FloatSwap(&l); }
+#endif
 
 #endif
 
@@ -229,12 +233,14 @@
 
 void Sys_PumpEvents( void );
 
+#if 0
 #define BigShort
 static inline short LittleShort(short l) { return ShortSwap(l); }
 #define BigLong
 static inline int LittleLong (int l) { return LongSwap(l); }
 #define BigFloat
 static inline float LittleFloat (const float l) { return FloatSwap(&l); }
+#endif
 
 #endif
 
@@ -268,6 +274,7 @@
 #define	BOTLIB_HARD_LINKED
 #endif
 
+#if 0
 #if !idppc
 inline static short BigShort( short l) { return ShortSwap(l); }
 #define LittleShort
@@ -283,6 +290,7 @@
 #define BigFloat
 inline static float LittleFloat (const float *l) { return FloatSwap(l); }
 #endif
+#endif
 
 #endif
 
@@ -302,10 +310,18 @@
 #define CPUSTRING       "freebsd-other"
 #endif
 
+#include <machine/param.h>
+#if __FreeBSD_version < 500000
+#include <inttypes.h>
+#else
+#include <stdint.h>
+#endif
+
 #define	PATH_SEP '/'
 
 // bk010116 - omitted Q3STATIC (see Linux above), broken target
 
+#if 0
 #if !idppc
 static short BigShort( short l) { return ShortSwap(l); }
 #define LittleShort
@@ -321,6 +337,7 @@
 #define BigFloat
 static float LittleFloat (const float *l) { return FloatSwap(l); }
 #endif
+#endif
 
 #endif
 
@@ -452,13 +469,9 @@
 void *Hunk_Alloc( int size, ha_pref preference );
 #endif
 
-#ifdef __linux__
 // https://zerowing.idsoftware.com/bugzilla/show_bug.cgi?id=371
 // custom Snd_Memset implementation for glibc memset bug workaround
 void Snd_Memset (void* dest, const int val, const size_t count);
-#else
-#define Snd_Memset Com_Memset
-#endif
 
 #if !( defined __VECTORC )
 void Com_Memset (void* dest, const int val, const size_t count);
@@ -888,18 +901,18 @@
 } qint64;
 
 //=============================================
-/*
-short	BigShort(short l);
-short	LittleShort(short l);
-int		BigLong (int l);
-int		LittleLong (int l);
-qint64  BigLong64 (qint64 l);
-qint64  LittleLong64 (qint64 l);
-float	BigFloat (const float *l);
-float	LittleFloat (const float *l);
+
+int16_t	BigShort(int16_t l);
+int16_t	LittleShort(int16_t l);
+int32_t	BigLong (int32_t l);
+int32_t	LittleLong (int32_t l);
+qint64		BigLong64 (qint64 l);
+qint64		LittleLong64 (qint64 l);
+float	BigFloat (float l);
+float	LittleFloat (float l);
 
 void	Swap_Init (void);
-*/
+
 char	* QDECL va(char *format, ...);
 
 //=============================================
