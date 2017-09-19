--- Alc/backends/jack.c.orig	2017-07-30 05:09:21 UTC
+++ Alc/backends/jack.c
@@ -35,11 +35,13 @@
 #include <jack/ringbuffer.h>
 
 
+extern void default_jack_error_callback(const char *msg) JACK_OPTIONAL_WEAK_EXPORT;
+
 static const ALCchar jackDevice[] = "JACK Default";
 
-
 #ifdef HAVE_DYNLOAD
 #define JACK_FUNCS(MAGIC)          \
+    MAGIC(default_jack_error_callback); \
     MAGIC(jack_client_open);       \
     MAGIC(jack_client_close);      \
     MAGIC(jack_client_name_size);  \
@@ -65,6 +67,7 @@ static void *jack_handle;
 JACK_FUNCS(MAKE_FUNC);
 #undef MAKE_FUNC
 
+#define default_jack_error_callback (*pdefault_jack_error_callback)
 #define jack_client_open pjack_client_open
 #define jack_client_close pjack_client_close
 #define jack_client_name_size pjack_client_name_size
@@ -567,7 +570,7 @@ static ALCboolean ALCjackBackendFactory_init(ALCjackBa
 
     jack_set_error_function(jack_msg_handler);
     client = jack_client_open("alsoft", ClientOptions, &status, NULL);
-    jack_set_error_function(NULL);
+    jack_set_error_function(default_jack_error_callback);
     if(client == NULL)
     {
         WARN("jack_client_open() failed, 0x%02x\n", status);
