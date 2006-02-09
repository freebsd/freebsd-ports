--- tests/testing.c.orig	Thu Oct 27 12:51:03 2005
+++ tests/testing.c	Tue Feb  7 08:10:40 2006
@@ -486,9 +486,9 @@
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
