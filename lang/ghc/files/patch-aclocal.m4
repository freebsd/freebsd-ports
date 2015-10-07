--- aclocal.m4.orig	2015-07-21 13:52:50 UTC
+++ aclocal.m4
@@ -1718,36 +1718,6 @@ int main(int argc, char *argv[])
     }
     alarm(1);
 
-    if (timer_create(CLOCK_PROCESS_CPUTIME_ID, &ev, &timer) != 0) {
-        fprintf(stderr,"No CLOCK_PROCESS_CPUTIME_ID timer\n");
-       exit(1);
-    }
-
-    it.it_value.tv_sec = 0;
-    it.it_value.tv_nsec = 1;
-    it.it_interval = it.it_value;
-    if (timer_settime(timer, 0, &it, NULL) != 0) {
-        fprintf(stderr,"settime problem\n");
-        exit(4);
-    }
-
-    tock = 0;
-
-    for(n = 3; n < 20000; n++){
-        for(m = 2; m <= n/2; m++){
-            if (!(n%m)) count++;
-            if (tock) goto out;
-        }
-    }
-out:
-
-    if (!tock) {
-        fprintf(stderr,"no CLOCK_PROCESS_CPUTIME_ID signal\n");
-        exit(5);
-    }
-
-    timer_delete(timer);
-
     if (timer_create(CLOCK_REALTIME, &ev, &timer) != 0) {
         fprintf(stderr,"No CLOCK_REALTIME timer\n");
         exit(2);
