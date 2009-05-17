--- eve.c.orig	2009-05-17 17:08:46.000000000 +0800
+++ eve.c	2009-05-17 17:09:22.000000000 +0800
@@ -595,9 +595,11 @@
 #endif
     case 10:
       break;
+#if USE_ANTHY
     case 12:
       get_win_anthy_geom();
       break;
+#endif
     default:
       get_win_gtab_geom();
       break;
