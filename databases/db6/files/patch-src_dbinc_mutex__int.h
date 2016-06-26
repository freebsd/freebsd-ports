--- src/dbinc/mutex_int.h.orig	2016-03-28 19:45:54 UTC
+++ src/dbinc/mutex_int.h
@@ -652,7 +652,7 @@ MUTEX_SET(int *tsl)  {
 	 : "=&r" (__r), "+r" (tsl)
 	 :
 	 : "cr0", "memory");
-	 return (int)tsl;
+	 return (tsl != 0);
 }
 
 static inline int
