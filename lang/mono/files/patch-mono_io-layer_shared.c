--- mono/io-layer/shared.c.orig	Fri Dec  1 01:57:46 2006
+++ mono/io-layer/shared.c	Wed Feb 21 13:28:07 2007
@@ -330,10 +330,10 @@
 		while ((_wapi_sem_id = semget (key, _WAPI_SHARED_SEM_COUNT,
 					       IPC_CREAT | IPC_EXCL | 0600)) == -1) {
 			if (errno == ENOMEM) {
-				g_critical ("%s: semget error: %s", __func__,
+				g_error ("%s: semget error: %s", __func__,
 					    g_strerror (errno));
 			} else if (errno == ENOSPC) {
-				g_critical ("%s: semget error: %s.  Try deleting some semaphores with ipcs and ipcrm", __func__, g_strerror (errno));
+				g_error ("%s: semget error: %s.  Try deleting some semaphores with ipcs and ipcrm\nor increase the maximum number of semaphore in the system.", __func__, g_strerror (errno));
 			} else if (errno != EEXIST) {
 				if (retries > 3)
 					g_warning ("%s: semget error: %s key 0x%x - trying again", __func__,
