--- mlib/src/x11/x11_main.c.orig	2017-02-18 23:19:17 UTC
+++ mlib/src/x11/x11_main.c
@@ -36,7 +36,6 @@ $*/
 
 #include <stdio.h>
 #include <sys/select.h>
-#include <sys/eventfd.h>
 #include <unistd.h>
 
 #include <ft2build.h>
@@ -199,10 +198,9 @@ static void _app_init_thread(mAppSystem 
 
 #else
 
-	p->fd_event = eventfd(0, 0);
-	if(p->fd_event == -1) p->fd_event = 0;
+	if(pipe(p->fd_pipe) == -1) p->fd_pipe[0] = p->fd_pipe[1] = 0;
 
-	p->select_fdnum = 1 + ((p->connection < p->fd_event)? p->fd_event: p->connection);
+	p->select_fdnum = 1 + ((p->connection < p->fd_pipe[1])? p->fd_pipe[1]: p->connection);
 
 	p->mutex = mMutexNew();
 	mMutexLock(p->mutex);
@@ -228,8 +226,10 @@ void __mAppEnd(void)
 
 #if !defined(MLIB_NO_THREAD)
 
-	if(p->fd_event)
-		close(p->fd_event);
+	if(p->fd_pipe[0])
+		close(p->fd_pipe[0]);
+	if(p->fd_pipe[1])
+		close(p->fd_pipe[1]);
 
 	if(p->mutex)
 	{
@@ -435,8 +435,8 @@ void mAppWakeUpEvent()
 
 	int64_t num = 1;
 
-	if(MAPP_SYS->fd_event)
-		write(MAPP_SYS->fd_event, &num, 8);
+	if(MAPP_SYS->fd_pipe[1])
+		write(MAPP_SYS->fd_pipe[1], &num, 8);
 
 #endif
 }
@@ -492,7 +492,8 @@ static int _wait_event(void)
 	FD_SET(p->connection, &fd);
 
 #if !defined(MLIB_NO_THREAD)
-	if(p->fd_event) FD_SET(p->fd_event, &fd);
+	if(p->fd_pipe[0]) FD_SET(p->fd_pipe[0], &fd);
+	if(p->fd_pipe[1]) FD_SET(p->fd_pipe[1], &fd);
 #endif
 	
 	//タイマーの最小時間
@@ -526,10 +527,10 @@ static int _wait_event(void)
 	else if(FD_ISSET(p->connection, &fd))
 		return 1;
 #if !defined(MLIB_NO_THREAD)
-	else if(p->fd_event && FD_ISSET(p->fd_event, &fd))
+	else if(p->fd_pipe[0] && FD_ISSET(p->fd_pipe[0], &fd))
 	{
 		int64_t eft;
-		read(p->fd_event, &eft, 8);
+		read(p->fd_pipe[0], &eft, 8);
 	}
 #endif
 
