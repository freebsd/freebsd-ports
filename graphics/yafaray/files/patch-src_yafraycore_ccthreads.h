--- src/yafraycore/ccthreads.h.orig	2007-07-02 17:04:18.000000000 -0400
+++ src/yafraycore/ccthreads.h	2007-07-02 17:04:33.000000000 -0400
@@ -81,9 +81,7 @@
 		virtual void body()=0;
 		void run();
 		void wait();
-		int getId() {return (int)id;};
 		pthread_t getPid() {return id;};
-		int getSelf() {return (int)pthread_self();};
 		bool isRunning()const {return running;};
 	protected:
 		bool running;
