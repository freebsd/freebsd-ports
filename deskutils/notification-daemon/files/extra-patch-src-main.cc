--- src/main.cc.orig	Wed Aug 10 10:43:56 2005
+++ src/main.cc	Wed Aug 31 23:25:36 2005
@@ -622,7 +622,6 @@
 int
 main(int argc, char **argv)
 {
-    std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
     DBusError error;
 
     dbus_error_init(&error);
