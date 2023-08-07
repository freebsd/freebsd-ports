--- remote/node_modules/kerberos/src/kerberos_common.h.orig	2023-08-06 02:46:04 UTC
+++ remote/node_modules/kerberos/src/kerberos_common.h
@@ -1,7 +1,7 @@
 #ifndef KERBEROS_COMMON_H
 #define KERBEROS_COMMON_H
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include "unix/kerberos_gss.h"
 
 namespace node_kerberos {
