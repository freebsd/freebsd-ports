--- ../src/dbinc/mutex_int.h.orig	2010-04-12 13:25:22.000000000 -0700
+++ ../src/dbinc/mutex_int.h	2014-06-28 01:16:48.321255725 -0700
@@ -596,7 +596,7 @@
 	 : "=&r" (__r), "+r" (tsl)
 	 :
 	 : "cr0", "memory");
-	 return (int)tsl;
+	 return (tsl != 0);
 }
 
 static inline int
