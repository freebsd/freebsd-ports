--- ./q_shlinux.c.orig	Thu May 19 17:56:13 2005
+++ ./q_shlinux.c	Sun Feb 26 11:23:56 2006
@@ -12,6 +12,10 @@
 
 #include "qcommon.h"
 
+#ifdef __FreeBSD__
+#include <machine/param.h>
+#endif
+
 //===============================================================================
 
 byte *membase;
@@ -54,14 +58,32 @@
 
 int Hunk_End (void)
 {
-#ifndef __FreeBSD__
 	byte *n;
 
+#ifdef __FreeBSD__
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
+#endif
+#ifdef __linux__
 	n = mremap(membase, maxhunksize, curhunksize + sizeof(int), 0);
+#endif
 	if (n != membase)
 		Sys_Error("Hunk_End:  Could not remap virtual block (%d)", errno);
 	*((int *)membase) = curhunksize + sizeof(int);
-#endif
 	
 	return curhunksize;
 }
