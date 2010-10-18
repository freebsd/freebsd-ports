
$FreeBSD$

https://bugzilla.novell.com/show_bug.cgi?id=647248

--- libgc/pthread_support.c.orig
+++ libgc/pthread_support.c
@@ -1344,7 +1344,8 @@ void * GC_start_routine_head(void * arg, void *base_addr,
     if (start) *start = si -> start_routine;
     if (start_arg) *start_arg = si -> arg;
 
-    sem_post(&(si -> registered));	/* Last action on si.	*/
+	if (!(si->flags & FOREIGN_THREAD))
+		sem_post(&(si -> registered));	/* Last action on si.	*/
     					/* OK to deallocate.	*/
 #   if defined(THREAD_LOCAL_ALLOC) && !defined(DBG_HDRS_ALL)
  	LOCK();
