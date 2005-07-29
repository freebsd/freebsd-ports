--- cppu/inc/cppu/macros.hxx.kan	Wed Jul 24 23:28:55 2002
+++ cppu/inc/cppu/macros.hxx	Wed Jul 24 23:29:45 2002
@@ -76,7 +76,7 @@
     the struct inherits from a base struct the first member is no double or [unsigned] long long.
     @internal
 */
-#if defined(__GNUC__) && defined(LINUX) && (defined(INTEL) || defined(POWERPC)) && (__GNUC__ == 3)
+#if defined(__GNUC__) && (defined(LINUX) || defined(FREEBSD)) && (defined(INTEL) || defined(POWERPC)) && (__GNUC__ == 3)
 #define CPPU_GCC3_ALIGN( base_struct ) __attribute__ ((aligned (__alignof__ (base_struct))))
 #else
 #define CPPU_GCC3_ALIGN( base_struct )
