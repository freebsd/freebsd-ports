--- src/mq.c.orig	Sun Jun 20 20:21:26 2004
+++ src/mq.c	Sun Jun 20 21:58:03 2004
@@ -440,15 +440,30 @@
 
 static gboolean round_entries_desensitize_timeout(gpointer data)
 {
-	gint32 i = 0;
+	int i;
+	int entries_left = 0;
+	int n;
+	int j = 0;
 
-	do {
-		i = g_random_int_range(0,5);
-	} while (round_entries_sensitive[i] == FALSE || i == round_answer);
-
-	round_entries_sensitive[i] = FALSE;
-	gtk_widget_set_sensitive(GTK_WIDGET(game_buttons[i]),FALSE);
+	for (i = 0; i < 5; i++)
+		if (round_entries_sensitive[i] && i != round_answer)
+			entries_left++;
 
+	if (entries_left == 0) {
+		round_entries_desensitize_timeout_id = -1;
+		return FALSE;
+	}
+	
+	n = g_random_int_range(0, entries_left);
+	for (i = 0; i < 5; i++)
+		if (round_entries_sensitive[i] && i != round_answer) {
+			if (j++ == n) {
+				round_entries_sensitive[i] = FALSE;
+				gtk_widget_set_sensitive(GTK_WIDGET(game_buttons[i]), FALSE);
+				break;
+			}
+		}
+	      
 	return TRUE;
 }
 
