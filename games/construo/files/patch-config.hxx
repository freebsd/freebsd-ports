--- config.hxx.orig	2003-01-11 18:37:26.000000000 +0300
+++ config.hxx	2013-09-13 20:20:18.512226481 +0400
@@ -21,6 +21,7 @@
 #define CONFIG_HH
 
 #include <string>
+#include <cstdlib> // for getenv()
 
 class Config
 {
