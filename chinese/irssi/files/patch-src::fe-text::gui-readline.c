--- src/fe-text/gui-readline.c.orig	Mon Nov 11 15:00:02 2002
+++ src/fe-text/gui-readline.c	Tue Apr  1 09:47:02 2003
@@ -50,6 +50,10 @@
 static ENTRY_REDIRECT_REC *redir;
 static int escape_next_key;
 
+static int big5high = FALSE;
+static unichar prekey = '\0';
+
+
 static int readtag;
 static time_t idle_time;
 
@@ -148,7 +152,25 @@
 
 	idle_time = time(NULL);
 
-	if (key < 32) {
+        if(big5high || is_big5_hi(key))
+        {
+          if(big5high)
+          {
+            big5high = FALSE;
+            str[0] = prekey;
+            str[1] = key;
+            str[2] = '\0';
+            gui_entry_insert_text(active_entry, str);
+            return;
+          }
+          else
+          {
+            big5high = TRUE;
+            prekey = key;
+            return;
+          }
+        }
+	else if (key < 32) {
 		/* control key */
                 str[0] = '^';
 		str[1] = (char)key+'@';
