--- unix/ibus/path_util.cc.orig	2013-03-29 13:33:43.000000000 +0900
+++ unix/ibus/path_util.cc	2013-04-27 15:42:28.000000000 +0900
@@ -30,7 +30,7 @@
 #include "unix/ibus/path_util.h"
 
 namespace {
-const char kInstalledDirectory[] = "/usr/share/ibus-mozc";
+const char kInstalledDirectory[] = LOCALBASE "/share/ibus-mozc/icons";
 }
 
 namespace mozc {
