
$FreeBSD$

--- text.cc.orig	Sun Apr 28 23:04:34 2002
+++ text.cc	Sat Sep 28 23:00:58 2002
@@ -198,14 +198,14 @@
   gtk_widget_show(widget);
 }
 
-void Text::append(char *msg,int color,Importance imp=IM_NORMAL) {
+void Text::append(char *msg,int color,Importance imp) {
   if (Filter.accept(msg)) {
     pushLevel(imp);
     gtk_ftext_append(GTK_FTEXT(text),msg,-1,color);
   }
 }
 
-void Text::append(char *msg,char *msg2,int color, Importance imp=IM_NORMAL) {
+void Text::append(char *msg,char *msg2,int color, Importance imp) {
   char *d;
   d=(char *)g_malloc0(strlen(msg)+strlen(msg2)+1);
   strcpy(d,msg);
@@ -253,13 +253,13 @@
     }
 }
 
-void TextSet::append(char *msg,int color,Importance imp=IM_NORMAL) {
+void TextSet::append(char *msg,int color,Importance imp) {
   list<Text *>::iterator ti;
   for(ti=targets.begin();ti!=targets.end();ti++)
     (*ti)->append(msg,color,imp);
 }
 
-void TextSet::append(char *msg,char *msg2,int color,Importance imp=IM_NORMAL) {
+void TextSet::append(char *msg,char *msg2,int color,Importance imp) {
   list<Text *>::iterator ti;
   for(ti=targets.begin();ti!=targets.end();ti++)
     (*ti)->append(msg,msg2,color,imp);
