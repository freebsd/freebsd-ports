--- backends/x86_64_initreg.c.orig	2014-06-17 18:51:09 UTC
+++ backends/x86_64_initreg.c
@@ -32,6 +32,7 @@
 
 #include <stdlib.h>
 #ifdef __x86_64__
+# include <sys/types.h>
 # include <sys/user.h>
 # include <sys/ptrace.h>
 #endif
