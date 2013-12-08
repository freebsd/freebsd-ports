--- src/qrunner/qrunner.cxx.orig	2013-11-19 10:58:52.118170777 -0500
+++ src/qrunner/qrunner.cxx	2013-11-19 11:00:04.670568086 -0500
@@ -94,7 +94,7 @@
 		return;
 	qr->inprog = true;
 
-	size_t n = QRUNNER_READ(fd, rbuf, FIFO_SIZE);
+	ssize_t n = QRUNNER_READ(fd, rbuf, FIFO_SIZE);
 	switch (n) {
 	case -1:
 		if (!QRUNNER_EAGAIN())
