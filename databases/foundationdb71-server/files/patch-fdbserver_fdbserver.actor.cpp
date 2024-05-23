--- fdbserver/fdbserver.actor.cpp.orig	2024-01-17 13:58:04 UTC
+++ fdbserver/fdbserver.actor.cpp
@@ -84,7 +84,11 @@
 #if defined(__linux__) || defined(__FreeBSD__)
 #include <execinfo.h>
 #include <signal.h>
+#if defined(__linux__)
 #include <sys/prctl.h>
+#elif defined(__FreeBSD__)
+#include <sys/procctl.h>
+#endif
 #ifdef ALLOC_INSTRUMENTATION
 #include <cxxabi.h>
 #endif
@@ -2238,9 +2242,14 @@ int main(int argc, char* argv[]) {
 			f = result;
 		} else if (role == ServerRole::FlowProcess) {
 			TraceEvent(SevDebug, "StartingFlowProcess").detail("From", "fdbserver");
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
 			prctl(PR_SET_PDEATHSIG, SIGTERM);
 			if (getppid() == 1) /* parent already died before prctl */
+				flushAndExit(FDB_EXIT_SUCCESS);
+#elif defined(__FreeBSD__)
+			const int sig = SIGTERM;
+			procctl(P_PID, 0, PROC_PDEATHSIG_CTL, (void*)&sig);
+			if (getppid() == 1) /* parent already died before procctl */
 				flushAndExit(FDB_EXIT_SUCCESS);
 #endif
 
