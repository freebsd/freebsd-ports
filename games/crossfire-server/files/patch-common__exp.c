--- ./common/exp.c.orig	2012-03-18 07:31:50.000000000 +0100
+++ ./common/exp.c	2014-03-27 18:59:52.047466456 +0100
@@ -224,7 +224,7 @@
                 exit(1);
             }
 
-            tmpexp = atoll(cp);
+            tmpexp = strtoll(cp, (char **)NULL, 10);
             /* Do some sanity checking - if value is bogus, just exit because
              * the table otherwise is probably in an inconsistent state
              */
