--- src/ServerInterface.C	Tue May 11 12:13:52 1999
+++ src/ServerInterface.C	Sat Oct 26 00:50:26 2002
@@ -48,6 +48,9 @@
 #include <errno.h>
 
 #include <sys/times.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 
 #include "DLList.h" // Doubly linked lists
 
@@ -118,9 +121,9 @@
 
   display_version();
     
-  cerr << "ServerInterface(): experimental nibbles"   \
+  std::cerr << "ServerInterface(): experimental nibbles"   \
        << "interface! Don't run it in background... " \
-       << endl << endl;
+       << std::endl << std::endl;
   
   srand(time(NULL));
 
@@ -144,12 +147,12 @@
   sigaction(SIGCHLD, &action, NULL);
 */  
 
-  cout << "Starting ZNibbles Server on port: " << port << endl;
+  std::cout << "Starting ZNibbles Server on port: " << port << std::endl;
   
   // Create and attach the listening socket
   if((socket_ecoute = creer_socket(SOCK_STREAM, &port, &address)) == -1) {
-    cerr << "Unable to create socket. Try option `--help' to get some help."\
-	 << endl;
+    std::cerr << "Unable to create socket. Try option `--help' to get some help."\
+	 << std::endl;
     exit(2);
   } 
 
@@ -170,36 +173,36 @@
 // display version numbers (long format)
 void ServerInterface::display_version() 
 {
-  cerr << "ZNibbles Server v" VERSION " - A little silly game - "
+  std::cerr << "ZNibbles Server v" VERSION " - A little silly game - "
        << "(c) Vincent Mallet 1997, 1998, 1999 - vmallet@enst.fr" 
-       << endl << endl;
+       << std::endl << std::endl;
 }
 
 
 // display version number (short format)
 void ServerInterface::display_version_short()
 {
-  cout << "ZNibbles Server " VERSION << endl;
+  std::cout << "ZNibbles Server " VERSION << std::endl;
 }
 
 
 // display small help
 void ServerInterface::display_help(char *name)
 {
-  cout << "usage: " << name << " [OPTIONS].." << endl;
-  cout << endl;
-  cout << "Start a ZNibbles Server." << endl;
-  cout << endl;
-  cout << "  -p, --port=NUM       listen for clients on port NUM [default is 5051]" << endl;
-  cout << "  -s, --size=NUMxNUM   create a world of dimension NUMxNUM [default is 80x40]" << endl;
-  cout << "  -w, --width=NUM      create a world of width NUM [default is 80]" << endl;
-  cout << "  -g, --height=NUM     create a world of height NUM [default is 40]" << endl;
-  cout << "  -c, --no-computer    disable computer-controlled worms" << endl;
-  cout << "  -d, --debug          enable debug output" << endl;
-  cout << "  -V, --version        print version number, then exit" << endl;
-  cout << "  -h, --help           show this message and exit" << endl;
-  cout << endl;
-  cout << "Report bugs to <vmallet@enst.fr>." << endl;
+  std::cout << "usage: " << name << " [OPTIONS].." << std::endl;
+  std::cout << std::endl;
+  std::cout << "Start a ZNibbles Server." << std::endl;
+  std::cout << std::endl;
+  std::cout << "  -p, --port=NUM       listen for clients on port NUM [default is 5051]" << std::endl;
+  std::cout << "  -s, --size=NUMxNUM   create a world of dimension NUMxNUM [default is 80x40]" << std::endl;
+  std::cout << "  -w, --width=NUM      create a world of width NUM [default is 80]" << std::endl;
+  std::cout << "  -g, --height=NUM     create a world of height NUM [default is 40]" << std::endl;
+  std::cout << "  -c, --no-computer    disable computer-controlled worms" << std::endl;
+  std::cout << "  -d, --debug          enable debug output" << std::endl;
+  std::cout << "  -V, --version        print version number, then exit" << std::endl;
+  std::cout << "  -h, --help           show this message and exit" << std::endl;
+  std::cout << std::endl;
+  std::cout << "Report bugs to <vmallet@enst.fr>." << std::endl;
 }
 
 
@@ -230,9 +233,15 @@
     socket_service = -1;
     while (socket_service == -1) {
       // wait for connection
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 400013)
+      socket_service = accept(socket_ecoute, 
+			      (struct sockaddr *) &address, 
+			      (socklen_t *) &lg_address);
+#else
       socket_service = accept(socket_ecoute, 
 			      (struct sockaddr *) &address, 
 			      &lg_address);
+#endif
       
       // Reception d'un signal (probablement SIGCHLD) 
       if(socket_service == -1 && errno == EINTR) {
@@ -277,7 +286,7 @@
 	char *peol;
 
  	if (debug) {
-	  cout << "chaine: ";
+	  std::cout << "chaine: ";
  	}
 
 	fgets(line, MAXLINE, stdin);
@@ -305,28 +314,28 @@
 	} else if (strcmp(line, "p") == 0) { // pause
 	  xpaused = !xpaused;
 	  display_system_message(((xpaused) 
-				  ? "Pausing...\n" 
-				  : "Running...\n"));
+				  ? (char *)"Pausing...\n" 
+				  : (char *)"Running...\n"));
 	  continue;
 	} else if (strcmp(line, "-") == 0) { // slower...
  	  if (debug) {
-	    cout << "slower...  ival=";
+	    std::cout << "slower...  ival=";
  	  }
 	  ival += 25000UL;
  	  if (debug) {
-	    cout << ival << endl;
+	    std::cout << ival << std::endl;
  	  }
 	  continue;
 	} else if (strcmp(line, "+") == 0) { // faster!
 	  if (ival > 0UL) {
  	    if (debug) {
-	      cout << "Faster!  ival=";
+	      std::cout << "Faster!  ival=";
  	    }
 	    ival -= 25000UL;
 	    if (ival > 10000000)
 	      ival = 0;
  	    if (debug) {
-	      cout << ival << endl;
+	      std::cout << ival << std::endl;
  	    }
 	  } else
 	    display_system_message("Can't go faster :)\n");
@@ -388,7 +397,7 @@
 void ServerInterface::pipe_handler(int sig)
 {
   sig++;
-  //   cerr << "got SIGPIPE!" << endl;
+  //   std::cerr << "got SIGPIPE!" << std::endl;
   //   pipe_rw_error = 1;
 }
 
@@ -407,9 +416,9 @@
 // void ServerInterface::alarm_handler(int sig)
 // {
 //   if (curworld) {
-//     cout << "---- TIMED: " << (curworld->playcycle - startcycle) 
+//     std::cout << "---- TIMED: " << (curworld->playcycle - startcycle) 
 //          << "  cycles -------"
-// 	 << "(sig=" << sig << ")" << endl;
+// 	 << "(sig=" << sig << ")" << std::endl;
 //     startcycle = curworld->playcycle;
 //   }
 // }
@@ -433,9 +442,15 @@
 
   while (read_ready(socketnum)) {
 
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 400013)
+    socket_service = accept(socketnum, 
+			    (struct sockaddr *) &address, 
+			    (socklen_t *) &lg_address);
+#else
     socket_service = accept(socketnum, 
 			    (struct sockaddr *) &address, 
 			    &lg_address);
+#endif
 
     // s'il y a une erreur, ce n'est pas une EINTR (cf appel a read_ready())
     if(socket_service == -1) { 
@@ -475,9 +490,9 @@
     return;
   
   if (priv) 
-    cout << "*private*  Message: " << from.get_name() << "> " << msg << endl;
+    std::cout << "*private*  Message: " << from.get_name() << "> " << msg << std::endl;
   else 
-    cout << "Message: " << from.get_name() << "> " << msg << endl;
+    std::cout << "Message: " << from.get_name() << "> " << msg << std::endl;
 }
 
 void ServerInterface::display_system_message(char   * msg, 
@@ -488,8 +503,8 @@
     return;
 
   color++;
-  cout << "*** ";
+  std::cout << "*** ";
   if (p)
-    cout << p->get_name() << " ";
-  cout << msg;
+    std::cout << p->get_name() << " ";
+  std::cout << msg;
 }
