--- src/openrct2/core/String.cpp.orig	2024-03-06 10:18:48 UTC
+++ src/openrct2/core/String.cpp
@@ -15,7 +15,6 @@
 #include <stdexcept>
 #include <vector>
 #ifndef _WIN32
-#    include <alloca.h>
 #    include <unicode/ucnv.h>
 #    include <unicode/unistr.h>
 #    include <unicode/utypes.h>
