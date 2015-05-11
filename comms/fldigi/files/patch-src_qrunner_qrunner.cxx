--- src/qrunner/qrunner.cxx.orig	2015-03-21 00:29:04 UTC
+++ src/qrunner/qrunner.cxx
@@ -103,7 +103,7 @@ void qrunner::execute(int fd, void *arg)
 		return;
 	qr->inprog = true;
 
-	size_t n = QRUNNER_READ(fd, rbuf, FIFO_SIZE);
+	ssize_t n = QRUNNER_READ(fd, rbuf, FIFO_SIZE);
 	switch (n) {
 	case -1:
 		if (!QRUNNER_EAGAIN()) {
