--- src/shairport.h.orig	2011-08-20 23:58:11 UTC
+++ src/shairport.h
@@ -11,14 +11,22 @@
 #include <regex.h>
 #include <sys/types.h>
 #include <regex.h>
+#include "ao.h"
 
 
 #define HWID_SIZE 6
 #define SHAIRPORT_LOG 1
-#define LOG_INFO     1
-#define LOG_DEBUG    5
-#define LOG_DEBUG_V  6
-#define LOG_DEBUG_VV 7
+
+#ifndef LOG_INFO
+#define LOG_INFO     5
+#endif
+
+#ifndef LOG_DEBUG
+#define LOG_DEBUG    6
+#endif
+
+#define LOG_DEBUG_V  7
+#define LOG_DEBUG_VV 8
 
 struct shairbuffer
 {
@@ -58,13 +66,21 @@ extern "C"
 {
 #endif /* __cplusplus */
 
+struct printfPtr
+{
+  int (*extprintf)(const char* msg, size_t msgSize);
+};
+
 int shairport_main(int argc, char **argv);
 void shairport_exit(void);
 int shairport_loop(void);
 int shairport_is_running(void);
+void shairport_set_ao(struct AudioOutput *ao);
+void shairport_set_printf(struct printfPtr *funcPtr);
 
 #ifdef __cplusplus
 }
 #endif /* __cplusplus */
 
 #endif
+
