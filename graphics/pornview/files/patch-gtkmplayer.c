--- src/support/widgets/gtkmplayer.c.orig	Fri Dec 13 12:15:21 2002
+++ src/support/widgets/gtkmplayer.c	Sat May 17 15:04:45 2003
@@ -30,6 +30,7 @@
 #include <errno.h>
 #include <ctype.h>
 #include <math.h>
+#include <signal.h>
 
 #include <gtk/gtk.h>
 #include <gdk/gdkx.h>
@@ -72,9 +73,9 @@
     int     stderr_fd;
     int     stdin_fd;
 
-    gchar   stdout[GTK_MPLAYER_BUF_SIZE];
+    gchar   stdoutb[GTK_MPLAYER_BUF_SIZE];
     gint    stdout_size;
-    gchar   stderr[GTK_MPLAYER_BUF_SIZE];
+    gchar   stderrb[GTK_MPLAYER_BUF_SIZE];
     gint    stderr_size;
 
     ProcessLineFunc process_line_fn;
@@ -1049,13 +1050,13 @@
     context->stdout_fd = out_fd[0];
     fcntl (context->stdout_fd, F_SETFL, O_NONBLOCK);
     close (out_fd[1]);
-    context->stdout[0] = '\0';
+    context->stdoutb[0] = '\0';
     context->stdout_size = 0;
 
     context->stderr_fd = err_fd[0];
     fcntl (context->stderr_fd, F_SETFL, O_NONBLOCK);
     close (err_fd[1]);
-    context->stderr[0] = '\0';
+    context->stderrb[0] = '\0';
     context->stderr_size = 0;
 
     context->stdin_fd = in_fd[1];
@@ -1193,7 +1194,7 @@
 
     if (size > 0 && size < GTK_MPLAYER_BUF_SIZE)
     {
-	memcpy (buf, context->stderr, size);
+	memcpy (buf, context->stderrb, size);
 	next = buf + size;
     }
     else
@@ -1211,7 +1212,7 @@
 	size += MIN (GTK_MPLAYER_BUF_SIZE - 1, n);
 
 	process_lines (context, buf, size,
-		       context->stderr, &context->stderr_size, TRUE);
+		       context->stderrb, &context->stderr_size, TRUE);
     }
 
     /*
@@ -1221,7 +1222,7 @@
 
     if (size > 0 && size < GTK_MPLAYER_BUF_SIZE)
     {
-	memcpy (buf, context->stdout, size);
+	memcpy (buf, context->stdoutb, size);
 	next = buf + size;
     }
     else
@@ -1240,7 +1241,7 @@
     pos = context->player->pos;
 
     process_lines (context, buf, size,
-		   context->stdout, &context->stdout_size, FALSE);
+		   context->stdoutb, &context->stdout_size, FALSE);
 
     if (fabs (context->player->pos - pos) > 0.1)
 	gtk_signal_emit (GTK_OBJECT (context->player),
