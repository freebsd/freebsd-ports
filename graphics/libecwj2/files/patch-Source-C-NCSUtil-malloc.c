--- Source/C/NCSUtil/malloc.c.orig	2009-04-05 22:40:20.000000000 +0400
+++ Source/C/NCSUtil/malloc.c	2009-04-05 22:44:30.000000000 +0400
@@ -70,6 +70,10 @@
 
 #endif
 
+#ifdef FREEBSD
+#include <sys/sysctl.h>
+#endif
+
 void NCSMallocInit(void)
 {
 #ifdef NOTDEF
@@ -430,7 +434,21 @@
 	return((INT32)nTotalRam);
 	
 #else	/* PALM */
+
+#ifdef FREEBSD
+	int mib[2], physmem;
+	size_t len;
+
+	mib[0] = CTL_HW;
+	mib[1] = HW_PHYSMEM;
+	len = sizeof(physmem);
+	sysctl(mib, 2, &physmem, &len, NULL, 0);
+
+	return (physmem);
+
+#else	/* FREEBSD */
 #error - NCSPhysicalMemorySize()
+#endif	/* FREEBSD */
 #endif	/* PALM */
 #endif	/* SOLARIS */
 #endif	/* IRIX */
