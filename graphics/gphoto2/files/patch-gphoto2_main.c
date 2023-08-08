--- gphoto2/main.c.orig	2020-07-02 06:39:33 UTC
+++ gphoto2/main.c
@@ -1211,14 +1211,14 @@ start_timeout_func (Camera *camera, unsigned int timeo
 
 	pthread_create (&tid, NULL, thread_func, td);
 
-	return (tid);
+	return (intptr_t)tid;
 }
 
 static void
 stop_timeout_func (Camera __unused__ *camera, unsigned int id,
 		   void __unused__ *data)
 {
-	pthread_t tid = id;
+	pthread_t tid = (pthread_t)(intptr_t)id;
 
 	pthread_cancel (tid);
 	pthread_join (tid, NULL);
