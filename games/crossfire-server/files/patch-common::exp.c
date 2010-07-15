--- common/exp.c.orig	2010-04-26 15:23:21.000000000 +0900
+++ common/exp.c	2010-05-25 04:22:52.000000000 +0900
@@ -224,7 +224,7 @@
                 exit(1);
             }
 
-            tmpexp = atoll(cp);
+            tmpexp = strtoll(cp, (char **)NULL, 10);
             /* Do some sanity checking - if value is bogus, just exit because
              * the table otherwise is probably in an inconsistent state
              */
