--- scopes/monoscope/monoscope.c-orig	Thu Jun 19 11:15:16 2003
+++ scopes/monoscope/monoscope.c	Thu Jun 19 11:15:22 2003
@@ -103,7 +103,7 @@
 		pthread_mutex_lock(&update_mutex);
 		memcpy (copyEq, newEq, sizeof (short) * CONVOLVE_BIG);
 		thisEq = copyEq;
-#if 1					
+#if 0					
 		val = convolve_match (avgEq, copyEq, state);
 		thisEq += val;
 #endif	
