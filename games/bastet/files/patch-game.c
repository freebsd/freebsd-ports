diff -ru game.c bastet-0.41/game.c
--- game.c	Sat Dec 18 00:28:00 2004
+++ bastet-0.41/game.c	Sat Dec 18 00:56:26 2004
@@ -12,6 +12,9 @@
 #include "game.h"
 #include "main.h"
 #include "bast.h"
+#include <sys/select.h>
+
+void bast_clear();
 
 const DOT block_data[BLOCK_TYPES][BLOCK_ORIENTS][BLOCK_DOTS] =
 {
@@ -66,7 +70,7 @@
 
 /* Delay before block drop one step down (usec).
    We start at one sec. and then decreases the delay by 23% at each level. */
-const int delay[NO_LEVELS] = {1000000, 770000, 593000, 457000, 352000, 271000, 208000, 160000, 124000, 95000};
+const int delay[NO_LEVELS] = {999999, 770000, 593000, 457000, 352000, 271000, 208000, 160000, 124000, 95000};
 
 /* Window in which the action takes place. */
 WINDOW *well_win;
@@ -278,6 +282,7 @@
         refresh();
 }
 
+struct timeval mytimeout;
 /* Drop a block in the well. When done return y-cord. of where block
    ended. If it's not possible to even start with a new block return -1. */
 int drop_block(int type, int level)
@@ -288,14 +293,13 @@
         int orient = 0;
         int ch;
         fd_set inputs, test_fds;
-        struct timeval timeout;
         int sel_ret;
 
         if (0 == check_block_pos(y, x, type, orient))
                 return -1;      /* Oh no, game over. */
 
-        timeout.tv_sec = 0;
-        timeout.tv_usec = delay[level];
+        mytimeout.tv_sec = 0;
+        mytimeout.tv_usec = delay[level];
 
         FD_ZERO(&inputs);
         FD_SET(0, &inputs);
@@ -308,7 +312,7 @@
         while(1) {
                 test_fds = inputs;
 
-                sel_ret = select(FD_SETSIZE, &test_fds, (fd_set *) 0, (fd_set *) 0, &timeout);
+                sel_ret = select(FD_SETSIZE, &test_fds, (fd_set *) 0, (fd_set *) 0, &mytimeout);
 
                 ch = getch();
 
@@ -391,8 +402,8 @@
                                 set_block(y, x, type, orient);
                                 return y;
                         }
-                        timeout.tv_sec = 0;
-                        timeout.tv_usec = delay[level];
+                        mytimeout.tv_sec = 0;
+                        mytimeout.tv_usec = delay[level];
                 }
         }
 }
