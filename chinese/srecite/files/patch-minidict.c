--- src/minidict.c~	Sun Nov 21 20:58:43 2004
+++ src/minidict.c	Sun Nov 21 21:00:12 2004
@@ -195,12 +195,12 @@
 int do_CH_search(gchar word[256],int begin,int end)
 {
 
-	g_print("CH search \n");
 	int i ;
 	int flag=0;
 	
 	//init 0
 	CH_line_index = 0;	
+	g_print("CH search \n");
 
 	for(i=begin;i<=end;i++)
 	{
@@ -228,12 +228,12 @@
 //search EN successfully,show result
 void dict_show_EN_success()
 {
-	g_print("search successfully !\n");
 	gchar  result_str[256];
 	gchar  ps1_str[256];
 	gchar  ps2_str[256];
 	gchar  ps3_str[256];
 	
+	g_print("search successfully !\n");
 	strcpy(result_str,"");
 	strcpy(ps1_str,"");
 	strcpy(ps2_str,"");
@@ -260,13 +260,13 @@
 //search CH successfully,show result
 void dict_show_CH_success()
 {
-	g_print("search successfully !\n");
 	int i;
 	struct line_st myline;
 	
 	gchar  result_str[256];
 	gchar  ps1_str[256];
 	
+	g_print("search successfully !\n");
 	strcpy(result_str,"");
 	strcpy(ps1_str,"");
 	
@@ -315,11 +315,10 @@
 //search dict
 static void dict_search()
 {
-	g_print("dict search!!\n");
 	gchar word[256];
 	int flag;
 	
-	
+	g_print("dict search!!\n");
 	strcpy(word,gtk_entry_get_text(GTK_ENTRY(input_entry)));
 	
 	if( (word[0] & 0x80) == 0x80 )
