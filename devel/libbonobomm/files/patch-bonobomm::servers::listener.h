--- bonobomm/servers/listener.h.orig	Tue Aug 17 17:56:23 2004
+++ bonobomm/servers/listener.h	Tue Aug 17 17:56:52 2004
@@ -69,7 +69,7 @@
   typedef BonoboListenerClass      BaseClassType;
 
 private:
-  friend class CppClassType;
+  friend class Listener_Class;
   static CppClassType listener_class_;
 
   Listener(const Listener&);
