--- rpmio/rpmsq.c.orig	2010-07-02 12:27:50.000000000 +0200
+++ rpmio/rpmsq.c	2010-07-02 12:27:53.000000000 +0200
@@ -75,6 +75,25 @@ static struct rpmsqElem rpmsqRock;
 
 static rpmsq rpmsqQueue = &rpmsqRock;
 
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
 /** \ingroup rpmsq
  * Insert node into from queue.
  * @param elem          node to link
