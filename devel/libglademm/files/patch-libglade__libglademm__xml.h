--- libglade/libglademm/xml.h.orig	Tue Oct 11 11:18:23 2005
+++ libglade/libglademm/xml.h	Tue Oct 11 11:18:51 2005
@@ -240,7 +240,7 @@
      //If there is already a C++ instance, then return it again:
      if(pObjectBase)
      {
-       widget = dynamic_cast<T_Widget*>( Glib::wrap(pCWidget) );
+       widget = dynamic_cast<T_Widget*>( Glib::wrap((GtkWidget*)pCWidget) );
 
        //The dynamic cast checks that it is of the correct type.
        //Somebody might be trying to call get_widget_derived() after already calling get_widget(),
