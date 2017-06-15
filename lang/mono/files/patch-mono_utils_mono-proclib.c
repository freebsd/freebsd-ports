--- mono/utils/mono-proclib.c.orig	2016-07-29 09:10:33 UTC
+++ mono/utils/mono-proclib.c
@@ -107,11 +107,11 @@ mono_process_list (int *size)
 		mib [2] = KERN_PROC_ALL;
 		mib [3] = 0;
 
-		res = sysctl (mib, 4, NULL, &data_len, NULL, 0);
+		res = sysctl (mib, 3, NULL, &data_len, NULL, 0);
 		if (res)
 			return NULL;
 		processes = (struct kinfo_proc *) malloc (data_len);
-		res = sysctl (mib, 4, processes, &data_len, NULL, 0);
+		res = sysctl (mib, 3, processes, &data_len, NULL, 0);
 		if (res < 0) {
 			free (processes);
 			if (errno != ENOMEM)
