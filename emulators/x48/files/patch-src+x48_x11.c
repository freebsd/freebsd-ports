--- src/x48_x11.c.orig	Thu Sep  9 01:05:58 1999
+++ src/x48_x11.c	Sat Jun 28 20:55:35 2003
@@ -4108,6 +4108,7 @@
       break;
     case XK_KP_Add:
     case XK_plus:
+    case XK_equal:
       key_event(BUTTON_PLUS, xev);
       wake = 1;
       break;
@@ -4168,6 +4169,8 @@
       break;
     case XK_Alt_L:
     case XK_Alt_R:
+    case XK_Meta_L:
+    case XK_Meta_R:
       key_event(BUTTON_ALPHA, xev);
       wake = 1;
       break;
