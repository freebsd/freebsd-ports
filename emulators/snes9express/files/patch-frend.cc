--- frend.cc.orig	2009-12-21 22:38:54 UTC
+++ frend.cc
@@ -379,7 +379,7 @@ void dimension<T>::input(std::istream& i
   i >> buf;
   unsigned int l = buf.size(), xpos = 0, ypos = 0;
   if(l < 3)
-    return i;
+    return;
   if(buf[0]=='(')
     xpos++;
   if(buf[l-1]==',')
@@ -400,13 +400,12 @@ void dimension<T>::input(std::istream& i
   const char*buf3 = buf.c_str();
   _x = strtol(&(buf[xpos]), NULL, 0);
   _y = strtol(&(buf[ypos]), NULL, 0);
-  return i;
 }
 
 template <class T>
 void dimension<T>::print(std::ostream& o) const
 {
-  return o << "(" << _x << ", " << _y << ")";
+  o << "(" << _x << ", " << _y << ")";
 }
 
 /* ############################## Color ################################ */
@@ -2527,7 +2526,7 @@ void Window::addMenu(const char*label, M
 	{
 		if(strcmp(items[i].label, "-"))
 		{
-			if(items[i].icon > 0)
+			if(items[i].icon)
 			{
 				menu_item = gtk_menu_item_new();
 				GtkWidget *hbox = gtk_hbox_new(false, false);
