--- src/qrunner/qrunner.cxx.orig	2014-10-14 21:19:37.000000000 -0400
+++ src/qrunner/qrunner.cxx	2014-10-24 14:39:00.000000000 -0400
@@ -103,7 +103,7 @@
 		return;
 	qr->inprog = true;
 
-	size_t n = QRUNNER_READ(fd, rbuf, FIFO_SIZE);
+	ssize_t n = QRUNNER_READ(fd, rbuf, FIFO_SIZE);
 	switch (n) {
 	case -1:
 		if (!QRUNNER_EAGAIN()) {
