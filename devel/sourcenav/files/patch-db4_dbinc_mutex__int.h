--- db4/dbinc/mutex_int.h.orig	2010-10-28 20:58:58 UTC
+++ db4/dbinc/mutex_int.h
@@ -596,7 +596,7 @@ MUTEX_SET(int *tsl)  {
 	 : "=&r" (__r), "+r" (tsl)
 	 :
 	 : "cr0", "memory");
-	 return (int)tsl;
+	 return (tsl != 0);
 }
 
 static inline int
