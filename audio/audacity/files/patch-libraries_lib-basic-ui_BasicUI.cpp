--- libraries/lib-basic-ui/BasicUI.cpp.orig	2022-09-28 03:57:45 UTC
+++ libraries/lib-basic-ui/BasicUI.cpp
@@ -29,6 +29,7 @@ Paul Licameli
 
 #include <string>
 
+extern char** environ;
 namespace
 {
 
