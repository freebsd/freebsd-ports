--- src/tests/rtpoll-test.c.orig	2008-01-03 20:03:03.000000000 -0500
+++ src/tests/rtpoll-test.c	2008-01-03 20:03:25.000000000 -0500
@@ -45,6 +45,7 @@ static int worker(pa_rtpoll_item *w) {
 }
 
 int main(int argc, char *argv[]) {
+#ifdef SIGRTMIN
     pa_rtpoll *p;
     pa_rtpoll_item *i, *w;
     struct pollfd *pollfd;
@@ -86,6 +87,7 @@ int main(int argc, char *argv[]) {
     pa_rtpoll_item_free(w);
 
     pa_rtpoll_free(p);
+#endif
 
     return 0;
 }
