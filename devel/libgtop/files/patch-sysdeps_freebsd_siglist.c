--- sysdeps/freebsd/siglist.c.orig	Fri Jan 20 02:56:40 2006
+++ sysdeps/freebsd/siglist.c	Fri Jan 20 02:56:44 2006
@@ -26,4 +26,37 @@
 #include <glibtop/signal.h>
 
 const glibtop_signame glibtop_sys_siglist [] =
-{ { 0, NULL, NULL } };
+{  {  1, "SIGHUP",  "Hangup" },
+   {  2, "SIGINT",  "Interrupt" },
+   {  3, "SIGQUIT", "Quit" },
+   {  4, "SIGILL",  "Illegal Instruction" },
+   {  5, "SIGTRAP", "Trace/Breakpoint Trap" },
+   {  6, "SIGABRT", "Abort" },
+   {  7, "SIGEMT",  "Emulation Trap" },
+   {  8, "SIGFPE",  "Arithmetic Exception" },
+   {  9, "SIGKILL", "Killed" },
+   { 10, "SIGBUS",  "Bus Error" },
+   { 11, "SIGSEGV", "Segmentation Fault" },
+   { 12, "SIGSYS",  "Bad System Call" },
+   { 13, "SIGPIPE", "Broken Pipe" },
+   { 14, "SIGALRM", "Alarm Clock" },
+   { 15, "SIGTERM", "Terminated" },
+   { 16, "SIGURG",  "Urgent Condition Present On Socket" },
+   { 17, "SIGSTOP", "Stop (cannot be caught or ignored)" },
+   { 18, "SIGTSTP", "Stop Signal Generated From Keyboard" },
+   { 19, "SIGCONT", "Continue After Stop" },
+   { 20, "SIGCHLD", "Child Status Has Changed" },
+   { 21, "SIGTTIN", "Background Read Attempted From Control Terminal" },
+   { 22, "SIGTTOU", "Background Write Attempted To Control Terminal" },
+   { 23, "SIGIO",   "I/O Is Possible On A Descriptor" },
+   { 24, "SIGXCPU", "CPU Time Limit Exceeded" },
+   { 25, "SIGXFSZ", "File Size Limit Exceeded" },
+   { 26, "SIGVTALRM","Virtual Time Alarm" },
+   { 27, "SIGPROF", "Profiling Timer Alarm" },
+   { 28, "SIGWINCH","Window Size Change" },
+   { 29, "SIGINFO", "Status Request From Keyboard" },
+   { 30, "SIGUSR1", "User Defined Signal 1" },
+   { 31, "SIGUSR2", "User Defined Signal 2" },
+   { 32, "SIGTHR",  "Thread Interrupt" },
+   {  0, NULL, NULL }
+};
