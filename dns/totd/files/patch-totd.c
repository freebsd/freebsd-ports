--- totd.c.orig	Wed Feb  2 12:10:31 2005
+++ totd.c	Wed Apr 12 14:56:16 2006
@@ -504,7 +504,7 @@
 				tvp = &tv_out;
 				if (T.debug > 2)
 					syslog (LOG_DEBUG, "next timeout after %ld s.",
-						tv_out.tv_sec);
+						(long)tv_out.tv_sec);
 			}
 		}
 
