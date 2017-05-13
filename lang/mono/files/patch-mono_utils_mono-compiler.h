--- mono/utils/mono-compiler.h.orig	2017-05-01 17:08:15 UTC
+++ mono/utils/mono-compiler.h
@@ -54,13 +54,13 @@
    For now we will disable this. */
 #define MONO_TLS_FAST
 #else
-#define MONO_TLS_FAST __attribute__((tls_model("local-dynamic")))
+#define MONO_TLS_FAST __attribute__((tls_model("local-dynamic"))) __attribute__((visability("hidden")))
 #endif
 #endif
 
 #else
 
-#define MONO_TLS_FAST __attribute__((tls_model("local-exec")))
+#define MONO_TLS_FAST __attribute__((tls_model("local-exec"))) __attribute__((visability("hidden")))
 
 #endif
 
