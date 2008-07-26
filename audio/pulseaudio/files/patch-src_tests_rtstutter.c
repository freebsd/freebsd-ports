--- src/tests/rtstutter.c.orig	2008-07-26 17:10:17.000000000 -0400
+++ src/tests/rtstutter.c	2008-07-26 17:12:26.000000000 -0400
@@ -42,6 +42,7 @@ static int msec_lower, msec_upper;
 static void* work(void *p) PA_GCC_NORETURN;
 
 static void* work(void *p) {
+#ifndef __FreeBSD__
     cpu_set_t mask;
     struct sched_param param;
 
@@ -83,6 +84,7 @@ static void* work(void *p) {
         } while (now.tv_sec < end.tv_sec ||
                  (now.tv_sec == end.tv_sec && now.tv_nsec < end.tv_nsec));
     }
+#endif
 }
 
 int main(int argc, char*argv[]) {
