--- main/source/pstdint.h.orig	2009-08-13 00:27:11.000000000 +0400
+++ main/source/pstdint.h	2009-08-13 00:27:29.000000000 +0400
@@ -199,7 +199,7 @@
  *  do nothing else.  On the Mac OS X version of gcc this is _STDINT_H_.
  */
 
-#if ((defined(__STDC__) && __STDC__ && __STDC_VERSION__ >= 199901L) || (defined (__WATCOMC__) && (defined (_STDINT_H_INCLUDED) || __WATCOMC__ >= 1250)) || (defined(__GNUC__) && (defined(_STDINT_H) || defined(_STDINT_H_)) )) && !defined (_PSTDINT_H_INCLUDED)
+#if !defined (_PSTDINT_H_INCLUDED)
 #include <stdint.h>
 #define _PSTDINT_H_INCLUDED
 # ifndef PRINTF_INT64_MODIFIER
