--- src/io.c.orig	2020-08-06 17:06:40 UTC
+++ src/io.c
@@ -136,13 +136,13 @@ void
 int io_stop = 0;
 
 void
-io_signal()
+io_signal(int signo)
 {
 	io_stop = 1;
 }
 
 void
-io_signal_on()
+io_signal_on(void)
 {
 	io_stop = 0;
 	signal(SIGINT, io_signal);
@@ -150,7 +150,7 @@ void
 }
 
 void
-io_signal_off()
+io_signal_off(void)
 {
 	signal(SIGINT, SIG_DFL);
 	signal(SIGPIPE, SIG_DFL);
