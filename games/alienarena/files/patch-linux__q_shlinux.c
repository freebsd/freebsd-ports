--- ./linux/q_shlinux.c.orig	Tue May 16 15:20:09 2006
+++ ./linux/q_shlinux.c	Tue May 16 15:20:10 2006
@@ -30,6 +30,11 @@
 
 #include "../qcommon/qcommon.h"
 
+#ifndef __linux__
+/* For round_page() macro. */
+#include <machine/param.h>
+#endif
+
 //===============================================================================
 
 byte *membase;
@@ -42,7 +47,7 @@
 	maxhunksize = maxsize + sizeof(int);
 	curhunksize = 0;
 	membase = mmap(0, maxhunksize, PROT_READ|PROT_WRITE, 
-		MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
+		MAP_PRIVATE|MAP_ANON, -1, 0);
 	if (membase == NULL || membase == (byte *)-1)
 		Sys_Error("unable to virtual allocate %d bytes", maxsize);
 
@@ -68,7 +73,32 @@
 {
 	byte *n;
 
+#ifndef __linux__
+	/*
+	 * The Linux system call mremap() is not present, so a wrapper is
+	 * needed. This code frees the unused part of the allocated memory
+	 * (equivalent to mremap() when shrinking a block of memory).
+	 */
+
+	size_t old_size = maxhunksize;
+	size_t new_size = curhunksize + sizeof(int);
+	void * unmap_base;
+	size_t unmap_len;
+
+	new_size = round_page(new_size);
+	old_size = round_page(old_size);
+
+	if (new_size > old_size)
+		n = 0; /* error */
+	else if (new_size < old_size)
+	{
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
