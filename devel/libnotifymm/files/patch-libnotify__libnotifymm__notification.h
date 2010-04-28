--- ./libnotify/libnotifymm/notification.h.orig	2010-04-23 11:36:40.000000000 -0400
+++ ./libnotify/libnotifymm/notification.h	2010-04-23 11:37:20.000000000 -0400
@@ -191,7 +191,7 @@
    * location. If @a attach is <tt>0</tt>, the widget will be unset.
    * @param attach The widget to attach to, or <tt>0</tt>.
    */
-  void attach_to_widget(Gtk::Widget& attach);;
+  void attach_to_widget(Gtk::Widget& attach);
   
   /** Attaches the notification to a Gtk::StatusIcon. This will set hints on the
    * notification requesting that the notification point to the status icon's
@@ -303,17 +303,16 @@
    * specified callback function will be called.
    */
    void add_action(const Glib::ustring& action, const Glib::ustring& label, const SlotInvokeAction& slot);
-  ;
   
   
   /** Clears all hints from the notification.
    */
-  void clear_hints();;
+  void clear_hints();
     
   
   /** Clears all actions from the notification.
    */
-  void clear_actions();;
+  void clear_actions();
   
   /** Tells the notification server to hide the notification on the screen.
    * @return <tt>true</tt> if successful. On error, this will return <tt>false</tt> and set
@@ -324,16 +323,14 @@
 #else
   void close(std::auto_ptr<Glib::Error>& error);
 #endif //GLIBMM_EXCEPTIONS_ENABLED
-;
-  
-  
+ 
+ 
   /**
    * @par Prototype:
    * <tt>void on_my_%closed()</tt>
    */
 
   Glib::SignalProxy0< void > signal_closed();
-;
   
   //gtkmmproc error: id : property defs lookup failed.
   #ifdef GLIBMM_PROPERTIES_ENABLED
