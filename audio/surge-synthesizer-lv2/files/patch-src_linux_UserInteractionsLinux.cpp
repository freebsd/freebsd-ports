--- src/linux/UserInteractionsLinux.cpp.orig	2020-04-15 17:52:26 UTC
+++ src/linux/UserInteractionsLinux.cpp
@@ -6,6 +6,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <thread>
+#include <sstream>
 
 /*
 ** In June 2019, @baconpaul chose to implement these with an attempt
