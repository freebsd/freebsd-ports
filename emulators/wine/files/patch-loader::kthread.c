Index: loader/kthread.c
===================================================================
RCS file: /home/wine/wine/loader/kthread.c,v
retrieving revision 1.2
diff -u -3 -p -r1.2 kthread.c
--- loader/kthread.c	9 Nov 2003 01:25:23 -0000	1.2
+++ loader/kthread.c	25 Dec 2003 18:24:15 -0000
@@ -300,7 +300,7 @@ int wine_pthread_create_thread( struct w
             "ret;\n"
             "1:\n\t"                    /* parent -> caller thread */
             "addl $8,%%esp" :
-            : "r" (sp), "g" (SYS_rfork), "g" (RFPROC | RFMEM)
+            : "r" (sp), "g" (SYS_rfork), "g" (RFPROC | RFMEM | RFTHREAD)
             : "eax", "edx");
         return 0;
     }
