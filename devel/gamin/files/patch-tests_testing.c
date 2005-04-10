--- tests/testing.c.orig	Fri Apr  8 15:09:45 2005
+++ tests/testing.c	Fri Apr  8 15:09:57 2005
@@ -424,9 +424,9 @@
             return (-1);
         }
         /*
-         * wait at most 3 secs before declaring failure
+         * wait at most 7 secs before declaring failure
          */
-        while ((delay < 30) && (testState.nb_events < nb_events + count)) {
+        while ((delay < 70) && (testState.nb_events < nb_events + count)) {
             debugLoop(100);
 
 /*	    printf("+"); fflush(stdout); */
