--- ../../j2se/src/solaris/hpi/native_threads/src/monitor_md.c	22 Oct 2003 23:03:43 -0000	1.1.1.2
+++ ../../j2se/src/solaris/hpi/native_threads/src/monitor_md.c	21 Oct 2004 05:42:52 -0000
@@ -129,7 +129,7 @@
 	mid->monitor_owner = self;
 	mid->entry_count = 1;
 	return SYS_OK;
-    } else if (err == EBUSY) { /* it's already locked */
+    } else if (err == EBUSY || err == EDEADLK) { /* it's already locked */
 	if (mid->monitor_owner == self) {
 	    mid->entry_count++;
 	    return SYS_OK;
