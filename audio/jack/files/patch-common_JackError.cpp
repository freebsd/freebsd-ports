--- common/JackError.cpp.orig	2022-01-15 18:51:10 UTC
+++ common/JackError.cpp
@@ -133,5 +133,5 @@ SERVER_EXPORT void silent_jack_error_callback(const ch
 SERVER_EXPORT void silent_jack_info_callback(const char *desc)
 {}
 
-SERVER_EXPORT void (*jack_error_callback)(const char *desc) = &default_jack_error_callback;
-SERVER_EXPORT void (*jack_info_callback)(const char *desc) = &default_jack_info_callback;
+LIB_EXPORT void (*jack_error_callback)(const char *desc) = &default_jack_error_callback;
+LIB_EXPORT void (*jack_info_callback)(const char *desc) = &default_jack_info_callback;
