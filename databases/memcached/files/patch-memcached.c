--- memcached.c.orig	Mon Jul 21 22:56:55 2003
+++ memcached.c	Mon Jul 21 22:58:46 2003
@@ -34,7 +34,6 @@
 #include <errno.h>
 #include <time.h>
 #include <event.h>
-#include <malloc.h>
 #include <assert.h>
 
 #include "memcached.h"
@@ -293,26 +292,6 @@
         return;
     }
 
-    if (strcmp(command, "stats malloc") == 0) {
-        char temp[512];
-        struct mallinfo info;
-        char *pos = temp;
-
-        info = mallinfo();
-        pos += sprintf(pos, "STAT arena_size %d\r\n", info.arena);
-        pos += sprintf(pos, "STAT free_chunks %d\r\n", info.ordblks);
-        pos += sprintf(pos, "STAT fastbin_blocks %d\r\n", info.smblks);
-        pos += sprintf(pos, "STAT mmapped_regions %d\r\n", info.hblks);
-        pos += sprintf(pos, "STAT mmapped_space %d\r\n", info.hblkhd);
-        pos += sprintf(pos, "STAT max_total_alloc %d\r\n", info.usmblks);
-        pos += sprintf(pos, "STAT fastbin_space %d\r\n", info.fsmblks);
-        pos += sprintf(pos, "STAT total_alloc %d\r\n", info.uordblks);
-        pos += sprintf(pos, "STAT total_free %d\r\n", info.fordblks);
-        pos += sprintf(pos, "STAT releasable_space %d\r\nEND", info.keepcost);
-        out_string(c, temp);
-        return;
-    }
-
     if (strcmp(command, "stats maps") == 0) {
         char *wbuf;
         int wsize = 8192; /* should be enough */
@@ -1089,7 +1068,6 @@
     printf("-d            run as a daemon\n");
     printf("-m <num>      max memory to use for items in megabytes, default is 64 MB\n");
     printf("-c <num>      max simultaneous connections, default is 1024\n");
-    printf("-k            lock down all paged memory\n");
     printf("-v            verbose (print errors/warnings while in event loop)\n");
     printf("-h            print this help and exit\n");
     printf("-i            print memcached and libevent license\n");
@@ -1236,11 +1214,6 @@
             fprintf(stderr, "failed to daemon() in order to daemonize\n");
             return 1;
         }
-    }
-
-    /* lock paged memory if needed */
-    if (lock_memory) {
-        mlockall(MCL_CURRENT | MCL_FUTURE);
     }
 
     /* create the listening socket and bind it */
