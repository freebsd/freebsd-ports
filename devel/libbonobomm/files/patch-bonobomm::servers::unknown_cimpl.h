--- bonobomm/servers/unknown_cimpl.h.orig	Tue Aug 17 17:56:16 2004
+++ bonobomm/servers/unknown_cimpl.h	Tue Aug 17 17:57:13 2004
@@ -75,7 +75,7 @@
   typedef BonoboObjectClass      BaseClassType;
 
 private:
-  friend class CppClassType;
+  friend class Unknown_CImpl_Class;
   static CppClassType unknown_cimpl_class_;
 
   Unknown_CImpl(const Unknown_CImpl&);
