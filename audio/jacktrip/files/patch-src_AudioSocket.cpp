Fix build with Qt >= 6.9.0

https://github.com/jacktrip/jacktrip/pull/1419

--- src/AudioSocket.cpp.orig	2025-01-21 17:04:33 UTC
+++ src/AudioSocket.cpp
@@ -37,6 +37,7 @@
 
 #include "AudioSocket.h"
 
+#include <QDebug>
 #include <QEventLoop>
 #include <iostream>
 
