Backport of upstream GameNetworkingSockets commit b81c19c31eb7 ("Fix endian handling
issues"), half of the fix for big-endian builds (issue #412).

--- 3rdparty/GameNetworkingSockets/src/public/minbase/minbase_endian.h.orig	2026-04-07 13:58:55 UTC
+++ 3rdparty/GameNetworkingSockets/src/public/minbase/minbase_endian.h
@@ -48,7 +48,7 @@ inline T DWordSwapC( T dw )
 	temp = *((uint32 *)&dw) 				>> 24;
 	temp |= ((*((uint32 *)&dw) & 0x00FF0000) >> 8);
 	temp |= ((*((uint32 *)&dw) & 0x0000FF00) << 8);
-	temp |= (*((uint32 *)&dw) << 24;
+	temp |= (*((uint32 *)&dw) << 24);
 #endif
    return *((T*)&temp);
 }
@@ -79,23 +79,22 @@ inline T QWordSwapC( T dw )
 	#define BigWord( val )		WordSwap( val )
 	#define BigInt32( val )		DWordSwap( val )
 	#define BigDWord( val )		DWordSwap( val )
-	#define BigQWord( val )		QWordSwap( val ) 
+	#define BigQWord( val )		QWordSwap( val )
 	#define BigFloat( val )		DWordSwap( val )
-	#define LittleInt16( val )	( val )
-	#define LittleWord( val )	( val )
-	#define LittleInt32( val )	( val )
-	#define LittleDWord( val )	( val )
-	#define LittleQWord( val )	( val )
-
+	#define LittleInt16( val )  ( (void)sizeof(char[sizeof(val)==2?1:-1]), (val) )
+	#define LittleWord( val )   ( (void)sizeof(char[sizeof(val)==2?1:-1]), (val) )
+	#define LittleInt32( val )  ( (void)sizeof(char[sizeof(val)==4?1:-1]), (val) )
+	#define LittleDWord( val )  ( (void)sizeof(char[sizeof(val)==4?1:-1]), (val) )
+	#define LittleQWord( val )  ( (void)sizeof(char[sizeof(val)==8?1:-1]), (val) )
 	#define LittleFloat( val )	( val )
 
 #elif defined(VALVE_BIG_ENDIAN)
 
-	#define BigInt16( val )		( val )
-	#define BigWord( val )		( val )
-	#define BigInt32( val )		( val )
-	#define BigDWord( val )		( val )
-	#define BigQWord( val )		( val )
+	#define BigInt16( val )  ( (void)sizeof(char[sizeof(val)==2?1:-1]), (val) )
+	#define BigWord( val )   ( (void)sizeof(char[sizeof(val)==2?1:-1]), (val) )
+	#define BigInt32( val )  ( (void)sizeof(char[sizeof(val)==4?1:-1]), (val) )
+	#define BigDWord( val )  ( (void)sizeof(char[sizeof(val)==4?1:-1]), (val) )
+	#define BigQWord( val )  ( (void)sizeof(char[sizeof(val)==8?1:-1]), (val) )
 	#define BigFloat( val )		( val )
 	#define LittleInt16( val )	WordSwap( val )
 	#define LittleWord( val )	WordSwap( val )
@@ -105,23 +104,7 @@ inline T QWordSwapC( T dw )
 	#define LittleFloat( val )	DWordSwap( val )
 
 #else
-
-	// @Note (toml 05-02-02): this technique expects the compiler to 
-	// optimize the expression and eliminate the other path. On any new 
-	// platform/compiler this should be tested.
-	inline short BigInt16( int16 val )		{ int test = 1; return ( *(char *)&test == 1 ) ? WordSwap( val )  : val; }
-	inline uint16 BigWord( uint16 val )		{ int test = 1; return ( *(char *)&test == 1 ) ? WordSwap( val )  : val; }
-	inline int32 BigInt32( int32 val )		{ int test = 1; return ( *(char *)&test == 1 ) ? DWordSwap( val ) : val; }
-	inline uint32 BigDWord( uint32 val )	{ int test = 1; return ( *(char *)&test == 1 ) ? DWordSwap( val ) : val; }
-	inline uint64 BigQWord( uint64 val )	{ int test = 1; return ( *(char *)&test == 1 ) ? QWordSwap( val ) : val; }
-	inline float BigFloat( float val )		{ int test = 1; return ( *(char *)&test == 1 ) ? DWordSwap( val ) : val; }
-	inline short LittleInt16( int16 val )	{ int test = 1; return ( *(char *)&test == 1 ) ? val : WordSwap( val ); }
-	inline uint16 LittleWord( uint16 val )	{ int test = 1; return ( *(char *)&test == 1 ) ? val : WordSwap( val ); }
-    inline long LittleInt32( int32 val )		{ int test = 1; return ( *(char *)&test == 1 ) ? val : DWordSwap( val ); }
-	inline uint32 LittleDWord( uint32 val )	{ int test = 1; return ( *(char *)&test == 1 ) ? val : DWordSwap( val ); }
-	inline uint64 LittleQWord( uint64 val )	{ int test = 1; return ( *(char *)&test == 1 ) ? val : QWordSwap( val ); }
-	inline float LittleFloat( float val )	{ int test = 1; return ( *(char *)&test == 1 ) ? val : DWordSwap( val ); }
-
+	#error "Must define either VALVE_LITTLE_ENDIAN or VALVE_BIG_ENDIAN"
 #endif
 
 #endif // #ifndef MINBASE_ENDIAN_H
