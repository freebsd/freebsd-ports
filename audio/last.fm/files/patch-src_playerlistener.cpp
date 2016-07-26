--- src/playerlistener.cpp.orig	2016-07-26 15:06:09 UTC
+++ src/playerlistener.cpp
@@ -33,6 +33,10 @@
 #include <iostream>
 #include <algorithm>
 
+#ifdef Q_OS_UNIX
+#include <unistd.h>
+#endif
+
 using namespace std;
 
 
