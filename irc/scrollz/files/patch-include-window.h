--- include/window.h.orig	2011-04-29 17:21:18.000000000 +0900
+++ include/window.h	2013-03-09 18:47:08.841093765 +0900
@@ -42,7 +42,7 @@
  * CREATE, that allows you to start new iscreen or xterm windows
  * connected to the ircII client.
  */
-#undef	WINDOW_CREATE
+#define	WINDOW_CREATE
 
 #if defined(M_UNIX) || !defined(HAVE_SYS_UN_H)
 #undef WINDOW_CREATE
