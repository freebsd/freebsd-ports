--- curses/cdraw.c.orig
+++ curses/cdraw.c
@@ -939,7 +939,7 @@
 	  mvaddstr(win->y + i, win->x, tmpbuf);
     } else {
 	printf("error: win %d is %dx%d @ %d,%d\n",
-	       (int) win, win->w, win->h, win->x, win->y);
+	       win, win->w, win->h, win->x, win->y);
     }
 }
 
