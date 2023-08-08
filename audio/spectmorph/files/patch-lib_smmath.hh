- fix compilation failure on 14: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
- see https://github.com/swesterfeld/spectmorph/issues/23

--- lib/smmath.hh.orig	2023-07-12 03:47:47 UTC
+++ lib/smmath.hh
@@ -431,7 +431,7 @@ double db_from_factor (double factor, double min_dB);
 
 #if defined (__i386__) && defined (__GNUC__)
 static inline int G_GNUC_CONST
-sm_ftoi (register float f)
+sm_ftoi (float f)
 {
   int r;
 
@@ -441,7 +441,7 @@ sm_ftoi (register float f)
   return r;
 }
 static inline int G_GNUC_CONST
-sm_dtoi (register double f)
+sm_dtoi (double f)
 {
   int r;
 
