--- src/fe-text/gui-readline.c.orig	Sun Nov 23 20:30:02 2003
+++ src/fe-text/gui-readline.c	Sun Dec  7 16:35:50 2003
@@ -53,6 +53,9 @@
 static ENTRY_REDIRECT_REC *redir;
 static int escape_next_key;
 
+static int big5high = FALSE;
+static unichar prekey = '\0';
+
 static int readtag;
 static unichar prev_key;
 static GTimeVal last_keypress;
@@ -339,7 +342,25 @@
 		return;
 	}
 
-	if (key < 32) {
+	if(big5high || is_big5_hi(key))
+	{
+		if(big5high)
+		{
+			big5high = FALSE;
+			str[0] = prekey;
+			str[1] = key;
+			str[2] = '\0';
+			gui_entry_insert_text(active_entry, str);
+			return;
+		}
+		else
+		{
+			big5high = TRUE;
+			prekey = key;
+			return;
+		}
+	}
+	else if (key < 32) {
 		/* control key */
                 str[0] = '^';
 		str[1] = (char)key+'@';
