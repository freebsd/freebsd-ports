--- rf/uwidget.cpp.orig	2003-01-14 19:07:42.000000000 +0100
+++ rf/uwidget.cpp	2007-11-22 20:06:28.000000000 +0100
@@ -231,23 +231,23 @@
 
 	static void gtkclicked(GtkButton *button, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		UEventSendMessage(widid, EV_CMD, cmdid, 0L);
 	}
 	
 	static void gtkmenuitemactivate(GtkMenuItem *menuitem, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		UEventSendMessage(widid, EV_CMD, cmdid, 0L);
 	}
 
 	static void gtkselectclist(GtkWidget *clist, gint row, gint column,
 							   GdkEventButton *event, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		gchar *text;
 		gtk_clist_get_text(GTK_CLIST(clist), row, column, &text);
 		UEventSendMessage(widid, EV_LIST_SELECTING, UMAKEINT(cmdid, row), text);
@@ -255,15 +255,15 @@
 
 	static void gtkselectclistcolumn(GtkCList *clist, gint column, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		UEventSendMessage(widid, EV_LIST_SELCOLUMN, UMAKEINT(cmdid, column), 0L);
 	}
 
 	static gint gtkclistdblclick(GtkWidget *widget, GdkEventButton *event, gpointer data)
 	{
-		int widid = ULOWORD((int)data);
-		int cmdid = UHIWORD((int)data);
+		int widid = ULOWORD((size_t)data);
+		int cmdid = UHIWORD((size_t)data);
 		if (event->type == GDK_2BUTTON_PRESS)
 		{
 			UEventSendMessage(widid, EV_LIST_DBLCLICK, cmdid, 0L);
@@ -274,8 +274,8 @@
 
 	static void gtkcomboclicked(GtkWidget *widget, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 
 		GtkList *list = GTK_LIST(widget->parent);
 		GList *selection = list->selection;
@@ -320,8 +320,8 @@
 
 	static void gtkmenuactivated(GtkWidget *widget, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 
 		UStr selTxt;
 
@@ -392,7 +392,7 @@
 	static void dataForeach(GQuark key_id, gpointer data, gpointer user_data)
 	{
 		const char *str = g_quark_to_string(key_id);
-		int id = (int)user_data;
+		size_t id = (size_t)user_data;
 		int cmd;
 		if(matchToken(str, cmd))
 		{
@@ -514,32 +514,32 @@
 
 	static void gtktreeexpand(GtkWidget *item, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		g_assert(GTK_IS_TREE_ITEM(item));
 		UEventSendMessage(widid, EV_TREE_EXPANDING, UMAKEINT(cmdid, 0), item);
 	}
 
 	static void gtktreecollapse(GtkWidget *item, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		g_assert(GTK_IS_TREE_ITEM(item));
 		UEventSendMessage(widid, EV_TREE_EXPANDING, UMAKEINT(cmdid, 1), item);
 	}
 
 	static void gtktreeselect(GtkWidget *item, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		g_assert(GTK_IS_TREE_ITEM(item));
 		UEventSendMessage(widid, EV_TREE_SELECTING, UMAKEINT(cmdid, 0), item);
 	}
 
 	static void gtktreedeselect(GtkWidget *item, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		g_assert(GTK_IS_TREE_ITEM(item));
 		UEventSendMessage(widid, EV_TREE_SELECTING, UMAKEINT(cmdid, 1), item);
 	}
@@ -661,8 +661,8 @@
 				  gint             page_num,
 				  gpointer         data)
 	{
-		int widid = ULOWORD((int)data);
-		int cmdid = UHIWORD((int)data);
+		int widid = ULOWORD((size_t)data);
+		int cmdid = UHIWORD((size_t)data);
 		
 		UEventSendMessage(widid, EV_PAGE_CHANGED, UMAKEINT(cmdid, page_num), 0L);
 	}
@@ -682,8 +682,8 @@
 
 	static gint gtkexposeevent(GtkWidget *widget, GdkEvent *event, gpointer user_data)
 	{
-		int widid = ULOWORD((int)user_data);
-		int cmdid = UHIWORD((int)user_data);
+		int widid = ULOWORD((size_t)user_data);
+		int cmdid = UHIWORD((size_t)user_data);
 		
 		UEventSendMessage(widid, EV_CUSTOM_DRAW, cmdid, event);
 		return TRUE;
@@ -782,7 +782,7 @@
 	m_listeners.push_back(listener);
 }
 
-int UWidget::UDispatchMessage(int/*UEventType*/ evt, int arg1, void *arg2, UDispatchInfo & dispatchInfo)
+int UWidget::UDispatchMessage(int/*UEventType*/ evt, int arg1, const void *arg2, UDispatchInfo & dispatchInfo)
 {
 	std::vector<UCmdTarget *>::iterator i;
 	for(i = m_listeners.begin(); i != m_listeners.end(); ++i)
@@ -3136,10 +3136,10 @@
 	if(!GTK_IS_CLIST(w))
 		return;
 
-	gchar *emptyTxts[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
+	const gchar *emptyTxts[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
 
     GtkCList *list = GTK_CLIST(w);
-	*num = gtk_clist_append  (list, emptyTxts);
+	*num = gtk_clist_append  (list, (gchar **)emptyTxts);
 #endif
 #if qMacAPP
 	TView *view = (TView *)w;
