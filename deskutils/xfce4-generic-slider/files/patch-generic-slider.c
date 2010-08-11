--- ./generic-slider.c.orig	2010-06-04 23:25:59.000000000 +0200
+++ ./generic-slider.c	2010-08-11 19:55:41.000000000 +0200
@@ -162,15 +162,15 @@
 	arglist[num_args - 1] = NULL;
 	
 	/* Forks */
-	
+
 	pid = fork();
-	if (pid == -1) {
-		fprintf(stderr, "Could not fork a new process\n");
-	} else if (pid == 0) {
+	if(pid==0) {
+		wait();
+	} else {
 		execvp(arglist[0], arglist);
 		perror("execvp");
-		_exit(-1);
 	}
+
 }
 
 static gint scroll_slider_cb(GtkWidget *widget, GdkEventScroll *event, GList *stupid_hack) {
