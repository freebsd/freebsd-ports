--- main/sndserv.cc.orig	Fri Jan 28 22:41:59 2005
+++ main/sndserv.cc	Sun Oct  2 00:04:43 2005
@@ -522,8 +522,8 @@
 };
 
 void d4xSndServer::run(){
-	my_mutex.lock();
 	while(1){
+		my_mutex.lock();
 		pthread_cond_wait(&cond,&(my_mutex.m));
 		std::list<d4x::SndEvent> tmpqueue=queue;
 		queue.clear();
@@ -538,9 +538,7 @@
 			tmpqueue.pop_front();
 		};
 		if (stop_now) break;
-		my_mutex.unlock();
 	};
-	my_mutex.unlock();
 };
 
 void d4xSndServer::set_sound_file(int event,char *path){
