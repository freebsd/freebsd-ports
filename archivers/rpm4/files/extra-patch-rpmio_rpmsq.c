--- rpmio/rpmsq.c.orig	2012-06-17 22:38:37.000000000 +0200
+++ rpmio/rpmsq.c	2012-06-17 22:38:29.000000000 +0200
@@ -39,6 +39,25 @@
     { -1,	NULL },
 };
 
+int
+sighold(int sig)
+{
+	sigset_t set;
+
+	sigemptyset(&set);
+	sigaddset(&set, sig);
+	return (_sigprocmask(SIG_BLOCK, &set, NULL));
+}
+int
+sigrelse(int sig)
+{
+	sigset_t set;
+
+	sigemptyset(&set);
+	sigaddset(&set, sig);
+	return (_sigprocmask(SIG_UNBLOCK, &set, NULL));
+}
+
 int rpmsqIsCaught(int signum)
 {
     return sigismember(&rpmsqCaught, signum);
