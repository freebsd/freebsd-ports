--- common/JackError.h.orig	2022-01-15 18:51:23 UTC
+++ common/JackError.h
@@ -35,8 +35,8 @@ extern "C"
     SERVER_EXPORT void jack_info(const char *fmt, ...);
     SERVER_EXPORT void jack_log(const char *fmt, ...);
 
-    SERVER_EXPORT extern void (*jack_error_callback)(const char *desc);
-    SERVER_EXPORT extern void (*jack_info_callback)(const char *desc);
+    LIB_EXPORT extern void (*jack_error_callback)(const char *desc);
+    LIB_EXPORT extern void (*jack_info_callback)(const char *desc);
 
     SERVER_EXPORT extern void default_jack_error_callback(const char *desc);
     SERVER_EXPORT extern void default_jack_info_callback(const char *desc);
