--- x11/serverping.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ x11/serverping.cpp	2012-05-27 07:12:12.000000000 +0900
@@ -25,14 +25,15 @@
 // code and should be reasonably easy to compile on Windows.
 
 
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <sstream>
 #include "utils.h"
 #include "streams.h"
 #include "xetp_basic.h"
 #include "neth.h"
 #include "id.h"
 
+using namespace std;
 
 
 class ServerPing {
@@ -113,7 +114,7 @@
 
 
   char* sString = argv[argc - 1];
-  char* port = Utils::strchr(sString,':');
+  const char* port = Utils::strchr(sString,':');
   // server:port
   if (port) {
     serverName = new char[port - sString + 1];
@@ -140,10 +141,9 @@
     error("Error opening client UDP socket.");
   }
   
-  ostrstream str;
-  str << "Looking up IP address for server " << serverName << ends;
-  message(str.str());
-  delete str.str();
+  stringstream str;
+  str << "Looking up IP address for server " << serverName;
+  message(str.str().c_str());
 
   // Create server address.
   memset((void *)&serverAddr,'\0',sizeof(serverAddr));
@@ -170,11 +170,10 @@ ServerPing::ServerPing(int argc,char** argv) {
   client.sin_family = AF_INET;
   client.sin_addr.s_addr = htonl(INADDR_ANY);
   client.sin_port = htons((u_short)clientPort);
-  if (bind(udpSock,(CMN_SOCKADDR *)&client,sizeof(client)) < 0) {
-    ostrstream str;
-    str << "Could not bind local UDP port " << clientPort << ends;
-    error(str.str());
-    delete str.str();
+  if (::bind(udpSock,(CMN_SOCKADDR *)&client,sizeof(client)) < 0) {
+    stringstream str;
+    str << "Could not bind local UDP port " << clientPort;
+    error(str.str().c_str());
     return;
   }
 
@@ -197,11 +196,10 @@
   // Send "count" number of SERVER_PINGs.
   for (int tries = 0; tries < count; tries++) {
     // Send the ping.
-    ostrstream msg;
+    stringstream msg;
     msg << "Sending XETP::SERVER_PING to " 
-        << serverName << ':' << serverPort << ends;
-    message(msg.str());
-    delete msg.str();
+        << serverName << ':' << serverPort;
+    message(msg.str().c_str());
     XETPBasic::send_server_ping(udpOut);
     // Don't buffer the ping.
     udpOut->flush();
@@ -248,11 +246,10 @@
   }
 
   // If we get here, we failed to reach the server.
-  ostrstream msg;
+  stringstream msg;
   msg << "No return from " << serverName << ':' << serverPort << " after " 
-      << count << " tries." << ends;
-  error(msg.str());
-  delete msg.str();
+      << count << " tries.";
+  error(msg.str().c_str());
 }
 
 
@@ -271,12 +268,9 @@
 
 
 void ServerPing::error(const char* msg1,const char* msg2) {
-  ostrstream str;
-  str << msg1 << msg2 << ends;
-  error(str.str());
-
-  // Will never get here, but WTF.
-  delete str.str();
+  stringstream str;
+  str << msg1 << msg2;
+  error(str.str().c_str());
 }
 
 
@@ -355,6 +349,7 @@
 
 
 
+int
 main(int argc,char** argv) {
   ServerPing ping(argc,argv);
   ping.go();
