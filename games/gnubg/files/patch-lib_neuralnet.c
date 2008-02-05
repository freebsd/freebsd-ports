--- lib/neuralnet.c.orig	2008-01-14 23:59:11.000000000 +0100
+++ lib/neuralnet.c	2008-01-15 00:05:27.000000000 +0100
@@ -30,6 +30,10 @@
 #include <time.h>
 #include <stdlib.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 #include "neuralnet.h"
 #include "sse.h"
 
@@ -960,7 +964,17 @@
     if ( 0 != error ) result = 0;
     return result;
 
-#else
+#endif
+
+#ifdef __FreeBSD__
+
+#include <sys/sysctl.h>
+    size_t length = sizeof( result );
+    int error = sysctlbyname("hw.instruction_sse", &result, &length, NULL, 0);
+    if ( 0 != error) result = 0;
+    return result;
+
+#endif
 
 	asm (
 		/* Check if cpuid is supported (can bit 21 of flags be changed) */
@@ -1011,7 +1025,6 @@
 "4:"
 
 			: "=b"(result) : : "%eax", "%ecx", "%edx");
-#endif
 
 	switch (result)
 	{
