! fix a possible signal handling race condition
! obtained from libowfat cvs
--- io/io_tryread.c	7 Nov 2003 22:11:30 -0000	1.4
+++ io/io_tryread.c	7 Mar 2004 21:48:56 -0000	1.5
@@ -21,7 +21,7 @@
 	    e->next_read=-1;
 	    return -1;
     }
-    new.it_interval.tv_usec=0;
+    new.it_interval.tv_usec=10000;
     new.it_interval.tv_sec=0;
     new.it_value.tv_usec=10000;
     new.it_value.tv_sec=0;
