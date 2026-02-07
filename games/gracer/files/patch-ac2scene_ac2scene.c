--- ac2scene/ac2scene.c.orig	2000-03-01 04:26:42 UTC
+++ ac2scene/ac2scene.c
@@ -160,8 +160,6 @@ check_triangle_strip (GrSceneOptHint *hint, GrSurface 
       return 1;
     }
     break;
-
-  default:
   }
 
   return 0;
@@ -232,8 +230,6 @@ check_triangle_fan (GrSceneOptHint *hint, GrSurface *s
       return 1;
     }
     break;
-
-  default:
   }
 
   return 0;
@@ -315,7 +311,6 @@ check_quad_strip (GrSceneOptHint *hint, GrSurface *sur
       return 1;
     }
     break;
-  default:
   }
 
   return 0;
@@ -397,8 +392,6 @@ optimize_object (GrObject *obj,
       hints[i]->state = GR_SCENE_OPT_QUAD_STRIP_START;
       hints[i]->surf->elements = gr_new (GrSElement, num_quads * 2 + 2);
       break;
-
-    default:
     }
   }
 
