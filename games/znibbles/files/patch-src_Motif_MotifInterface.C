--- src/Motif/MotifInterface.C.orig	1999-05-12 11:43:51 UTC
+++ src/Motif/MotifInterface.C
@@ -32,7 +32,7 @@
 # include <config.h>
 #endif
 
-#include <iostream.h>
+#include <iostream>
 
 #include <unistd.h>
 #include <stdlib.h>
@@ -131,7 +131,7 @@ void MotifInterface::init(int argc, char
   display_version();
 
   if (two_key)
-    cout << "Two-key mode enabled" << endl;
+    std::cout << "Two-key mode enabled" << std::endl;
 
   
   // connect pipe_handler to SIGPIPE signal
@@ -147,8 +147,8 @@ void MotifInterface::init(int argc, char
     exit(2); 
   }
 
-  cout << "Connecting to ZNibbles server:  " \
-       << options.get_host_name() << ":" << options.get_port() << "... " << endl;
+  std::cout << "Connecting to ZNibbles server:  " \
+       << options.get_host_name() << ":" << options.get_port() << "... " << std::endl;
   
   // create and bind socket to any port 
   port = 0;
@@ -158,7 +158,7 @@ void MotifInterface::init(int argc, char
   } 
 
   if (debug)
-    cout << "Client socket created on port: " << ntohs(client_address.sin_port) << endl;
+    std::cout << "Client socket created on port: " << ntohs(client_address.sin_port) << std::endl;
   
   // Build server address 
   server_address.sin_family = AF_INET;
@@ -175,7 +175,7 @@ void MotifInterface::init(int argc, char
 
   display_play_help();
 
-  cout << "Connection accepted\n" << endl;
+  std::cout << "Connection accepted\n" << std::endl;
 
   hack_socket_client = socket_client; // hack for signal handling
   action.sa_handler = stop_handler;
@@ -185,7 +185,7 @@ void MotifInterface::init(int argc, char
 
   init_messages(options.get_message_file());
 
-  cout << "initializing interface..." << endl;
+  std::cout << "initializing interface..." << std::endl;
   make(argc, argv);
 }
 
@@ -262,54 +262,54 @@ void MotifInterface::make(int argc, char
 
 void MotifInterface::display_version() 
 {
-  cerr << "ZNibbles v" VERSION " - A little silly game - "
+  std::cerr << "ZNibbles v" VERSION " - A little silly game - "
        << "(c) Vincent Mallet 1997, 1998, 1999 - vmallet@enst.fr" 
-       << endl << endl;
+       << std::endl << std::endl;
 }
 
 void MotifInterface::display_version_short()
 {
-  cout << "ZNibbles Motif Client " VERSION << endl;
+  std::cout << "ZNibbles Motif Client " VERSION << std::endl;
 }
 
 void MotifInterface::display_help(char *name)
 {
-  cout << "Usage: " << name << " [OPTION].. PLAYERNAME" << endl;
-  cout << endl;
-  cout << "Start a ZNibbles Motif client and connect to the specified nibbles server." << endl;
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
+  std::cout << "Start a ZNibbles Motif client and connect to the specified nibbles server." << std::endl;
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
 
 
 
 void MotifInterface::display_play_help()
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
 
 
@@ -318,7 +318,7 @@ void MotifInterface::display_play_help()
 
 void MotifInterface::pipe_handler(int sig)
 {
-  cerr << "--- Lost Server Connection! ---" << endl;
+  std::cerr << "--- Lost Server Connection! ---" << std::endl;
   sig++; // warnings..
   dead_server = 1;
 }
@@ -326,7 +326,7 @@ void MotifInterface::pipe_handler(int si
 
 void MotifInterface::stop_handler(int sig)
 {
-  cerr << "--- Quitting game! ---" << endl;
+  std::cerr << "--- Quitting game! ---" << std::endl;
 
   if (hack_socket_client) {
     struct timeval tv;
@@ -391,11 +391,11 @@ void MotifInterface::display_message(Pla
   char buf[300];
   
   if (priv) {
-    //    cout << "Got  *private*  Message: '" << msg << "'" << endl;
+    //    std::cout << "Got  *private*  Message: '" << msg << "'" << std::endl;
     sprintf(buf, "[Private] %s> %s\n", from.get_name(), msg);
   }
   else {
-    //    cout << "Message: " << from.name << "> " << msg << endl;
+    //    std::cout << "Message: " << from.name << "> " << msg << std::endl;
     sprintf(buf, "%s> %s\n", from.get_name(), msg);
   }
   textarea.add_line(buf);
@@ -545,7 +545,7 @@ Boolean MotifInterface::myWorkProc(XtPoi
       case VOID_TRAME:
 	{
 	  if (mythis.debug)
-	    cout << "got VOID_TRAME " << endl;
+	    std::cout << "got VOID_TRAME " << std::endl;
 	  mt.get_char();
 	  char *p = mt.get_string();
 	  if (p && strcmp(p, "w") == 0)
@@ -595,14 +595,14 @@ Boolean MotifInterface::myWorkProc(XtPoi
       
       case QUIT_GAME:
 	if (mythis.debug)
-	  cout << "Got QUIT_GAME" << endl;
-	cout << "Client shutting down.... " << endl;
+	  std::cout << "Got QUIT_GAME" << std::endl;
+	std::cout << "Client shutting down.... " << std::endl;
 	done = 1;
 	break;
 	
       default:
 	if (mythis.debug)
-	  cout << "got unknown frame type: " << (int) mt.peek_char() << endl;
+	  std::cout << "got unknown frame type: " << (int) mt.peek_char() << std::endl;
 	break;
       }
     }
@@ -661,7 +661,7 @@ void MotifInterface::pause_request(int p
 void MotifInterface::join_game()
 {
   if (debug)
-    cout << "Sending welcome message..." << endl;
+    std::cout << "Sending welcome message..." << std::endl;
   
   t.put_char(JOIN_GAME);
   t.put_string(own_name);
