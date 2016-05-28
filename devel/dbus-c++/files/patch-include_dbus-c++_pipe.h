--- include/dbus-c++/pipe.h.orig	2016-05-28 13:11:06 UTC
+++ include/dbus-c++/pipe.h
@@ -30,6 +30,8 @@
 /* STD */
 #include <cstdlib>
 
+#include <sys/types.h>
+
 namespace DBus
 {
 
