--- src/c4/yml/common.hpp.orig	2025-04-10 19:51:13 UTC
+++ src/c4/yml/common.hpp
@@ -9,7 +9,7 @@
 #include <c4/dump.hpp>
 #include <c4/yml/export.hpp>
 
-#if defined(C4_MSVC) || defined(C4_MINGW)
+#if defined(C4_MSVC) || defined(C4_MINGW) || defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <alloca.h>
