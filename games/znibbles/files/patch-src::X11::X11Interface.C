--- src/X11/X11Interface.C	Wed May 12 21:43:42 1999
+++ src/X11/X11Interface.C	Sat Oct 26 00:32:49 2002
@@ -38,7 +38,7 @@
 # include <config.h>
 #endif
 
-#include <iostream.h>
+#include <iostream>
 
 #include <unistd.h>
 #include <stdlib.h>
@@ -109,7 +109,7 @@
   display_version();
 
   if (_two_key)
-    cout << "Two-key mode enabled" << endl;
+    std::cout << "Two-key mode enabled" << std::endl;
 
   
   // connect pipe_handler to SIGPIPE signal
@@ -125,8 +125,8 @@
     exit(2); 
   }
 
-  cout << "Connecting to ZNibbles server:  " \
-       << options.get_host_name() << ":" << options.get_port() << "... " << endl;
+  std::cout << "Connecting to ZNibbles server:  " \
+       << options.get_host_name() << ":" << options.get_port() << "... " << std::endl;
   
   // create and bind socket to any port 
   port = 0;
@@ -136,7 +136,7 @@
   } 
 
 //   if (debug)
-//     cout << "Client socket created on port: " << ntohs(client_address.sin_port) << endl;
+//     std::cout << "Client socket created on port: " << ntohs(client_address.sin_port) << std::endl;
   
   // Build server address 
   server_address.sin_family = AF_INET;
@@ -153,7 +153,7 @@
 
   display_play_help();
 
-  cout << "Connection accepted\n" << endl;
+  std::cout << "Connection accepted\n" << std::endl;
 
 //   hack_socket_client = socket_client; // hack for signal handling
 //   action.sa_handler = stop_handler;
@@ -163,7 +163,7 @@
 
   init_messages(options.get_message_file());
 
-  cout << "initializing interface..." << endl;
+  std::cout << "initializing interface..." << std::endl;
   X11Init(argc, argv);
 }
 
@@ -201,56 +201,56 @@
 // display version number (long format)
 void X11Interface::display_version() 
 {
-  cerr << "ZNibbles v" VERSION " - A little silly game - "
+  std::cerr << "ZNibbles v" VERSION " - A little silly game - "
        << "(c) Vincent Mallet 1997, 1998, 1999 - vmallet@enst.fr" 
-       << endl << endl;
+       << std::endl << std::endl;
 }
 
 // display version number (short format)
 void X11Interface::display_version_short()
 {
-  cout << "ZNibbles X11 Client -experimental- " VERSION << endl;
+  std::cout << "ZNibbles X11 Client -experimental- " VERSION << std::endl;
 }
 
 //display small help for invocation
 void X11Interface::display_help(char *name)
 {
-  cout << "Usage: " << name << " [OPTION].. PLAYERNAME" << endl;
-  cout << endl;
-  cout << "Start a ZNibbles X11 client and connect to the specified nibbles server." << endl;
-  cout << endl;
-  cout << "  -n, --host-name=HOST     connect to server HOST [default is localhost]" << endl;
-  cout << "  -p, --port=NUM           connect to port NUM of server [default is 5051]" << endl;
-  cout << "  -m, --message-file=FILE  load predefined messages from file FILE" << endl;
-  cout << "  -t, --twokey             control worm with only two keys, LEFT and RIGHT" << endl;
-  cout << "  -i, --enable-stdin       enable standard input for sending messages" << endl;
-  cout << "  -d, --debug              enable debug output" << endl;
-  cout << "  -V, --version            print version number, then exit" << endl;
-  cout << "  -h, --help               show this message and exit" << endl;
-  cout << endl;
-  cout << "Report bugs to <vmallet@enst.fr>." << endl;
+  std::cout << "Usage: " << name << " [OPTION].. PLAYERNAME" << std::endl;
+  std::cout << std::endl;
+  std::cout << "Start a ZNibbles X11 client and connect to the specified nibbles server." << std::endl;
+  std::cout << std::endl;
+  std::cout << "  -n, --host-name=HOST     connect to server HOST [default is localhost]" << std::endl;
+  std::cout << "  -p, --port=NUM           connect to port NUM of server [default is 5051]" << std::endl;
+  std::cout << "  -m, --message-file=FILE  load predefined messages from file FILE" << std::endl;
+  std::cout << "  -t, --twokey             control worm with only two keys, LEFT and RIGHT" << std::endl;
+  std::cout << "  -i, --enable-stdin       enable standard input for sending messages" << std::endl;
+  std::cout << "  -d, --debug              enable debug output" << std::endl;
+  std::cout << "  -V, --version            print version number, then exit" << std::endl;
+  std::cout << "  -h, --help               show this message and exit" << std::endl;
+  std::cout << std::endl;
+  std::cout << "Report bugs to <vmallet@enst.fr>." << std::endl;
 }
 
 
 // display help on key used
 void X11Interface::display_play_help()
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
 
 
@@ -261,7 +261,7 @@
 
 void X11Interface::pipe_handler(int sig)
 {
-  cerr << "--- Lost Server Connection! ---" << endl;
+  std::cerr << "--- Lost Server Connection! ---" << std::endl;
   sig++; // warnings..
   dead_server = 1;
 }
@@ -285,7 +285,7 @@
 
     z++;
     if (t.receive_from(socket_client)) {
-      //      cout << "receive error, errno=" << errno << endl;
+      //      std::cout << "receive error, errno=" << errno << std::endl;
 
       handle_Xevent();
       
@@ -309,7 +309,7 @@
 	}
 	
 	if (dir) {
-	  cout << "Sending Direction ==" << dir << endl;
+	  std::cout << "Sending Direction ==" << dir << std::endl;
 	  tx.reset();
 	  tx.put_char(PLAYER_CHANGEDIR);
 	  tx.put_char(dir);
@@ -323,7 +323,7 @@
 	  break; // on verra ca plus tard.
 	  
 	case WORLD_DESC: 
-	  cout << endl << "got WORLD_DESC " << endl;
+	  std::cout << std::endl << "got WORLD_DESC " << std::endl;
 	  w.read_description(t);
 	  tx.reset();
 	  tx.put_char(CYCLE_ACK);
@@ -333,14 +333,14 @@
 	  break;
 	  
 	case CHANGE_NOTIFY:
-	  //FAST	  cout << endl <<  "got CHANGE_NOTIFY " << endl;
+	  //FAST	  std::cout << std::endl <<  "got CHANGE_NOTIFY " << std::endl;
 	  t.get_char(); 
 	  w.read_changes(t);
 	  break;
 	  
 	case VOID_TRAME:
 	  {
-	    cout << "got VOID_TRAME " << endl;
+	    std::cout << "got VOID_TRAME " << std::endl;
 	    t.get_char();
 	    char *p = t.get_string();
 	    if (p && strcmp(p, "w") == 0)
@@ -358,10 +358,10 @@
 	
 	case TEXT_MESSAGE:
 	  {
-	    cout << "got *private* TEXT_MESSAGE == '";
+	    std::cout << "got *private* TEXT_MESSAGE == '";
 	    t.get_char(); // skip packet id
 	    char *msg = t.get_string();
-	    cout << msg << "'" << endl;
+	    std::cout << msg << "'" << std::endl;
 	  }
 	break;
 
@@ -393,13 +393,13 @@
 	break;
 
 	case QUIT_GAME:
-	  cout << "Got QUIT_GAME" << endl;
-	  cout << "Client shutting down.... " << endl;
+	  std::cout << "Got QUIT_GAME" << std::endl;
+	  std::cout << "Client shutting down.... " << std::endl;
 	  done = 1;
 	  break;
 
 	default:
-	  cout << "got unknown frame type: " << (int) t.peek_char() << endl;
+	  std::cout << "got unknown frame type: " << (int) t.peek_char() << std::endl;
 	  break;
 	}
     }
@@ -427,13 +427,13 @@
 	nibblesarea.redraw2();
       break;
     case ButtonPress:
-      cout << "ButtonPress" << endl;
+      std::cout << "ButtonPress" << std::endl;
       break;
     case KeyPress:
       nibblesarea.handle_key(&report);
       break;
     case ConfigureNotify:
-      cout << "Configure" << endl;
+      std::cout << "Configure" << std::endl;
       break;
     }
   }
@@ -442,30 +442,30 @@
 
 void X11Interface::add_player(Player& p)
 {
-  cout << "Player <" << p.get_name() <<"> joined the game!" << endl;
+  std::cout << "Player <" << p.get_name() <<"> joined the game!" << std::endl;
 }
 
 void X11Interface::kill_player(Player& p, int reason)
 {
-  cout << "Player <" << p.get_name() <<"> LEFT the game!     (reason=" << reason << ")" << endl;
+  std::cout << "Player <" << p.get_name() <<"> LEFT the game!     (reason=" << reason << ")" << std::endl;
 }
 
 
 void X11Interface::display_message(Player& from, char *msg, int priv)
 {
   if (priv) 
-    cout << "*private*  Message: " << from.get_name() << "> " << msg << endl;
+    std::cout << "*private*  Message: " << from.get_name() << "> " << msg << std::endl;
   else 
-    cout << "Message: " << from.get_name() << "> " << msg << endl;
+    std::cout << "Message: " << from.get_name() << "> " << msg << std::endl;
 }
 
 void X11Interface::display_system_message(char *msg, Player *p, int color) // default p=NULL, color=0
 {
   color++;
-  cout << "*** ";
+  std::cout << "*** ";
   if (p)
-    cout << p->get_name() << " ";
-  cout << msg;
+    std::cout << p->get_name() << " ";
+  std::cout << msg;
 }
 
 
