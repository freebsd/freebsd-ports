--- src/ui.cpp.orig	2018-02-10 10:03:56 UTC
+++ src/ui.cpp
@@ -100,7 +100,7 @@ public:
     virtual void motion(GtkWidget *,int x,int y,int b);
 private:
     void create();
-    void add_icon_to_button(GtkWidget *,char **xpm);
+    void add_icon_to_button(GtkWidget *,const char **xpm);
     void add_input_mode(GtkWidget *,char *,int mode);
     void init_mode_menu();
     void init_buttons();
@@ -286,7 +286,7 @@ void ToolBar::create()
     gtk_widget_show(m_hbox);
     gtk_widget_show(m_win);
     //³¨¤òÅ½¤ë¡¢
-    char **p;
+    const char **p;
     p = getKKIcon();
     if (p) {
 	add_icon_to_button(kk_setting_button,p);
@@ -353,7 +353,7 @@ void ToolBar::set_mode(int s)
     }
 }
 
-void ToolBar::add_icon_to_button(GtkWidget *button,char **xpm)
+void ToolBar::add_icon_to_button(GtkWidget *button,const char **xpm)
 {
     GtkStyle *style;
     GdkBitmap *mask;
@@ -434,7 +434,7 @@ void ToolBar::destroy(GtkWidget *w)
 
 void ToolBar::activate(GtkWidget *w,gpointer p)
 {
-    int pos = (int)p;
+    int pos = (uint64_t)p;
     gtk_widget_draw(w, NULL);
     user_if->change_menu(pos);
 }
@@ -581,7 +581,7 @@ GtkWidget *Indicator::get_win()
 
 void Indicator::draw_stat()
 {
-    char *m = "OFF";
+    const char *m = "OFF";
     if (XimIC::isAnyActive()){
 	m = "ON";
     }
