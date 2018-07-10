--- src/bsd/kqueue/kqueue_stubs.c.orig	2011-05-30 02:53:09 UTC
+++ src/bsd/kqueue/kqueue_stubs.c
@@ -44,22 +44,22 @@ kevent_dispose(void* p){
 
 void
 kevent_set_readevent(void* ke,int fd){
-    EV_SET(ke,fd,EVFILT_READ,EV_ADD,0,0,NULL);
+    EV_SET((struct kevent*)ke,fd,EVFILT_READ,EV_ADD,0,0,NULL);
 }
 
 void
 kevent_set_writeevent(void* ke,int fd){
-    EV_SET(ke,fd,EVFILT_WRITE,EV_ADD,0,0,NULL);
+    EV_SET((struct kevent*)ke,fd,EVFILT_WRITE,EV_ADD,0,0,NULL);
 }
 
 void
 kevent_set_enableuserevent(void* ke,int id){
-    EV_SET(ke,id,EVFILT_USER,EV_ADD,0,0,NULL);
+    EV_SET((struct kevent*)ke,id,EVFILT_USER,EV_ADD,0,0,NULL);
 }
 
 void
 kevent_set_triggeruserevent(void* ke,int id){
-    EV_SET(ke,id,EVFILT_USER,0,NOTE_TRIGGER,0,NULL);
+    EV_SET((struct kevent*)ke,id,EVFILT_USER,0,NOTE_TRIGGER,0,NULL);
 }
 
 int
