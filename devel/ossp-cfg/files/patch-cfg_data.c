--- cfg_data.c.orig	Sun Jul 28 07:06:02 2002
+++ cfg_data.c	Mon Feb  3 15:15:12 2003
@@ -186,7 +186,7 @@
             break;
         }
         case CFG_DATA_ATTR_CTRL: {
-            cfg_data_cb_t ctrl = (cfg_data_cb_t)va_arg(ap, void (*)(void));
+            cfg_data_cb_t ctrl = (cfg_data_cb_t)va_arg(ap, void *);
             data->ctrl = ctrl;
             break;
         }
