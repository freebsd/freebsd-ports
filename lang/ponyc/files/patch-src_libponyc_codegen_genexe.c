--- src/libponyc/codegen/genexe.c.orig	2018-10-13 12:30:06 UTC
+++ src/libponyc/codegen/genexe.c
@@ -347,8 +347,7 @@ static bool link_exe(compile_t* c, ast_t* program,
     "";
 #endif
   const char* lexecinfo =
-#if (defined(PLATFORM_IS_LINUX) && !defined(__GLIBC__)) || \
-    (defined(PLATFORM_IS_BSD) && defined(DEBUG))
+#if (defined(PLATFORM_IS_LINUX) && !defined(__GLIBC__)) || defined(PLATFORM_IS_BSD)
    "-lexecinfo";
 #else
     "";
