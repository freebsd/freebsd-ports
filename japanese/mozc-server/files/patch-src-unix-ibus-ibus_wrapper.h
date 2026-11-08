--- src/unix/ibus/ibus_wrapper.h.orig	2026-10-18 10:26:37 UTC
+++ src/unix/ibus/ibus_wrapper.h
@@ -65,7 +65,7 @@ class GobjectWrapper {
   }
 
   template <typename C, typename D>
-  ulong SignalConnect(absl::string_view signal, C callback, D* user_data) {
+  unsigned long SignalConnect(absl::string_view signal, C callback, D* user_data) {
     GObject* obj = GetGobject();
     if (obj == nullptr) {
       return 0;
@@ -75,7 +75,7 @@ class GobjectWrapper {
                             reinterpret_cast<gpointer>(user_data));
   }
 
-  void SignalHandlerDisconnect(ulong id);
+  void SignalHandlerDisconnect(unsigned long id);
 };
 
 class GsettingsWrapper : public GobjectWrapper {
