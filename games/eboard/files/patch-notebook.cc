
$FreeBSD$

--- notebook.cc.orig	Wed Jun 26 03:06:59 2002
+++ notebook.cc	Sat Sep 28 23:00:58 2002
@@ -48,7 +48,7 @@
   gtk_widget_show(label);
 }
 
-Page::Page(int _number,GtkWidget *_content, char *_title, bool _removable=false) {
+Page::Page(int _number,GtkWidget *_content, char *_title, bool _removable) {
   
   GtkWidget *b,*p;
 
@@ -166,7 +166,7 @@
 		     (gpointer)this);
 }
 
-void Notebook::addPage(GtkWidget *what,char *title,int id,bool removable=false) {
+void Notebook::addPage(GtkWidget *what,char *title,int id,bool removable) {
   Page *pg;
   global.debug("Notebook","addPage",title);
   pg=new Page(id,what,title,removable);
@@ -205,7 +205,7 @@
   return( pages[i]->number );
 }
 
-void Notebook::setTabColor(int pageid,int color,Importance imp=IM_TOP) {
+void Notebook::setTabColor(int pageid,int color,Importance imp) {
   vector<Page *>::iterator pi;
   int i;
   global.debug("Notebook","setTabColor","1");
@@ -217,7 +217,7 @@
 }
 
 void Notebook::setTabColor(int page_num,int color,int poly,
-			   Importance imp=IM_TOP) {
+			   Importance imp) {
   vector<Page *>::iterator pi;
   GdkColor nc;
   GtkStyle *style;
