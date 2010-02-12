--- src/Container/Container_i.cxx.orig	2009-03-18 20:52:29.000000000 +0600
+++ src/Container/Container_i.cxx	2009-05-20 10:21:06.000000000 +0700
@@ -29,6 +29,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <time.h>
+#include <sys/wait.h>
 #ifndef WIN32
 #include <sys/time.h>
 #include <dlfcn.h>
