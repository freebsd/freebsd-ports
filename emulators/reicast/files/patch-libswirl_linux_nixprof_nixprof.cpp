--- libswirl/linux/nixprof/nixprof.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/linux/nixprof/nixprof.cpp
@@ -13,6 +13,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <thread>
 #include <pthread.h>
 #include <unistd.h>
 #include <pthread.h>
@@ -56,7 +57,7 @@
 
 static int tick_count=0;
 static pthread_t proft;
-static pthread_t thread[2];
+static pthread_t thread_[2];
 static void*     prof_address[2];
 static u32 prof_wait;
 
@@ -76,8 +77,8 @@ void prof_handler (int sn, siginfo_t * si, void *ctxr)
 	context_from_segfault(&ctx);
 	
 	int thd=-1;
-	if (pthread_self()==thread[0]) thd=0;
-	else if (pthread_self()==thread[1]) thd=1;
+	if (pthread_self()==thread_[0]) thd=0;
+	else if (pthread_self()==thread_[1]) thd=1;
 	else return;
 
 	prof_address[thd] = (void*)ctx.pc;
@@ -94,7 +95,7 @@ void install_prof_handler(int id)
 	act.sa_flags = SA_SIGINFO | SA_RESTART;
 	sigaction(SIGPROF, &act, &segv_oact);
 
-	thread[id]=pthread_self();
+	thread_[id]=pthread_self();
 }
 
 static void prof_head(FILE* out, const char* type, const char* name)
@@ -299,7 +300,7 @@ static void* profiler_main(void *ptr)
 		{
 			tick_count++;
 			// printf("Sending SIGPROF %08X %08X\n",thread[0],thread[1]);
-			for (int i = 0; i < 2; i++) pthread_kill(thread[i], SIGPROF);
+			for (int i = 0; i < 2; i++) pthread_kill(thread_[i], SIGPROF);
 			// printf("Sent SIGPROF\n");
 			usleep(prof_wait);
 			// fwrite(&prof_address[0],1,sizeof(prof_address[0])*2,prof_out);
