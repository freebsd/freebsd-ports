https://bitbucket.org/agriggio/art/issues/142/failure-on-freebsd-error-use-of-undeclared
--- rtengine/subprocess.cc.orig	2020-11-18 20:27:15 UTC
+++ rtengine/subprocess.cc
@@ -23,6 +23,8 @@
 #include <iostream>
 #include <unistd.h>
 #include <giomm.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 
 #include <set>
 
