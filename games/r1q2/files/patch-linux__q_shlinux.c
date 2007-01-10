--- linux/q_shlinux.c.orig	Wed Jan 10 19:46:44 2007
+++ linux/q_shlinux.c	Wed Jan 10 19:47:36 2007
@@ -12,25 +12,23 @@
 
 #include "../qcommon/qcommon.h"
 
+#ifndef __linux__
+#include <machine/param.h>
+#endif
+
 //===============================================================================
 
 byte *membase;
 int maxhunksize;
 int curhunksize;
 
-#ifdef __FreeBSD__
-#define MMAP_ANON MAP_ANON
-#else
-#define MMAP_ANON MAP_ANONYMOUS
-#endif
-
 void *Hunk_Begin (int maxsize)
 {
 	// reserve a huge chunk of memory, but don't commit any yet
 	maxhunksize = maxsize + sizeof(int);
 	curhunksize = 0;
 	membase = mmap(0, maxhunksize, PROT_READ|PROT_WRITE, 
-		MAP_PRIVATE|MMAP_ANON, -1, 0);
+		MAP_PRIVATE|MAP_ANON, -1, 0);
 	if (membase == NULL || membase == (byte *)-1)
 		Sys_Error("unable to virtual allocate %d bytes", maxsize);
 
@@ -54,14 +52,29 @@
 
 int Hunk_End (void)
 {
-#ifndef __FreeBSD__
 	byte *n;
 
+#ifndef __linux__
+	size_t old_size = maxhunksize;
+	size_t new_size = curhunksize + sizeof(int);
+	void * unmap_base;
+	size_t unmap_len;
+
+	new_size = round_page(new_size);
+	old_size = round_page(old_size);
+	if (new_size > old_size)
+		n = 0; /* error */
+	else if (new_size < old_size) {
+		unmap_base = (caddr_t)(membase + new_size);
+		unmap_len = old_size - new_size;
+		n = munmap(unmap_base, unmap_len) + membase;
+	}
+#else
 	n = mremap(membase, maxhunksize, curhunksize + sizeof(int), 0);
+#endif
 	if (n != membase)
 		Sys_Error("Hunk_End:  Could not remap virtual block (%d)", errno);
 	*((int *)membase) = curhunksize + sizeof(int);
-#endif
 	
 	return curhunksize;
 }
@@ -107,7 +120,9 @@
 
 void Sys_DebugBreak (void)
 {
+#ifdef __i386__
         __asm ("int $3");
+#endif
 }
 
 void Sys_Mkdir (char *path)
