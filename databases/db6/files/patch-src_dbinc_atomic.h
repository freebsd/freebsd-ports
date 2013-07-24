--- ../src/dbinc/atomic.h.orig	2012-02-29 19:48:38.000000000 +0100
+++ ../src/dbinc/atomic.h	2012-05-04 22:39:32.000000000 +0200
@@ -70,7 +70,7 @@ typedef struct {
  * These have no memory barriers; the caller must include them when necessary.
  */
 #define	atomic_read(p)		((p)->value)
-#define	atomic_init(p, val)	((p)->value = (val))
+#define	db_atomic_init(p, val)	((p)->value = (val))
 
 #ifdef HAVE_ATOMIC_SUPPORT
 
@@ -206,7 +206,7 @@ static inline int __atomic_compare_excha
 #define	atomic_dec(env, p)	(--(p)->value)
 #define	atomic_compare_exchange(env, p, oldval, newval)		\
 	(DB_ASSERT(env, atomic_read(p) == (oldval)),		\
-	atomic_init(p, (newval)), 1)
+	db_atomic_init(p, (newval)), 1)
 #else
 #define atomic_inc(env, p)	__atomic_inc(env, p)
 #define atomic_dec(env, p)	__atomic_dec(env, p)
