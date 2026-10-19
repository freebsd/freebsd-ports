--- src/unix/ibus/ibus_wrapper.cc.orig	2026-10-18 10:27:15 UTC
+++ src/unix/ibus/ibus_wrapper.cc
@@ -36,8 +36,8 @@ static_assert(std::is_same<gint, int>::value, "gint mu
 #include "absl/strings/string_view.h"
 
 static_assert(std::is_same<gint, int>::value, "gint must be int.");
-static_assert(std::is_same<guint, uint>::value, "guint must be uint.");
-static_assert(std::is_same<gulong, ulong>::value, "guint must be ulong.");
+static_assert(std::is_same<guint, unsigned int>::value, "guint must be unsigned int.");
+static_assert(std::is_same<gulong, unsigned long>::value, "gulong must be unsigned long.");
 static_assert(std::is_same<gchar, char>::value, "gchar must be char.");
 static_assert(std::is_same<gboolean, int>::value, "gboolean must be int.");
 static_assert(std::is_same<gpointer, void*>::value, "gpointer must be void*.");
@@ -78,7 +78,7 @@ void GobjectWrapper::RefSink() {
   g_object_ref_sink(obj);
 }
 
-void GobjectWrapper::SignalHandlerDisconnect(ulong id) {
+void GobjectWrapper::SignalHandlerDisconnect(unsigned long id) {
   GObject* obj = GetGobject();
   if (obj == nullptr) {
     return;
