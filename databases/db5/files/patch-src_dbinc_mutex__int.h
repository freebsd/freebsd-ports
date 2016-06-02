--- src/dbinc/mutex_int.h.orig	2013-09-09 15:35:08 UTC
+++ src/dbinc/mutex_int.h
@@ -596,7 +596,7 @@ MUTEX_SET(int *tsl)  {
 	 : "=&r" (__r), "+r" (tsl)
 	 :
 	 : "cr0", "memory");
-	 return (int)tsl;
+	 return (tsl != 0);
 }
 
 static inline int
