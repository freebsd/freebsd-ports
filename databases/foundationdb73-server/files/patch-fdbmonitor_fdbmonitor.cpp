--- fdbmonitor/fdbmonitor.cpp.orig	2024-01-09 21:06:41 UTC
+++ fdbmonitor/fdbmonitor.cpp
@@ -27,6 +27,8 @@
 
 #ifdef __linux__
 #include <sys/prctl.h>
+#elif defined(__FreeBSD__)
+#include<sys/procctl.h>
 #endif
 
 #include <sys/wait.h>
@@ -758,7 +760,10 @@ void start_process(Command* cmd, ProcessID id, uid_t u
 		signal(SIGHUP, SIG_DFL);
 		signal(SIGINT, SIG_DFL);
 		signal(SIGTERM, SIG_DFL);
-
+#ifdef __linux__
+		signal(SIGCHLD, SIG_DFL);
+#endif
+		sigprocmask(SIG_SETMASK, mask, nullptr);
 		/* All output in this block should be to stdout (for SevInfo messages) or stderr (for SevError messages) */
 		/* Using log_msg() or log_err() from the child will cause the logs to be written incorrectly */
 		dup2(cmd->pipes[0][1], fileno(stdout));
@@ -787,14 +792,16 @@ void start_process(Command* cmd, ProcessID id, uid_t u
 		}
 
 #ifdef __linux__
-		signal(SIGCHLD, SIG_DFL);
-
-		sigprocmask(SIG_SETMASK, mask, nullptr);
-
 		/* death of our parent raises SIGHUP */
 		prctl(PR_SET_PDEATHSIG, SIGHUP);
 		if (getppid() == 1) /* parent already died before prctl */
 			exit(0);
+#elif defined(__FreeBSD__)
+		/* death of our parent raises SIGHUP */
+		const int sig = SIGHUP;
+		procctl(P_PID, 0, PROC_PDEATHSIG_CTL, (void*)&sig);
+		if (getppid() == 1) /* parent already died before procctl */
+			exit(0);
 #endif
 
 		if (delay)
