--- cmn/role.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/role.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -29,9 +29,9 @@
 
 #include "stdafx.h"
 
-#include <iostream.h>
+#include <iostream>
 #if X11
-#include <strstream.h>
+#include <sstream>
 #include <time.h>
 #endif
 #if WIN32
@@ -266,43 +266,39 @@
 
 
 void Role::error(const char *msg1,const char *msg2,const char *msg3) {
-  ostrstream str;
+  stringstream str;
 
   if (msg2 == NULL) {
-    str << msg1 << ends;
+    str << msg1;
   }
   else if (msg3 == NULL) {
-    str << msg1 << msg2 << ends;
+    str << msg1 << msg2;
   }
   else {
-    str << msg1 << msg2 << msg3 << ends;
+    str << msg1 << msg2 << msg3;
   }
 
   // Call one argument version.
-  _error(str.str());
-
-  delete str.str();
+  _error(str.str().c_str());
 }
 
 
 
 void Role::message(const char *msg1,const char *msg2,const char *msg3) {
-  ostrstream str;
+  stringstream str;
 
   if (msg2 == NULL) {
-    str << msg1 << ends;
+    str << msg1;
   }
   else if (msg3 == NULL) {
-    str << msg1 << msg2 << ends;
+    str << msg1 << msg2;
   }
   else {
-    str << msg1 << msg2 << msg3 << ends;
+    str << msg1 << msg2 << msg3;
   }
 
   // Call one argument version.
-  _message(str.str());
-
-  delete str.str();
+  _message(str.str().c_str());
 }
 
 
@@ -605,11 +601,11 @@
   // Display message that we are looking up IP address.
   // Assumes that caller will call Client::connect_server after a turn or two, 
   // so the message will be displayed on the Ui.
-  ostrstream str;
-  str << "Looking up IP address for server " << serverName << ends;
+  stringstream str;
+  str << "Looking up IP address for server " << serverName;
   // Display for a long time.
-  errLocator->arena_message_enq(str.str(),NULL,1000000); 
-  errLocator->message_enq(Utils::strdup(str.str()));
+  errLocator->arena_message_enq(Utils::strdup(str.str().c_str()),NULL,1000000);
+  errLocator->message_enq(Utils::strdup(str.str().c_str()));
   // Probably would be better to use Role::message(), but we want it to stay
   // up for a long time.  Should add argument to Role::message().
 
@@ -657,18 +653,16 @@ void Client::connect_server() {  
     client.sin_family = AF_INET;
     client.sin_addr.s_addr = htonl(INADDR_ANY);
     client.sin_port = htons((u_short)(clientPortBase + n));
-    if (bind(udpSock,(CMN_SOCKADDR *)&client,sizeof(client)) >= 0) {
+    if (::bind(udpSock,(CMN_SOCKADDR *)&client,sizeof(client)) >= 0) {
       // Success.
       break;
     }
   }
   if (n == CLIENT_PORT_TRIES) {
-    ostrstream str;
+    stringstream str;
     str << "Could not bind local UDP port to any of " 
-        << clientPortBase << "-" << (clientPortBase + CLIENT_PORT_TRIES - 1) 
-        << ends;
-    error(str.str());
-    delete str.str();
+        << clientPortBase << "-" << (clientPortBase + CLIENT_PORT_TRIES - 1);
+    error(str.str().c_str());
     return;    
   }
   //  cout << "UDP port seems to be" << client.sin_port << endl;
@@ -703,22 +697,19 @@
 
   // Inform user of failed connection
   if (!ok()) {
-    strstream msg;
+    stringstream msg;
     msg << "Could not connect to " << serverName << " on port " <<
-      port << "." << ends;
-    error(msg.str());
-    delete(msg.str());
+      port << ".";
+    error(msg.str().c_str());
     delete tcpOut;
     return;
   }
 
   // Inform user of successful connection
-  strstream msg;
+  stringstream msg;
   msg << hostName << " connected to " << serverName << " on port " <<
-    port << ends;
-  message(msg.str());
-  delete msg.str();
-
+    port;
+  message(msg.str().c_str());
   
   // Create TCP and UDP streams.
   tcpIn = new NetInStream(tcpSock,False);
@@ -967,11 +958,11 @@
   Role::_error(msg);
 
   if (errorLocator) {
-    ostrstream str2;
-    str2 << "ERROR: " << msg << ends;
-    errorLocator->arena_message_enq(str2.str(),NULL,ROLE_FAILED_TIME);
+    stringstream str2;
+    str2 << "ERROR: " << msg;
+    errorLocator->arena_message_enq(Utils::strdup(str2.str().c_str()),NULL,ROLE_FAILED_TIME);
     // Don't delete str2.str(), give memory to the Locator.
-    errorLocator->message_enq(Utils::strdup(str2.str()));
+    errorLocator->message_enq(Utils::strdup(str2.str().c_str()));
   }
 #if WIN32
   // Only the client can afford to block on error messages.
@@ -986,11 +977,9 @@
   Role::_error(msg);
 
   if (errorLocator) {
-    ostrstream str2;
-    str2 << msg << ends;
-    errorLocator->arena_message_enq(str2.str());
+    errorLocator->arena_message_enq(Utils::strdup(msg));
     // Don't delete str2.str(), give memory to the Locator.
-    errorLocator->message_enq(Utils::strdup(str2.str()));
+    errorLocator->message_enq(Utils::strdup(msg));
   }
 }
 
@@ -1256,10 +1245,9 @@
   if (turn > turnMax) {
     turnMax = turn;
     if (echoPingPong) {
-      ostrstream str;
-      str << "PONG the server with turn " << turnMax << ends;
-      message(str.str());
-      delete str.str();
+      stringstream str;
+      str << "PONG the server with turn " << turnMax;
+      message(str.str().c_str());
     }
     // Tell server so it can free turn windows to send more data.
     XETP::send_pong(udpOut,turnMax);
@@ -1365,10 +1353,9 @@
         }
       }
       else {
-        ostrstream str;
-        str << "No context for classId " << classId << ends;
-        error(str.str());
-        delete str.str();
+        stringstream str;
+        str << "No context for classId " << classId;
+        error(str.str().c_str());
       }
     }
   }
@@ -1582,9 +1569,9 @@
     return Utils::strdup(clientName);
   }
 
-  ostrstream str;
-  str << '\"' << intel->get_name() << "\"@" << clientName << ends;
-  return str.str();
+  stringstream str;
+  str << '\"' << intel->get_name() << "\"@" << clientName;
+  return Utils::strdup(str.str().c_str());
 }
 
 
@@ -1695,11 +1682,10 @@
       }
     
 #ifdef SKIP_MESSAGES
-      ostrstream msg;
+      stringstream msg;
       msg << "Average delay is " << avg << " out of " 
-        << delaysNum << " samples." << ends;
+        << delaysNum << " samples.";
       server->message(msg.str());
-      delete msg.str();
 #endif
 
 #if 0
@@ -1723,10 +1709,9 @@
 //            server->error("Client has reached maximum skip value.");
 //          }
 #ifdef SKIP_MESSAGES
-        ostrstream msg;
-        msg << "Increasing skip to " << skip << ends;
+        stringstream msg;
+        msg << "Increasing skip to " << skip;
         server->message(msg.str());
-        delete msg.str();
 #endif
       }
       // We have moved back into our target range, can send more data now.
@@ -1734,10 +1719,9 @@
         skip--;
 
 #ifdef SKIP_MESSAGES
-        ostrstream msg;
-        msg << "Decreasing skip to " << skip << ends;
+        stringstream msg;
+        msg << "Decreasing skip to " << skip;
         server->message(msg.str());
-        delete msg.str();
 #endif
       }
 
@@ -1777,7 +1761,7 @@
 
 
 
-Server::Server(Boolean lHuman,char *portName,LocatorP errLocator) {
+Server::Server(Boolean lHuman,const char *portName,LocatorP errLocator) {
   // Hack, using errLocator for more than reporting errors.
   errLocator->set_remember_deleted(True);
   errLocator->set_remember_sounds(True); 
@@ -1842,20 +1826,18 @@ void Server::run() {
   serverAddr.sin_port = htons(port);
 
   // Give address to both the TCP and UDP sockets.
-  if (bind(tcpSock, (CMN_SOCKADDR *)&serverAddr, sizeof(serverAddr)) < 0) {
-    ostrstream str;
+  if (::bind(tcpSock, (CMN_SOCKADDR *)&serverAddr, sizeof(serverAddr)) < 0) {
+    stringstream str;
     str << "Couldn't bind socket name to TCP socket on port " 
-        << port << "."  << ends;
-    error(str.str());
-    delete str.str();
+        << port << ".";
+    error(str.str().c_str());
     return;
   }
-  if (bind(udpSock, (CMN_SOCKADDR *)&serverAddr, sizeof(serverAddr)) < 0) {
-    ostrstream str;
+  if (::bind(udpSock, (CMN_SOCKADDR *)&serverAddr, sizeof(serverAddr)) < 0) {
+    stringstream str;
     str << "Couldn't bind socket name to UDP socket on port " 
-        << port << "."  << ends;
-    error(str.str());
-    delete str.str();
+        << port << ".";
+    error(str.str().c_str());
     return;
   }
 
@@ -1868,10 +1850,9 @@
   assert(udpIn);
 
   // Message to server log.
-  strstream msg;
-  msg << "Set up server on port " << port << ends;
-  message(msg.str());
-  delete(msg.str());
+  stringstream msg;
+  msg << "Set up server on port " << port;
+  message(msg.str().c_str());
 
   running = True;
 }
@@ -1951,10 +1932,9 @@
     localHumanId = hId;
 
     // Log the human's name.
-    strstream msg;
-    msg << "Player 0 \"" << human->get_name() << '\"' << "@SERVER" << ends;
-    message(msg.str());
-    delete(msg.str());
+    stringstream msg;
+    msg << "Player 0 \"" << human->get_name() << '\"' << "@SERVER";
+    message(msg.str().c_str());
 
     return;
   }
@@ -1985,12 +1965,11 @@
 
   // Log all the players in the game, some code duplication for the
   // local human.
-  ostrstream str;
+  stringstream str;
   char* fullName = cn->get_full_client_name();
-  str << "Player " << num << " " << fullName << ends;
-  message(str.str());
+  str << "Player " << num << " " << fullName;
+  message(str.str().c_str());
   delete fullName;
-  delete str.str();
   
   // Send assign_intel via TCP
   OutStreamP out = cn->get_tcp_out_stream();
@@ -2007,13 +1986,12 @@
     // anyway.
     for (m = 0; m < connections.length() && m != n; m++) {
       char* fullName = cn->get_full_client_name();
-      ostrstream str;
-      str << fullName << " has joined the game" << ends;
+      stringstream str;
+      str << fullName << " has joined the game";
       delete fullName;
 
       OutStreamP out = cn->get_udp_out_stream();
-      XETP::send_arena_message(out,timeMS,str.str());
-      delete str.str();
+      XETP::send_arena_message(out,timeMS,str.str().c_str());
     }
     cn->creation_message_sent();
   }
@@ -2101,13 +2079,12 @@
           // Give the connection some slack when it is first starting up.
           turn - cn->get_start_turn() >= MINIMUM_CUTOFF) {
         char* fullName = cn->get_full_client_name();
-        ostrstream str;
+        stringstream str;
         str << fullName
             << " has not responded in "
-            << diff << " turns.  Disconnect." << ends;
-        message(str.str());
+            << diff << " turns.  Disconnect.";
+        message(str.str().c_str());
         delete fullName;
-        delete str.str();
         tooOld = True;
       }
     }
@@ -2147,11 +2124,10 @@
           diff == NO_ACTIVITY_WARN_2 ||
           diff == NO_ACTIVITY_WARN_3) {
         if (echoPingPong) {
-          ostrstream str;
+          stringstream str;
           str << "Haven't heard from " << cn->get_client_name()
-              << " in " << diff << " turns, sending PING." << ends;
-          message(str.str());
-          delete str.str();
+              << " in " << diff << " turns, sending PING.";
+          message(str.str().c_str());
         }
         XETP::send_ping(cn->get_udp_out_stream());
       }
@@ -2311,7 +2287,11 @@
   for (m = 0; m < followers.length(); m++) {
     PhysicalP q = (PhysicalP)followers.get(m);
     netData = q->get_net_data();
-    assert(!netData->get_sent_flag());
+    // This line was aborting network games, often in the pound scenario.
+    // Without it, the server seems to continue without error.
+    // I tried replacing it with a warning, but there is so much of it
+    // that it is nearly impossible to see anything else. -Brandon
+//  assert(!netData->get_sent_flag());
     netData->set_sent_flag(True);
   }
 
@@ -2713,9 +2693,9 @@
   // Careful to set the propagate flag to False so the message doesn't get
   // sent to the clients.
   if (errorLocator) {
-    ostrstream str2;
-    str2 << "SERVER: " << msg << ends;
-    errorLocator->arena_message_enq(str2.str(),NULL,ROLE_FAILED_TIME,False);
+    stringstream str2;
+    str2 << "SERVER: " << msg;
+    errorLocator->arena_message_enq(Utils::strdup(str2.str().c_str()),NULL,ROLE_FAILED_TIME,False);
     // Don't delete str2.str(), give memory to the Locator.
 
     // Could do a regular message_enq(), but would have to deal with the
@@ -2728,10 +2708,9 @@
 void Server::display_chat_message(LocatorP l,const char* sender,
                                   const char* msg) {
   // Log the chat message, then let Role handle it.
-  strstream logMsg;
-  logMsg << '<' << sender << '>' << msg << ends;
-  message(logMsg.str());
-  delete logMsg.str();
+  stringstream logMsg;
+  logMsg << '<' << sender << '>' << msg;
+  message(logMsg.str().c_str());
 
   Role::display_chat_message(l,sender,msg);
 }
@@ -2851,12 +2830,11 @@
   udpAddr->sin_port = htons(udpPort);
 
   // Log the connection.
-  strstream msg;
+  stringstream msg;
   msg << clientName <<
 	" connected (TCP port " << ntohs(tcpAddr.sin_port) << 
-    ", UDP port " << udpPort << ")" << ends;
-  message(msg.str());
-  delete(msg.str());
+    ", UDP port " << udpPort << ")";
+  message(msg.str().c_str());
 
   Connection* cn =   
     new Connection(this,errorLocator,
@@ -2874,7 +2852,7 @@
   XETP::send_reset(out,manager->get_game_style_type());
 
   // Say hello to the new client.
-  ostrstream greeting;
+  stringstream greeting;
   greeting << "Welcome to " << hostName << ".";
 
   if (get_humans_num() == 1) {
@@ -2884,10 +2862,8 @@
     greeting << " There are now " 
              << get_humans_num() << " players.";
   }
-  greeting << ends;
   int timeMS = quantaToMS(UI_ARENA_MESSAGE_TIME,manager);  
-  XETP::send_arena_message(out,timeMS,greeting.str());
-  delete greeting.str();
+  XETP::send_arena_message(out,timeMS,greeting.str().c_str());
 
   manager->humans_num_incremented();
 }
@@ -2918,18 +2894,16 @@
       Connection* cm = get_connection(m);
 
       char* fullName = cn->get_full_client_name();
-      ostrstream str;
+      stringstream str;
       str << fullName << " has disconnected";
       if (intel) {
         str << ", " << kills << " human kills";
       }
-      str << ends;
       XETP::send_arena_message(cm->get_udp_out_stream(),
-                               timeMS,str.str());
+                               timeMS,str.str().c_str());
 
 
       delete fullName;
-      delete str.str();
     }
   }
 
@@ -3262,8 +3236,8 @@
 void Server::send_udp_server_pong(IGameManager* manager,LocatorP locator,
                                   CMN_SOCKET udpSock,
                                   CMN_SOCKADDR_IN* destAddr) {
-  static char* unknownString = "<unknown>";
-  static char* serverString = "<server>";
+  static const char* unknownString = "<unknown>";
+  static const char* serverString = "<server>";
 
 
   // Temporary stream.
