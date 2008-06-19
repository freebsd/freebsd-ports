--- tcap.c
+++ tcap.c
@@ -89,7 +89,7 @@
 
 
 #ifdef BSD
-#ifdef ULTRIX
+#if 1
     if (ioctl (0, TIOCGWINSZ, &ttysize) == 0
 	&& ttysize.ws_row > 0)
     {
