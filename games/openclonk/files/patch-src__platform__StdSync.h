--- src/platform/StdSync.h.orig	2014-10-05 17:22:07.000000000 +0400
+++ src/platform/StdSync.h	2014-11-27 18:14:51.000000000 +0300
@@ -135,7 +135,7 @@
 		{
 			// Use pthread_cond_wait or pthread_cond_timedwait depending on wait length. Check return value.
 			// Note this will temporarily unlock the mutex, so no deadlock should occur.
-			timespec ts = { iMillis / 1000, (iMillis % 1000) * 1000000 };
+			timespec ts = { static_cast<time_t>(iMillis / 1000), static_cast<long>(iMillis % 1000) * 1000000 };
 			if (0 != (iMillis != INFINITE ? pthread_cond_timedwait(&cond, &mutex, &ts) : pthread_cond_wait(&cond, &mutex)))
 			{
 				pthread_mutex_unlock(&mutex);
