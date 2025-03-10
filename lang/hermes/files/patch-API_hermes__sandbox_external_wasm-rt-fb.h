--- API/hermes_sandbox/external/wasm-rt-fb.h.orig	2024-08-17 05:54:34 UTC
+++ API/hermes_sandbox/external/wasm-rt-fb.h
@@ -21,7 +21,7 @@ typedef atomic_uint seed_t;
 #include <sys/random.h>
 #include <sys/syscall.h>
 #include <unistd.h>
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #include <time.h>
 #include <unistd.h>
 #endif
