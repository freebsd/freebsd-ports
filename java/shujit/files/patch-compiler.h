
$FreeBSD$

--- compiler.h	2002/04/26 17:13:45	1.1
+++ compiler.h	2002/04/26 17:17:19
@@ -61,13 +61,13 @@
 // Additional type definition
 
 #if !(defined(_ILP32) || defined(_LP64))
-#  ifndef _UINT16_T
+#  if !defined(_UINT16_T) && !defined(_UINT16_T_DECLARED)
 #    define _UINT16_T
 typedef unsigned short uint16_t;
 #    endif	// _UINT16_T
 
 #  ifndef __BIT_TYPES_DEFINED__
-#    ifndef _INT16_T
+#    if !defined(_INT16_T) && !defined(_INT16_T_DECLARED)
 #      define _INT16_T
 typedef short int16_t;
 #    endif	// _INT16_T
