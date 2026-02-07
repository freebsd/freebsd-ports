--- zotnet/mf/muinc.c.orig
+++ zotnet/mf/muinc.c
@@ -81,7 +81,6 @@
 {
     int     count,
             fd;
-    extern int  errno;
 
     for (count = 2; count > 0; count--)
 	if ((fd = lkopen (file, 1)) == NOTOK)
