--- tothread.h.orig	2007-11-13 02:21:24.000000000 +0600
+++ tothread.h	2007-11-13 02:21:49.000000000 +0600
@@ -217,6 +217,8 @@
 * thread and task objects so the calling thread must never delete a started thread.
 */
 
+void *toThreadStartWrapper(void*);
+
 class toThread
 {
 private:
