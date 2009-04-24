--- plugins/symbol-db/symbol-db-engine-priv.h.orig	2009-04-15 19:40:20.000000000 -0400
+++ plugins/symbol-db/symbol-db-engine-priv.h	2009-04-15 19:40:34.000000000 -0400
@@ -47,7 +47,7 @@
 
 #define CTAGS_MARKER	"#_#\n"
 
-#define SHARED_MEMORY_PREFIX		"/dev/shm"
+#define SHARED_MEMORY_PREFIX		"/tmp"
 
 #define THREADS_MAX_CONCURRENT			2
 #define TRIGGER_SIGNALS_DELAY			100
