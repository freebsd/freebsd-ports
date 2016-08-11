--- plugins/CuePack/CuePack.h.orig	2012-06-28 14:58:11 UTC
+++ plugins/CuePack/CuePack.h
@@ -1,7 +1,6 @@
 #include <plugin/IMediaPack.h>
 extern "C" {
-#include <libcue-1.4/libcue/libcue.h>
-#include <libcue-1.4/libcue/cd.h>
+#include <libcue.h>
 }
 using namespace std;
 using namespace mous;
