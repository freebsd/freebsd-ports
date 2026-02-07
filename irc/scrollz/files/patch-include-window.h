--- include/window.h.orig	2021-05-06 08:04:55 UTC
+++ include/window.h
@@ -42,7 +42,7 @@
  * CREATE, that allows you to start new iscreen or xterm windows
  * connected to the ircII client.
  */
-#undef	WINDOW_CREATE
+#define	WINDOW_CREATE
 
 #if defined(M_UNIX) || !defined(HAVE_SYS_UN_H)
 #undef WINDOW_CREATE
