--- linux/q_shlinux.c.orig	Fri Sep 28 21:38:18 2007
+++ linux/q_shlinux.c	Fri Sep 28 21:39:42 2007
@@ -16,6 +16,10 @@
 
 #include "../qcommon/qcommon.h"
 
+#ifndef __linux__
+#include <machine/param.h>
+#endif
+
 //===============================================================================
 
 byte *membase;
@@ -58,14 +62,29 @@
 
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
@@ -111,7 +130,9 @@
 
 void Sys_DebugBreak (void)
 {
+#ifdef __i386__
         __asm ("int $3");
+#endif
 }
 
 void Sys_Mkdir (char *path)
