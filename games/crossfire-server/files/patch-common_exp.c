--- common/exp.c.orig	2014-04-05 22:30:50 UTC
+++ common/exp.c
@@ -209,7 +209,7 @@ void init_experience(void) {
                 exit(1);
             }
 
-            tmpexp = atoll(cp);
+            tmpexp = strtoll(cp, (char **)NULL, 10);
             /* Do some sanity checking - if value is bogus, just exit because
              * the table otherwise is probably in an inconsistent state
              */
