--- components/crashcatcher/crashcatcher.cpp.orig	2019-05-07 13:04:04 UTC
+++ components/crashcatcher/crashcatcher.cpp
@@ -11,6 +11,7 @@
 #include <limits.h>
 
 #include <pthread.h>
+#include <memory>
 #include <stdbool.h>
 #include <sys/ptrace.h>
 
