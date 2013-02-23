--- src/friends.cpp.orig	2011-03-21 08:16:40.000000000 +0100
+++ src/friends.cpp	2013-02-11 15:09:54.000000000 +0100
@@ -22,6 +22,13 @@
 #include <ctype.h>
 #ifdef  HAVE_ENDIAN_H
 #include <endian.h>
+#else
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
+#endif
 #endif
 #include <ucommon/export.h>
 #include <ccaudio2.h>
@@ -1186,16 +1193,16 @@
     if(!dp)
         return;
 
-    fsys::open(dir, dp, fsys::ACCESS_DIRECTORY);
+    dir.open(dp, fsys::RDONLY);
 
-    while(is(dir) && fsys::read(dir, filename, sizeof(filename)) > 0) {
+    while(is(dir) && dir.read(filename, sizeof(filename)) > 0) {
         if(filename[0] == '.')
             continue;
 
         snprintf(path, sizeof(path), "%s/%s", dp, filename);
         fsys::load(path);
     }
-    fsys::close(dir);
+    dir.close();
 #endif
 }
 
