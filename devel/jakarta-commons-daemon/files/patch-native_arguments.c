--- native/arguments.c.orig	2012-02-24 00:24:02.000000000 +0100
+++ native/arguments.c	2012-06-13 13:15:57.000000000 +0200
@@ -158,7 +158,7 @@
     args->help    = false;        /* Don't display help */
     args->chck    = false;        /* Don't do a check-only startup */
     args->stop    = false;        /* Stop a running jsvc */
-    args->wait    = 0;            /* Wait until jsvc has started the JVM */
+    args->wait    = 10;           /* Wait until jsvc has started the JVM */
     args->install = false;        /* Don't install as a service */
     args->remove  = false;        /* Don't remove the installed service */
     args->service = false;        /* Don't run as a service */
@@ -262,10 +262,6 @@
             temp = optional(argc, argv, x++);
             if (temp)
                 args->wait = atoi(temp);
-            if (args->wait < 10) {
-                log_error("Invalid wait time specified (min=10)");
-                return NULL;
-            }
         }
         else if (!strcmp(argv[x], "-umask")) {
             temp = optional(argc, argv, x++);
