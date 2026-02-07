--- sources/utils/converter/opcode/Ice/IceTypes.h.orig	2018-09-02 12:42:44 UTC
+++ sources/utils/converter/opcode/Ice/IceTypes.h
@@ -47,10 +47,10 @@
 	typedef unsigned char		ubyte;		//!< sizeof(ubyte)	must be 1
 	typedef signed short		sword;		//!< sizeof(sword)	must be 2
 	typedef unsigned short		uword;		//!< sizeof(uword)	must be 2
-	typedef signed int			sdword;		//!< sizeof(sdword)	must be 4
-	typedef unsigned int		udword;		//!< sizeof(udword)	must be 4
-	typedef signed __int64		sqword;		//!< sizeof(sqword)	must be 8
-	typedef unsigned __int64	uqword;		//!< sizeof(uqword)	must be 8
+	typedef int32_t			sdword;		//!< sizeof(sdword)	must be 4
+	typedef uint32_t		udword;		//!< sizeof(udword)	must be 4
+	typedef int64_t			sqword;		//!< sizeof(sqword)	must be 8
+	typedef uint64_t		uqword;		//!< sizeof(uqword)	must be 8
 	typedef float				float32;	//!< sizeof(float32)	must be 4
 	typedef double				float64;	//!< sizeof(float64)	must be 4
 
