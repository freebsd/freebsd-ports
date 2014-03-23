--- Eris/PollDefault.cpp.orig	2014-03-10 19:29:37.000000000 +0100
+++ Eris/PollDefault.cpp	2014-03-10 19:29:49.000000000 +0100
@@ -77,7 +77,7 @@
 
 	if (!got_data) return;
 
-	struct timeval timeout = {msec_timeout / 1000, (msec_timeout % 1000) * 1000};
+	struct timeval timeout = {(long)msec_timeout / 1000, ((long)msec_timeout % 1000) * 1000};
 	int retval = select(maxfd+1, &reading, &writing, &exceptions, &timeout);
 	if (retval < 0) {
         warning() << "select() returned error: " << retval;
