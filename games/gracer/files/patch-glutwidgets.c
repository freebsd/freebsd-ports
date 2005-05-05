--- src/glutwidgets.c.orig	Wed May  4 18:47:07 2005
+++ src/glutwidgets.c	Wed May  4 18:48:56 2005
@@ -254,7 +254,6 @@
 	widget->x -= (width - screen_width) / 2;
 	widget->width += (width - screen_width);
 	break;
-      default:
       }
       switch (widget->anchor & GR_VERTICAL_MASK) {
       case GR_BOTTOM:
@@ -267,7 +266,6 @@
 	widget->y -= (height - screen_height) / 2;
 	widget->height += (width - screen_height);
 	break;
-      default:
       }
       glut_widget_calc_bbox (widget);
     }
@@ -325,8 +323,6 @@
 	glut_widget_set_focus (glut_next_focus_widget (NULL));
       }
       break;
-
-    default:
     }
   }
 
@@ -502,8 +498,6 @@
 	glut_widget_set_focus (widget);
       }
       break;
-
-    default:
     }
   }
 
@@ -1297,8 +1291,6 @@
     }
     glut_post_redisplay ();
     break;
-
-  default:
   }
 }
 
@@ -1569,8 +1561,6 @@
     case GR_RIGHT:
       width = glut_label_width (obj) / 2;
       break;
-
-    default:
     }
 
     glColor4fv (widget->fg_color[GR_STATE_NORMAL]);
