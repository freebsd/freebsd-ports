--- src/trace.c.orig	2010-01-18 06:13:18 UTC
+++ src/trace.c
@@ -88,7 +88,7 @@ void * thread_trace(thr_parms * t) {
    * wraparound in _anyone's_ lifetime, so no need to even check....
    * On lesser-bit platforms, we're not quite so lucky, so we have to check.
    */
-#if !defined(LP64)
+#if !defined(LP64) && !defined(_LP64)
   if (local_mbox != NULL) {
     if (t->serialno > (((unsigned long) 1) << ((sizeof(unsigned long) * 8) - 3))) {
       memset(local_mbox, 0, sizeof(unsigned long) * scene->objgroup.numobjects);
