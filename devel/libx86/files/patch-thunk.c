--- thunk.c.orig	2008-04-03 00:48:00 UTC
+++ thunk.c
@@ -11,7 +11,9 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/mman.h>
+#ifndef __FreeBSD__
 #include <sys/io.h>
+#endif
 #include <string.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
@@ -169,8 +171,8 @@ int LRMI_init() {
 	X86_ESP = 0xFFF9;
 	memset (stack, 0, 64*1024);
 
-	*((char *)0) = 0x4f; /* Make sure that we end up jumping back to a
-				halt instruction */
+	*((volatile char *)0) = 0x4f; /* Make sure that we end up jumping back to a
+					 halt instruction */
 
 	M.mem_base = 0;
 	M.mem_size = 1024*1024;
