--- src/mediaunits/pandora/pandorasource.cpp.orig	2020-03-17 17:41:28 UTC
+++ src/mediaunits/pandora/pandorasource.cpp
@@ -15,6 +15,7 @@
 
 #include <limits.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <resolv.h>
 
