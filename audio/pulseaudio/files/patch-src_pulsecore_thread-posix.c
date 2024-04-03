--- src/pulsecore/thread-posix.c.orig	2022-06-21 10:54:48 UTC
+++ src/pulsecore/thread-posix.c
@@ -71,6 +71,8 @@ static void* internal_thread_func(void *userdata) {
     prctl(PR_SET_NAME, t->name);
 #elif defined(HAVE_PTHREAD_SETNAME_NP) && defined(OS_IS_DARWIN)
     pthread_setname_np(t->name);
+#elif defined(HAVE_PTHREAD_SETNAME_NP) && defined(OS_IS_FREEBSD)
+    pthread_setname_np(t->id, t->name);
 #endif
 
     t->id = pthread_self();
@@ -184,6 +186,8 @@ void pa_thread_set_name(pa_thread *t, const char *name
     prctl(PR_SET_NAME, name);
 #elif defined(HAVE_PTHREAD_SETNAME_NP) && defined(OS_IS_DARWIN)
     pthread_setname_np(name);
+#elif defined(HAVE_PTHREAD_SETNAME_NP) && defined(OS_IS_FREEBSD)
+    pthread_setname_np(t->id, t->name);
 #endif
 }
 
@@ -201,7 +205,7 @@ const char *pa_thread_get_name(pa_thread *t) {
             t->name = NULL;
         }
     }
-#elif defined(HAVE_PTHREAD_GETNAME_NP) && defined(OS_IS_DARWIN)
+#elif defined(HAVE_PTHREAD_GETNAME_NP) && (defined(OS_IS_DARWIN) || defined(OS_IS_FREEBSD))
     if (!t->name) {
         t->name = pa_xmalloc0(17);
         pthread_getname_np(t->id, t->name, 16);
