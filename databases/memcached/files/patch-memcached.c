--- memcached.c.orig	Tue Jul 29 22:43:57 2003
+++ memcached.c	Thu Aug 21 11:18:45 2003
@@ -34,7 +34,6 @@
 #include <errno.h>
 #include <time.h>
 #include <event.h>
-#include <malloc.h>
 #include <assert.h>
 
 #include "memcached.h"
@@ -314,26 +313,6 @@
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
@@ -1114,7 +1093,6 @@
     printf("-d            run as a daemon\n");
     printf("-m <num>      max memory to use for items in megabytes, default is 64 MB\n");
     printf("-c <num>      max simultaneous connections, default is 1024\n");
-    printf("-k            lock down all paged memory\n");
     printf("-v            verbose (print errors/warnings while in event loop)\n");
     printf("-h            print this help and exit\n");
     printf("-i            print memcached and libevent license\n");
@@ -1198,7 +1176,6 @@
     int c;
     conn *l_conn;
     struct in_addr addr;
-    int lock_memory = 0;
     int daemonize = 0;
 
     /* init settings */
@@ -1222,9 +1199,6 @@
         case 'i':
             usage_license();
             exit(0);
-        case 'k':
-            lock_memory = 1;
-            break;
         case 'v':
             settings.verbose = 1;
             break;
@@ -1261,11 +1235,6 @@
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
