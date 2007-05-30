--- src/paman.cc.orig	Wed May 30 16:58:45 2007
+++ src/paman.cc	Wed May 30 16:59:37 2007
@@ -16,7 +16,9 @@
 struct pa_context *context = NULL;
 struct pa_mainloop_api *mainloop_api = NULL;
 
-extern "C" static void context_state_callback(struct pa_context *c, void *userdata);
+extern "C"
+{
+static void context_state_callback(struct pa_context *c, void *userdata);
 
 #define WINDOW_TITLE "Polypaudio Manager"
 
@@ -66,6 +68,7 @@
     }
             
     killConnection();
+}
 }
 
 void createConnection() {
