--- movement.c.orig	1991-04-02 06:46:54 UTC
+++ movement.c
@@ -426,6 +426,7 @@ int num;                            /* Number of bad g
         newdir = thing->dir;
     }
     break;
+  case STAND: case DIGLEFT: case DIGRIGHT: case UNMOVE: case PUTDOWN: break;
   }
 
   /* By default, the thing is standing in place */
@@ -498,6 +499,7 @@ int num;                            /* Number of bad g
       thing->dir = RIGHT;
     }
     break;
+  case STAND: case UNMOVE: break;
   }
   return(0);
 }
@@ -602,6 +604,7 @@ int num;                            /* Number of bad g
       thing->dir = RIGHT;
     }
     break;
+  case STAND: case DIGLEFT: case DIGRIGHT: case UNMOVE: case PUTDOWN: break;
   }
   return(0);
 }
