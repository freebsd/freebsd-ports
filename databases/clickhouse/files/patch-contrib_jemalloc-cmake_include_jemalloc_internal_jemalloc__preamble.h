--- contrib/jemalloc-cmake/include/jemalloc/internal/jemalloc_preamble.h.orig	2026-11-10 11:06:33 UTC
+++ contrib/jemalloc-cmake/include/jemalloc/internal/jemalloc_preamble.h
@@ -65,7 +65,7 @@ static const bool have_dss =
 #endif
     ;
 static const bool have_dss =
-#ifdef JEMALLOC_DSS
+#if 0
     true
 #else
     false
