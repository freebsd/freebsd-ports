--- ../../mfbt/Types.h.orig	2013-10-29 20:40:19 UTC
+++ ../../mfbt/Types.h
@@ -138,7 +138,9 @@
  */
 #if defined(__GNUC__) && defined(__cplusplus) && \
   !defined(__GXX_EXPERIMENTAL_CXX0X__) && __cplusplus < 201103L
+# ifndef decltype
 #  define decltype __typeof__
+# endif
 #endif
 
 #endif  /* mozilla_Types_h_ */
