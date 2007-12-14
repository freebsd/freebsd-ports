--- tricky/main.c.orig	2007-12-13 00:44:22.000000000 +0100
+++ tricky/main.c	2007-12-13 00:44:01.000000000 +0100
@@ -59,7 +59,7 @@
    VerboseOn = 1;
    }
 
-if ( Startup() != NULL ) /* Startup failed if it returns anything but NULL */
+if ( Startup() ) /* Startup failed if it returns anything but 0 */
    {
    printf("\nStartup Failed ... Exiting.\n");
    exit(1);
