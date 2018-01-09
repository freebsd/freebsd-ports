--- gcc/toplev.c.orig	2018-01-04 15:22:21 UTC
+++ gcc/toplev.c
@@ -1386,7 +1386,7 @@ process_options (void)
 
       if (flag_sanitize & SANITIZE_THREAD)
 	{
-	  error (UNKNOWN_LOCATION,
+	  error_at (UNKNOWN_LOCATION,
 		 "%<-fcheck-pointer-bounds%> is not supported with "
 		 "Thread Sanitizer");
 
