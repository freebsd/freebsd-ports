--- client/vector/sighandler.h.orig	2018-01-14 23:02:12 UTC
+++ client/vector/sighandler.h
@@ -44,6 +44,7 @@
 #define SIGHANDLER_H
 
 
+#include <stddef.h>
 #include <signal.h>
 #include <setjmp.h>
 
