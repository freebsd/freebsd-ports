--- sah_config.h.orig	2018-01-14 23:23:42 UTC
+++ sah_config.h
@@ -774,7 +774,7 @@
 #endif
 
 #if !defined(CUSTOM_STRING) && defined(COMPILER_STRING)
-#define CUSTOM_STRING PACKAGE_STRING" "SVN_REV" "COMPILER_STRING
+#define CUSTOM_STRING PACKAGE_STRING" " SVN_REV" " COMPILER_STRING
 #endif
 
 #include "std_fixes.h"
