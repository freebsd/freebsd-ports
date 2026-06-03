--- binutils-gdb/include/diagnostics.h.orig	2024-11-20 17:30:17 UTC
+++ binutils-gdb/include/diagnostics.h
@@ -76,11 +76,6 @@
 # define DIAGNOSTIC_ERROR_SWITCH \
   DIAGNOSTIC_ERROR ("-Wswitch")
 
-# if __has_warning ("-Wenum-constexpr-conversion")
-#  define DIAGNOSTIC_IGNORE_ENUM_CONSTEXPR_CONVERSION \
-   DIAGNOSTIC_IGNORE ("-Wenum-constexpr-conversion")
-# endif
-
 #elif defined (__GNUC__) /* GCC */
 
 # define DIAGNOSTIC_IGNORE_DEPRECATED_DECLARATIONS \
@@ -157,10 +152,6 @@
 
 #ifndef DIAGNOSTIC_ERROR_SWITCH
 # define DIAGNOSTIC_ERROR_SWITCH
-#endif
-
-#ifndef DIAGNOSTIC_IGNORE_ENUM_CONSTEXPR_CONVERSION
-# define DIAGNOSTIC_IGNORE_ENUM_CONSTEXPR_CONVERSION
 #endif
 
 #endif /* DIAGNOSTICS_H */
