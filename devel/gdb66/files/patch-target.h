--- gdb/target.h	Sat Feb  9 20:08:42 2002
+++ gdb/target.h	Fri May 24 08:38:31 2002
@@ -52,6 +52,7 @@
     dummy_stratum,		/* The lowest of the low */
     file_stratum,		/* Executable files, etc */
     core_stratum,		/* Core dump files */
+    kcore_stratum,		/* Kernel core files */
     download_stratum,		/* Downloading of remote targets */
     process_stratum,		/* Executing processes */
     thread_stratum		/* Executing threads */
