--- mono/utils/mono-proclib.c.orig	2017-04-12 10:51:21.000000000 +0000
+++ mono/utils/mono-proclib.c	2017-05-01 13:05:26.013997000 +0000
@@ -116,11 +116,11 @@
 		mib [2] = KERN_PROC_ALL;
 		mib [3] = 0;
 
-		res = sysctl (mib, 4, NULL, &data_len, NULL, 0);
+		res = sysctl (mib, 3, NULL, &data_len, NULL, 0);
 		if (res)
 			return NULL;
 		processes = (struct kinfo_proc *) g_malloc (data_len);
-		res = sysctl (mib, 4, processes, &data_len, NULL, 0);
+		res = sysctl (mib, 3, processes, &data_len, NULL, 0);
 		if (res < 0) {
 			g_free (processes);
 			if (errno != ENOMEM)
