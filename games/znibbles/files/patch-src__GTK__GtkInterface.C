--- src/GTK/GtkInterface.C	Wed May 12 21:43:29 1999
+++ src/GTK/GtkInterface.C	Sat Oct 26 00:36:57 2002
@@ -37,7 +37,7 @@
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 
-#include <iostream.h>
+#include <iostream>
 
 #include <unistd.h>
 #include <stdlib.h>
@@ -138,7 +138,7 @@
   display_version();
     
   if (_two_key)
-    cout << "Two-key mode enabled" << endl;
+    std::cout << "Two-key mode enabled" << std::endl;
 
 
   // connect pipe_handler to SIGPIPE signal
@@ -154,9 +154,9 @@
     exit(2); 
   }
 
-  cout << "Connecting to ZNibbles server:  " \
+  std::cout << "Connecting to ZNibbles server:  " \
        << options.get_host_name() << ":" \
-       << options.get_port() << "... " << endl;
+       << options.get_port() << "... " << std::endl;
   
   // create and bind socket to any port 
   port = 0;
@@ -168,8 +168,8 @@
   } 
 
   if (_debug)
-    cout << "Client socket created on port: " \
-	 << ntohs(client_address.sin_port) << endl;
+    std::cout << "Client socket created on port: " \
+	 << ntohs(client_address.sin_port) << std::endl;
   
   // Build server address 
   server_address.sin_family = AF_INET;
@@ -186,7 +186,7 @@
 
   display_play_help();
 
-  cout << "Connection accepted\n" << endl;
+  std::cout << "Connection accepted\n" << std::endl;
 
   _hack_socket_client = _socket_client; // hack for signal handling
   action.sa_handler = stop_handler;
@@ -196,7 +196,7 @@
 
   init_messages(options.get_message_file());
 
-  cout << "initializing interface..." << endl;
+  std::cout << "initializing interface..." << std::endl;
   make(argc, argv);
 }
 
@@ -294,7 +294,7 @@
   case 'z':
     {
 //       if (_debug)
-	cout << "Sending welcome message..." << endl;
+	std::cout << "Sending welcome message..." << std::endl;
 	
 	Trame tzz;
 	tzz.reset();
@@ -315,7 +315,7 @@
 
   default:
     if (mythis._debug)
-      cout << "key=" << event->keyval << endl;
+      std::cout << "key=" << event->keyval << std::endl;
     return FALSE;
   }
   
@@ -337,7 +337,7 @@
 				   GtkInterface *pthis) 
 {
   if (pthis->_debug)
-    cerr << "GtkInterface:::configure_event()"<<endl;
+    std::cerr << "GtkInterface:::configure_event()"<<std::endl;
 
   return FALSE;
 }
@@ -349,7 +349,7 @@
 				 GtkInterface *pthis)
 {
   if (pthis->_debug)
-    cerr << "GtkInterface:::expose_event()"<<endl;
+    std::cerr << "GtkInterface:::expose_event()"<<std::endl;
   
   return FALSE;
 }
@@ -476,7 +476,7 @@
   // GTK, the proper way to do this would be to use the
   // gdk_input_add() function.
 
-  gtk_idle_add(myWorkProc, this);
+  gtk_idle_add((GtkFunction)myWorkProc, this);
 
   gdk_input_add(_socket_client, 
 		GDK_INPUT_READ,
@@ -487,57 +487,57 @@
 // display version numbers (long format)
 void GtkInterface::display_version() 
 {
-  cerr << "ZNibbles v" VERSION " - A little silly game - "
+  std::cerr << "ZNibbles v" VERSION " - A little silly game - "
        << "(c) Vincent Mallet 1997, 1998, 1999 - vmallet@enst.fr" 
-       << endl << endl;
+       << std::endl << std::endl;
 }
 
 // display version number (short format)
 void GtkInterface::display_version_short()
 {
-  cout << "ZNibbles Gtk Client " VERSION << endl;
+  std::cout << "ZNibbles Gtk Client " VERSION << std::endl;
 }
 
 // display small help
 void GtkInterface::display_help(char *name)
 {
-  cout << "Usage: " << name << " [OPTION].. PLAYERNAME" << endl;
-  cout << endl;
-  cout << "Start a ZNibbles Gtk client and connect to the specified nibbles server." << endl;
-  cout << endl;
-  cout << "  -n, --host-name=HOST     connect to server HOST [default is localhost]" << endl;
-  cout << "  -p, --port=NUM           connect to port NUM of server [default is 5051]" << endl;
-  cout << "  -m, --message-file=FILE  load predefined messages from file FILE" << endl;
-  cout << "  -t, --twokey             control worm with only two keys, LEFT and RIGHT" << endl;
-  cout << "  -i, --enable-stdin       enable standard input for sending messages" << endl;
-  cout << "  -d, --debug              enable debug output" << endl;
-  cout << "  -V, --version            print version number, then exit" \
-       << endl;
-  cout << "  -h, --help               show this message and exit" << endl;
-  cout << endl;
-  cout << "Report bugs to <vmallet@enst.fr>." << endl;
+  std::cout << "Usage: " << name << " [OPTION].. PLAYERNAME" << std::endl;
+  std::cout << std::endl;
+  std::cout << "Start a ZNibbles Gtk client and connect to the specified nibbles server." << std::endl;
+  std::cout << std::endl;
+  std::cout << "  -n, --host-name=HOST     connect to server HOST [default is localhost]" << std::endl;
+  std::cout << "  -p, --port=NUM           connect to port NUM of server [default is 5051]" << std::endl;
+  std::cout << "  -m, --message-file=FILE  load predefined messages from file FILE" << std::endl;
+  std::cout << "  -t, --twokey             control worm with only two keys, LEFT and RIGHT" << std::endl;
+  std::cout << "  -i, --enable-stdin       enable standard input for sending messages" << std::endl;
+  std::cout << "  -d, --debug              enable debug output" << std::endl;
+  std::cout << "  -V, --version            print version number, then exit" \
+       << std::endl;
+  std::cout << "  -h, --help               show this message and exit" << std::endl;
+  std::cout << std::endl;
+  std::cout << "Report bugs to <vmallet@enst.fr>." << std::endl;
 }
 
 
 
 void GtkInterface::display_play_help()
 {
-  cout << endl;
-  cout << "Welcome to ZNibbles!" << endl;
-  cout << endl;
-  cout << "Valid keys while playing:" << endl
-       << endl
-       << "     Up, Down, Left, Right:   move worm 1" << endl
-       << endl
-       << "     p/u                  :   pause/unpause game" << endl
-       << endl
-       << "     P/U                  :   pause/unpause _your_ worm" << endl
-       << endl
-       << "     1, 2, ... 0          :   send predefined messages to other players" << endl
-       << endl
-       << "     Ctrl+Q               :   quit game" << endl
-       << endl
-       << " Have fun!" << endl;
+  std::cout << std::endl;
+  std::cout << "Welcome to ZNibbles!" << std::endl;
+  std::cout << std::endl;
+  std::cout << "Valid keys while playing:" << std::endl
+       << std::endl
+       << "     Up, Down, Left, Right:   move worm 1" << std::endl
+       << std::endl
+       << "     p/u                  :   pause/unpause game" << std::endl
+       << std::endl
+       << "     P/U                  :   pause/unpause _your_ worm" << std::endl
+       << std::endl
+       << "     1, 2, ... 0          :   send predefined messages to other players" << std::endl
+       << std::endl
+       << "     Ctrl+Q               :   quit game" << std::endl
+       << std::endl
+       << " Have fun!" << std::endl;
 }
 
 
@@ -547,7 +547,7 @@
 
 void GtkInterface::pipe_handler(int sig)
 {
-  cerr << "--- Lost Server Connection! ---" << endl;
+  std::cerr << "--- Lost Server Connection! ---" << std::endl;
   sig++; // warnings..
   _dead_server = 1;
 }
@@ -555,7 +555,7 @@
 
 void GtkInterface::stop_handler(int sig)
 {
-  cerr << "--- Quitting game! ---" << endl;
+  std::cerr << "--- Quitting game! ---" << std::endl;
 
   if (_hack_socket_client) {
     struct timeval tv;
@@ -647,11 +647,11 @@
   char buf[300];
   
   if (priv) {
-    //    cout << "Got  *private*  Message: '" << msg << "'" << endl;
+    //    std::cout << "Got  *private*  Message: '" << msg << "'" << std::endl;
     sprintf(buf, "[Private] %s> %s\n", from.get_name(), msg);
   }
   else {
-    //    cout << "Message: " << from.get_name() << "> " << msg << endl;
+    //    std::cout << "Message: " << from.get_name() << "> " << msg << std::endl;
     sprintf(buf, "%s> %s\n", from.get_name(), msg);
   }
   
@@ -707,7 +707,7 @@
 void GtkInterface::join_game()
 {
   if (_debug)
-    cout << "Sending welcome message..." << endl;
+    std::cout << "Sending welcome message..." << std::endl;
   
   t.put_char(JOIN_GAME);
   t.put_string(_own_name);
@@ -740,21 +740,21 @@
 					      gint source,
 					      GdkInputCondition cond)
 {
-//DBG  cerr << "!" ;
+//DBG  std::cerr << "!" ;
   ((GtkInterface *)pthis)->handle_server_input();
 }
 
 
 void GtkInterface::handle_server_input()
 {
-//DBG   cerr << nnn << " " ;
+//DBG   std::cerr << nnn << " " ;
 //DBG   nnn = 0;
 
   static int done = 0;
-//DBG   cerr<<"<";
+//DBG   std::cerr<<"<";
   if (t.receive_from(_socket_client)) {
     _errors++;
-    cerr << "GtkInterface::handle_server_input(): read error" << endl;
+    std::cerr << "GtkInterface::handle_server_input(): read error" << std::endl;
     if (_errors >= 5) {
       pipe_handler(SIGPIPE);
     }
@@ -762,9 +762,9 @@
   }
 
   _errors = 0;
-//DBG  cerr<<">";
+//DBG  std::cerr<<">";
 
-//DBG       cerr << "X";
+//DBG       std::cerr << "X";
   
   switch(t.peek_char()) {
   case TRAME_ERROR:
@@ -802,14 +802,14 @@
 
   case QUIT_GAME:
     if (_debug)
-      cout << "Got QUIT_GAME" << endl;
-    cout << "Client shutting down.... " << endl;
+      std::cout << "Got QUIT_GAME" << std::endl;
+    std::cout << "Client shutting down.... " << std::endl;
     done = 1;
     break;
     
   default:
     if (_debug)
-      cout << "got unknown frame type: " << (int) t.peek_char() << endl;
+      std::cout << "got unknown frame type: " << (int) t.peek_char() << std::endl;
     break;
   }
 }
@@ -840,7 +840,7 @@
   int my_other_player_id = t.get_int();
 
   if (_debug)
-    cout << "my new player: " << my_other_player_id << endl;
+    std::cout << "my new player: " << my_other_player_id << std::endl;
 
   Player& p = world.lookup_player(my_other_player_id);
 
@@ -848,8 +848,8 @@
 
   if (_other_player == NULL) {
     if (_debug)
-      cout << "GtkInterface::do_your_other_player(): bad id: " \
-	   << my_other_player_id << endl;
+      std::cout << "GtkInterface::do_your_other_player(): bad id: " \
+	   << my_other_player_id << std::endl;
     return;
   }
 
@@ -870,7 +870,7 @@
 void GtkInterface::do_void_trame() 
 {
   if (_debug)
-    cout << "got VOID_TRAME " << endl;
+    std::cout << "got VOID_TRAME " << std::endl;
   t.get_char();
   char *p = t.get_string();
   if (p && strcmp(p, "w") == 0)
@@ -978,8 +978,8 @@
   
   if (gtk_player == NULL) {
     if (_debug)
-      cerr << "GtkInterface::set_own_player(): SERIOUS: player not found !" \
-	   << endl;
+      std::cerr << "GtkInterface::set_own_player(): SERIOUS: player not found !" \
+	   << std::endl;
     return;
   }
 
@@ -999,7 +999,7 @@
 {
   if (_other_player == NULL) {
     if (_debug)
-      cout << "Sending welcome message..." << endl;
+      std::cout << "Sending welcome message..." << std::endl;
     
     Trame tzz;
     char s[100];
