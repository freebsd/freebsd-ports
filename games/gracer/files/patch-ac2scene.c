--- ac2scene/ac2scene.c.orig	Fri Apr  1 18:36:19 2005
+++ ac2scene/ac2scene.c	Fri Apr  1 18:36:48 2005
@@ -160,8 +160,6 @@
       return 1;
     }
     break;
-
-  default:
   }
 
   return 0;
@@ -232,8 +230,6 @@
       return 1;
     }
     break;
-
-  default:
   }
 
   return 0;
@@ -315,7 +311,6 @@
       return 1;
     }
     break;
-  default:
   }
 
   return 0;
@@ -397,8 +392,6 @@
       hints[i]->state = GR_SCENE_OPT_QUAD_STRIP_START;
       hints[i]->surf->elements = gr_new (GrSElement, num_quads * 2 + 2);
       break;
-
-    default:
     }
   }
 
