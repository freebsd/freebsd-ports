--- src/deutex.h.orig	1999-12-30 23:20:22 UTC
+++ src/deutex.h
@@ -31,23 +31,13 @@ Place, Suite 330, Boston, MA 02111-1307,
 #define DeuSF   for DOS .EXE  Unix Linux OS/2
 *********************************************/
 
-#if defined (__alpha)        /*__ALPHA__ for Alpha processor?*/
-/*long = int64 on a 64bit processor*/
-typedef char           Int8;
-typedef short          Int16;
-typedef int            Int32;
-typedef unsigned char  UInt8;
-typedef unsigned short UInt16;
-typedef unsigned int   UInt32;
-#else
-/*long = Int32 on a 32 bit processor*/
-typedef char           Int8;
-typedef short          Int16;
-typedef long           Int32;
-typedef unsigned char  UInt8;
-typedef unsigned short UInt16;
-typedef unsigned long  UInt32;
-#endif
+#include <stdint.h>
+typedef int8_t   Int8;
+typedef int16_t  Int16;
+typedef int32_t  Int32;
+typedef uint8_t  UInt8;
+typedef uint16_t UInt16;
+typedef uint32_t UInt32;
 
 #if defined DeuTex
 #if defined DeuSF
