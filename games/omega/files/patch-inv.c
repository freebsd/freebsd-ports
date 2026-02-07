--- inv.c.orig	2021-11-11 18:12:35.355855000 -0500
+++ inv.c	2021-11-11 18:13:11.096005000 -0500
@@ -8,7 +8,11 @@
 # ifdef AMIGA
 #  include <curses210.h>
 # else
-#  include <curses.h>
+#  ifdef __FreeBSD__
+#   include <ncurses.h>
+#  else
+#   include <curses.h>
+#  endif
 # endif
 #endif
 
@@ -840,8 +844,7 @@
       use_pack_item(response - 'a',slot);
     }
   }
-  if ( optionp(TOPINV) )
-    display_possessions();
+  display_possessions();
   return slot;
 }
 
