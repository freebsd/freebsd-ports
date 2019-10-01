--- src/linguist/shared/runqttool.cpp.orig	2019-02-14 20:37:05 UTC
+++ src/linguist/shared/runqttool.cpp
@@ -36,6 +36,7 @@
 
 #include <cstdlib>
 #include <iostream>
+#include <sys/wait.h>
 
 class FMT {
     Q_DECLARE_TR_FUNCTIONS(Linguist)
