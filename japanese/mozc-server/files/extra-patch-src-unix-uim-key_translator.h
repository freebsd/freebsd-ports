--- src/unix/uim/key_translator.h.orig	2015-07-13 05:02:13.505621000 +0900
+++ src/unix/uim/key_translator.h	2015-07-13 05:02:22.697125000 +0900
@@ -38,7 +38,7 @@
 using __gnu_cxx::hash_map;
 
 #include "base/port.h"
-#include "session/commands.pb.h"
+#include "protocol/commands.pb.h"
 
 namespace mozc {
 namespace uim {
