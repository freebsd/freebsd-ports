--- src/wordfile.c~	Sun Nov 21 21:01:43 2004
+++ src/wordfile.c	Sun Nov 21 21:02:37 2004
@@ -44,12 +44,11 @@
 //read wordfile to wordbook[][],10000 words limition 
 void init_wordbook()
 {
+	gchar * strtemp;//temp string
+	gchar  str[256];//temp string
 	word_count = 0;
 	S_state.word_index = 0;	
 
-	gchar * strtemp;//temp string
-	gchar  str[256];//temp string
-	
 	g_print("init wordbook!\n");
 
 	//open word file
@@ -91,16 +90,14 @@
 //get S_line from wordfile
 void read_line()
 {
+	gchar line[256],EN_word[256],TK_word[256],CH_word[256],*p;
+	gint n;// count for line
+
 	if(S_state.word_index <= 0 )
 		gtk_widget_set_sensitive(back_button,0);
 	else
 		gtk_widget_set_sensitive(back_button,1);
 	
-
-	gchar line[256],EN_word[256],TK_word[256],CH_word[256],*p;
-	
-	gint n;// count for line
-
 	// '#' is special char defined by me,to show TK_word is end
 	TK_word[0]='#';
 
