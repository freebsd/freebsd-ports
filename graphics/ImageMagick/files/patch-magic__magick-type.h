--- magick/magick-type.h.orig	2014-08-08 16:27:39.000000000 +0200
+++ magick/magick-type.h	2014-12-19 17:31:35.000000000 +0100
@@ -45,12 +45,16 @@ extern "C" {
 */
 #if MAGICKCORE_SIZEOF_FLOAT_T == 0
 typedef float MagickRealType;
+#define fabs fabsf
 #elif (MAGICKCORE_SIZEOF_FLOAT_T == MAGICKCORE_SIZEOF_FLOAT)
 typedef float MagickRealType;
+#define fabs fabsf
 #elif (MAGICKCORE_SIZEOF_FLOAT_T == MAGICKCORE_SIZEOF_DOUBLE)
 typedef double MagickRealType;
+#define fabs fabs
 #elif (MAGICKCORE_SIZEOF_FLOAT_T == MAGICKCORE_SIZEOF_LONG_DOUBLE)
 typedef long double MagickRealType;
+#define fabs fabsl
 #else
 # error Your float_t type is neither a float, nor a double, nor a long double
 #endif
@@ -74,12 +78,16 @@ typedef unsigned char Quantum;
 */
 #if MAGICKCORE_SIZEOF_FLOAT_T == 0
 typedef float MagickRealType;
+#define fabs fabsf
 #elif (MAGICKCORE_SIZEOF_FLOAT_T == MAGICKCORE_SIZEOF_FLOAT)
 typedef float MagickRealType;
+#define fabs fabsf
 #elif (MAGICKCORE_SIZEOF_FLOAT_T == MAGICKCORE_SIZEOF_DOUBLE)
 typedef double MagickRealType;
+#define fabs fabs
 #elif (MAGICKCORE_SIZEOF_FLOAT_T == MAGICKCORE_SIZEOF_LONG_DOUBLE)
 typedef long double MagickRealType;
+#define fabs fabsl
 #else
 # error Your float_t type is neither a float, nor a double, nor a long double
 #endif
@@ -103,10 +111,13 @@ typedef unsigned short Quantum;
 */
 #if MAGICKCORE_SIZEOF_DOUBLE_T == 0
 typedef double MagickRealType;
+#define fabs fabs
 #elif (MAGICKCORE_SIZEOF_DOUBLE_T == MAGICKCORE_SIZEOF_DOUBLE)
 typedef double MagickRealType;
+#define fabs fabs
 #elif (MAGICKCORE_SIZEOF_DOUBLE_T == MAGICKCORE_SIZEOF_LONG_DOUBLE)
 typedef long double MagickRealType;
+#define fabs fabsl
 #else
 # error Your double_t type is neither a float, nor a double, nor a long double
 #endif
@@ -131,6 +142,7 @@ typedef long double SignedQuantum;
 typedef long double Quantum;
 #define QuantumRange  18446744073709551615.0
 #define QuantumFormat  "%g"
+#define fabs fabsl
 #else
 #if !defined(_CH_)
 # error "MAGICKCORE_QUANTUM_DEPTH must be one of 8, 16, 32, or 64"
