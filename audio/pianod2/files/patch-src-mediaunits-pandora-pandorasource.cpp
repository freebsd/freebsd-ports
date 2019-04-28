--- src/mediaunits/pandora/pandorasource.cpp.orig	2018-03-16 18:13:50 UTC
+++ src/mediaunits/pandora/pandorasource.cpp
@@ -15,6 +15,7 @@
 
 #include <limits.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <resolv.h>
 
