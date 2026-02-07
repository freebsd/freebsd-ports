--- X-widget.c.orig
+++ X-widget.c
@@ -248,6 +248,11 @@
 	exit(EXIT_FAILURE);
     }
 
+    if (p->xpmdir && strlen(p->xpmdir) >= MAXXPMDIRLEN) {
+        fprintf(stderr, "directory too long\n");
+        exit(1);
+    }
+
     read_message_file(p->messagefile ? p->messagefile : "messages");
     read_keyboard_file(p->keyboardfile ? p->keyboardfile : "keys");
 
