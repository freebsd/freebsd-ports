--- src/testgame.c~	Sun Nov 21 21:00:23 2004
+++ src/testgame.c	Sun Nov 21 21:01:21 2004
@@ -42,14 +42,12 @@
 {
 	GtkWidget *vbox,*hbox,*h_line;
 	GtkWidget *text_label,*xpm_label;
+	gchar temp[10];
 
 	// init
 	r_num=0;w_num=0;t_num=0;
 	counter = S_conf.test_counter;
 
-	gchar temp[10];
-	
-
 /* test window */
 	test_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_window_set_title(GTK_WINDOW(test_win),"Test Game");
@@ -262,7 +260,6 @@
 //test start
 static void test_start()
 {
-	g_print("start button clicked!\n");
 
 	// clean up
 	//gtk_entry_set_text(GTK_ENTRY(input_entry),"");
@@ -271,6 +268,7 @@
 	//gchar temp[10];
 	gchar prompt_str[256];
 	
+	g_print("start button clicked!\n");
 	randnum = rand() % word_count;// 0< random num < word_count
 	S_state.word_index = randnum;
 	
@@ -391,12 +389,12 @@
 //test counter  over,show result
 static void test_over()
 {
-	g_print("counter over!\n");
 
 	gchar str[256];
 	gchar temp[256];
 	float percent;
 	
+	g_print("counter over!\n");
 	if(t_num == 0)
 		percent = 0.0000;
 	else
