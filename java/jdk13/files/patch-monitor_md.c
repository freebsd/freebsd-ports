$FreeBSD$

--- ../src/solaris/hpi/native_threads/src/monitor_md.c	11 Jul 2001 21:42:33 -0000	1.1.1.1
+++ ../src/solaris/hpi/native_threads/src/monitor_md.c	22 Nov 2004 17:19:50 -0000
@@ -132,7 +132,7 @@
 	mid->monitor_owner = self;
 	mid->entry_count = 1;
 	return SYS_OK;
-    } else if (err == EBUSY) { /* it's already locked */
+    } else if (err == EBUSY || err == EDEADLK) { /* it's already locked */
 	if (mid->monitor_owner == self) {
 	    mid->entry_count++;
 	    return SYS_OK;
