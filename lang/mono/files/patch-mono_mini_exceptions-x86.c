--- mono/mini/exceptions-x86.c.orig
+++ mono/mini/exceptions-x86.c
@@ -12,6 +12,7 @@
 #include <glib.h>
 #include <signal.h>
 #include <string.h>
+#include <sys/ucontext.h>
 
 #include <mono/metadata/abi-details.h>
 #include <mono/arch/x86/x86-codegen.h>
