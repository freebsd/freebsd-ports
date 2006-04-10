--- src/q_sh.c.orig	Sun Apr  2 01:27:58 2006
+++ src/q_sh.c	Tue Apr  4 00:35:10 2006
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <sys/mman.h>
 #include <sys/time.h>
+#include <machine/param.h>
 
 #include "qcommon.h"
 
@@ -42,7 +43,7 @@
 	curhunksize = 0;
 	
 	membase = mmap(0, maxhunksize, 
-		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0
+		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0
 	);
 	
 	if(membase == NULL || membase ==(byte *) - 1)
@@ -66,9 +67,22 @@
 }
 
 int Hunk_End(void){
-	byte *n;
+	byte *n = membase;
 	
-	n = mremap(membase, maxhunksize, curhunksize + sizeof(int), 0);
+	size_t old_size = maxhunksize;
+	size_t new_size = curhunksize + sizeof(int);
+	void * unmap_base;
+	size_t unmap_len;
+
+	new_size = round_page(new_size);
+	old_size = round_page(old_size);
+	if (new_size > old_size)
+		n = (byte *)-1;				/* error */
+	else if (new_size < old_size) {
+		unmap_base = (caddr_t)(membase + new_size);
+		unmap_len = old_size - new_size;
+		n = munmap(unmap_base, unmap_len) + membase;
+	}
 	
 	if(n != membase)
 		Sys_Error("Hunk_End:  Could not remap virtual block(%d)", errno);
