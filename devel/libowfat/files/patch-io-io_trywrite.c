! fix a possible signal handling race condition
! obtained from libowfat cvs
--- io/io_trywrite.c	27 Feb 2004 17:04:03 -0000	1.5
+++ io/io_trywrite.c	7 Mar 2004 21:48:56 -0000	1.6
@@ -22,7 +22,7 @@
 	    e->next_write=-1;
 	    return -1;
     }
-    new.it_interval.tv_usec=0;
+    new.it_interval.tv_usec=10000;
     new.it_interval.tv_sec=0;
     new.it_value.tv_usec=10000;
     new.it_value.tv_sec=0;
