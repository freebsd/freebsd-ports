$NetBSD: patch-an,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_termsize.c.orig	2008-03-19 00:44:12.000000000 +0000
+++ src/libmojave-external/cutil/lm_termsize.c
@@ -45,7 +45,7 @@ value caml_term_size(value arg)
     CAMLlocal1(buf);
 
     /* Return a pair of numbers */
-    buf = alloc_small(2, 0);
+    buf = caml_alloc_small(2, 0);
 
     /* Get the terminal size, return None on failure */
 #ifdef WIN32
@@ -53,7 +53,7 @@ value caml_term_size(value arg)
         HANDLE fd = *(HANDLE *)Data_custom_val(arg);
         CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
         if (! GetConsoleScreenBufferInfo(fd, &ConsoleInfo))
-            failwith("lm_termsize.c: caml_term_size: GetConsoleScreenBufferInfo failed");
+            caml_failwith("lm_termsize.c: caml_term_size: GetConsoleScreenBufferInfo failed");
 
         Field(buf, 0) = Val_int(ConsoleInfo.dwSize.Y);
         Field(buf, 1) = Val_int(ConsoleInfo.dwSize.X);
@@ -65,7 +65,7 @@ value caml_term_size(value arg)
         struct winsize ws;
 
         if(ioctl(fd, TIOCGWINSZ, &ws) < 0)
-            failwith("lm_termsize.c: caml_term_size: not a terminal");
+            caml_failwith("lm_termsize.c: caml_term_size: not a terminal");
     
         /* Return the pair of numbers */
         Field(buf, 0) = Val_int(ws.ws_row);
