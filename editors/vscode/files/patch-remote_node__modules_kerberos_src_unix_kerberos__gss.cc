--- remote/node_modules/kerberos/src/unix/kerberos_gss.cc.orig	2025-06-26 20:17:25 UTC
+++ remote/node_modules/kerberos/src/unix/kerberos_gss.cc
@@ -65,10 +65,17 @@ struct DLOpenHandle {
   DLOpenHandle& operator=(DLOpenHandle&) = delete;
 };
 
+#ifndef __FreeBSD__
 #define DYLIBS(V) \
     V(gssapi, "libgssapi_krb5.so.2") \
     V(krb5, "libkrb5.so.3") \
     V(comerr, "libcom_err.so.2")
+#else
+#define DYLIBS(V) \
+    V(gssapi, "libgssapi_krb5.so.2") \
+    V(krb5, "libkrb5.so.3") \
+    V(comerr, "libcom_err.so.3")
+#endif
 
 #define LIBRARY_HANDLE_GETTER(name, lib) \
     static const DLOpenHandle& name ## _handle() { \
