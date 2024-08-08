--- zeno/src/extra/GlobalComm.cpp.orig	2024-04-21 08:28:40 UTC
+++ zeno/src/extra/GlobalComm.cpp
@@ -10,6 +10,7 @@
 #include <unordered_set>
 #include <zeno/types/MaterialObject.h>
 #include <zeno/types/CameraObject.h>
+#include <thread>
 #ifdef __linux__
     #include<unistd.h>
     #include <sys/statfs.h>
