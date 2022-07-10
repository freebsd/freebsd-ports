--- win/tty/wintty.c.orig	2022-07-10 13:13:39 UTC
+++ win/tty/wintty.c
@@ -1555,7 +1555,8 @@ boolean free_data;
     int i;
 
     if (cw->data) {
-        if (cw == wins[WIN_MESSAGE] && cw->rows > cw->maxrow)
+        if (WIN_MESSAGE != WIN_ERR && cw == wins[WIN_MESSAGE]
+            && cw->rows > cw->maxrow)
             cw->maxrow = cw->rows; /* topl data */
         for (i = 0; i < cw->maxrow; i++)
             if (cw->data[i]) {
