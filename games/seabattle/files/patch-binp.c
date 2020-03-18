--- binp.c.orig	1997-05-13 17:51:00 UTC
+++ binp.c
@@ -42,7 +42,7 @@ void printxy(int x,int y,char *tempst)     /* Simple f
 }
 
 
-void exit_curses(void)                     /* Shutdown curses nicely so the */
+void exit_curses_(void)                     /* Shutdown curses nicely so the */
 {                                          /* terminal works properly */
    clear();
    refresh();
@@ -129,15 +129,15 @@ void do_sound(int which_one)               /* Plays ap
                                            /* Incomplete as of yet */
    if (which_one==1) 
       if (sound_device) 
-         if(rand()%2) system("cat hit1.au > /dev/audio ");
-         else system("cat hit2.au > /dev/audio ");
+         if(rand()%2) system("cat " DATADIR "/hit1.au > /dev/audio ");
+         else system("cat " DATADIR "/hit2.au > /dev/audio ");
       else beep();
    if (which_one==2)
       if (sound_device)
-         if(rand()%2) system("cat miss1.au > /dev/audio ");
-         else system("cat miss2.au > /dev/audio ");
+         if(rand()%2) system("cat " DATADIR "/miss1.au > /dev/audio ");
+         else system("cat " DATADIR "/miss2.au > /dev/audio ");
    if (which_one==3) 
-      if (sound_device) system("cat sunkit.au > /dev/audio ");
+      if (sound_device) system("cat " DATADIR "/sunkit.au > /dev/audio ");
       else beep();
 }
 
@@ -330,7 +330,7 @@ void quit(void)                            /* Create a
    wclear(quit_window);
    wrefresh(quit_window);
    delwin(quit_window);
-   if ((ch=='Y') || (ch=='y')) {exit_curses(); exit(0); }
+   if ((ch=='Y') || (ch=='y')) {exit_curses_(); exit(0); }
 #ifndef BROKEN_CURSES
    redrawwin(stdscr);
 #endif
