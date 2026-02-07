--- mono/utils/mono-threads.c.orig	2018-04-13 23:37:57 UTC
+++ mono/utils/mono-threads.c
@@ -1316,7 +1316,7 @@ mono_thread_info_sleep (guint32 ms, gboo
 		} while (1);
 	} else {
 		int ret;
-#if defined (__linux__) && !defined(HOST_ANDROID)
+#if defined (HAVE_CLOCK_NANOSLEEP) && !defined(HOST_ANDROID)
 		struct timespec start, target;
 
 		/* Use clock_nanosleep () to prevent time drifting problems when nanosleep () is interrupted by signals */
@@ -1346,7 +1346,7 @@ mono_thread_info_sleep (guint32 ms, gboo
 			memset (&rem, 0, sizeof (rem));
 			ret = nanosleep (&req, &rem);
 		} while (ret != 0);
-#endif /* __linux__ */
+#endif /* HAVE_CLOCK_NANOSLEEP */
 	}
 
 	MONO_EXIT_GC_SAFE;
