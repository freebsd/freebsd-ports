--- cppForSwig/SocketObject.cpp.orig	2021-05-20 07:39:28 UTC
+++ cppForSwig/SocketObject.cpp
@@ -11,6 +11,8 @@
 #include <cstring>
 #include <stdexcept>
 
+#include <netinet/in.h>
+
 #include "google/protobuf/text_format.h"
 
 using namespace std;
