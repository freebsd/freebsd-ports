--- badguy.c.orig	2001-03-16 00:44:30 UTC
+++ badguy.c
@@ -20,7 +20,7 @@ int badscore;            /* Score given during current
                          /* killing bad guys */
  
 /* Graphics cursors for drawing the possible states of the badguys */
-GC badguy1gc,badguy2gc,badguy3gc;
+extern GC badguy1gc,badguy2gc,badguy3gc;
  
 /* Initialize data structure for bad guys from level data */
 void start_badguy()
@@ -421,6 +421,7 @@ void move_badguys()
       case RIGHT: dir = LEFT;  break;
       case UP:    dir = DOWN;  break;
       case DOWN:  dir = UP;    break;
+      case UNMOVE: case STAND: case DIGLEFT: case DIGRIGHT: case PUTDOWN: break;
       }
     
     /* Execute computed movement. */
