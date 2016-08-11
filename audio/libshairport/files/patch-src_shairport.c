--- src/shairport.c.orig	2011-08-20 23:57:56 UTC
+++ src/shairport.c
@@ -31,6 +31,27 @@
 #include "shairport.h"
 #include "hairtunes.h"
 
+static struct printfPtr g_printf={NULL};
+
+int xprintf(const char *format, ...)
+{
+  char dbg[2048];
+  va_list args;
+  va_start(args, format);
+  vsnprintf(dbg, sizeof(dbg), format, args);
+  va_end(args);
+  if(g_printf.extprintf)
+  {
+    g_printf.extprintf(dbg, sizeof(dbg));
+  }
+  else 
+  {
+    printf(dbg);
+  }
+
+  return 1;
+}
+
 #ifndef TRUE
 #define TRUE (-1)
 #endif
@@ -92,13 +113,26 @@ static struct addrinfo *tAddrInfo;
 static char tPassword[56] = "";
 static char tHWID[HWID_SIZE] = {0,51,52,53,54,55};
 
+#ifdef XBMC
+struct AudioOutput g_ao;
+void shairport_set_ao(struct AudioOutput *ao)
+{
+ g_ao=*ao;
+}
+
+void shairport_set_printf(struct printfPtr *funcPtr)
+{
+  g_printf = *funcPtr;
+}
+#endif
+
 #ifndef XBMC
 int main(int argc, char **argv)
 #else
 int shairport_main(int argc, char **argv)
 #endif
 {
-  printf("initializing shairport\n");
+  xprintf("initializing shairport\n",NULL);
   char tHWID_Hex[HWID_SIZE * 2 + 1];
   char tKnownHwid[32];
 
@@ -177,22 +211,22 @@ int shairport_main(int argc, char **argv
     }    
     else if(!strcmp(arg, "-h") || !strcmp(arg, "--help"))
     {
-      slog(LOG_INFO, "ShairPort version 0.05 C port - Airport Express emulator\n");
-      slog(LOG_INFO, "Usage:\nshairport [OPTION...]\n\nOptions:\n");
-      slog(LOG_INFO, "  -a, --apname=AirPort    Sets Airport name\n");
-      slog(LOG_INFO, "  -p, --password=secret   Sets Password (not working)\n");
-      slog(LOG_INFO, "  -o, --server_port=5000  Sets Port for Avahi/dns-sd\n");
-      slog(LOG_INFO, "  -b, --buffer=282        Sets Number of frames to buffer before beginning playback\n");
-      slog(LOG_INFO, "  -d                      Daemon mode\n");
-      slog(LOG_INFO, "  -q, --quiet             Supresses all output.\n");
-      slog(LOG_INFO, "  -v,-v2,-v3,-vv          Various debugging levels\n");
-      slog(LOG_INFO, "\n");
+      xprintf("ShairPort version 0.05 C port - Airport Express emulator\n");
+      xprintf("Usage:\nshairport [OPTION...]\n\nOptions:\n");
+      xprintf("  -a, --apname=AirPort    Sets Airport name\n");
+      xprintf("  -p, --password=secret   Sets Password (not working)\n");
+      xprintf("  -o, --server_port=5000  Sets Port for Avahi/dns-sd\n");
+      xprintf("  -b, --buffer=282        Sets Number of frames to buffer before beginning playback\n");
+      xprintf("  -d                      Daemon mode\n");
+      xprintf("  -q, --quiet             Supresses all output.\n");
+      xprintf("  -v,-v2,-v3,-vv          Various debugging levels\n");
+      xprintf("\n");
       return 0;
     }    
   }
 
   if ( buffer_start_fill < 30 || buffer_start_fill > BUFFER_FRAMES ) { 
-     fprintf(stderr, "buffer value must be > 30 and < %d\n", BUFFER_FRAMES);
+     xprintf("buffer value must be > 30 and < %d\n", BUFFER_FRAMES);
      return(0);
   }
 
@@ -201,11 +235,11 @@ int shairport_main(int argc, char **argv
     int tPid = fork();
     if(tPid < 0)
     {
-      exit(1); // Error on fork
+      //exit(1); // Error on fork
     }
     else if(tPid > 0)
     {
-      exit(0);
+      //exit(0);
     }
     else
     {
@@ -246,10 +280,10 @@ int shairport_main(int argc, char **argv
     sscanf(tHWID_Hex, "%02X%02X%02X%02X%02X%02X", &tHWID[0], &tHWID[1], &tHWID[2], &tHWID[3], &tHWID[4], &tHWID[5]);
   }
 
-  slog(LOG_INFO, "LogLevel: %d\n", kCurrentLogLevel);
-  slog(LOG_INFO, "AirName: %s\n", tServerName);
-  slog(LOG_INFO, "HWID: %.*s\n", HWID_SIZE, tHWID+1);
-  slog(LOG_INFO, "HWID_Hex(%d): %s\n", strlen(tHWID_Hex), tHWID_Hex);
+  xprintf("LogLevel: %d\n", kCurrentLogLevel);
+  xprintf("AirName: %s\n", tServerName);
+  xprintf("HWID: %.*s\n", HWID_SIZE, tHWID+1);
+  xprintf("HWID_Hex(%d): %s\n", strlen(tHWID_Hex), tHWID_Hex);
 
   if(tSimLevel >= 1)
   {
@@ -263,12 +297,12 @@ int shairport_main(int argc, char **argv
 #ifndef XBMC
     startAvahi(tHWID_Hex, tServerName, tPort);
 #endif
-    slog(LOG_DEBUG_V, "Starting connection server: specified server port: %d\n", tPort);
+    xprintf("Starting connection server: specified server port: %d\n", tPort);
     tServerSock = setupListenServer(&tAddrInfo, tPort);
     if(tServerSock < 0)
     {
       freeaddrinfo(tAddrInfo);
-      slog(LOG_INFO, "Error setting up server socket on port %d, try specifying a different port\n", tPort);
+      xprintf("Error setting up server socket on port %d, try specifying a different port\n", tPort);
       return 0;
     }
 
@@ -295,7 +329,7 @@ int shairport_loop(void)
 
     int readsock;
 
-    slog(LOG_DEBUG_V, "Waiting for clients to connect\n");
+    xprintf("Waiting for clients to connect\n");
 
     while(m_running)
     {
@@ -327,7 +361,7 @@ int shairport_loop(void)
         {
           freeaddrinfo(tAddrInfo);
           tAddrInfo = NULL;
-          slog(LOG_DEBUG, "...Accepted Client Connection..\n");
+          xprintf("...Accepted Client Connection..\n");
           close(tServerSock);
           handleClient(tClientSock, tPassword, tHWID);
           //close(tClientSock);
@@ -335,11 +369,11 @@ int shairport_loop(void)
         }
         else
         {
-          slog(LOG_DEBUG_VV, "Child now busy handling new client\n");
+          xprintf("Child now busy handling new client\n");
           close(tClientSock);
         }
 #else
-      slog(LOG_DEBUG, "...Accepted Client Connection..\n");
+      xprintf("...Accepted Client Connection..\n");
       handleClient(tClientSock, tPassword, tHWID);
 #endif
       }
@@ -349,7 +383,7 @@ int shairport_loop(void)
       }
   }
 
-  slog(LOG_DEBUG_VV, "Finished\n");
+  xprintf("Finished\n");
   if(tAddrInfo != NULL)
   {
     freeaddrinfo(tAddrInfo);
@@ -360,6 +394,7 @@ int shairport_loop(void)
 void shairport_exit(void)
 {
   m_running = 0;
+  close(tServerSock);
 }
 
 int shairport_is_running(void)
@@ -407,7 +442,7 @@ int findEnd(char *tReadBuf)
 
 void handleClient(int pSock, char *pPassword, char *pHWADDR)
 {
-  slog(LOG_DEBUG_VV, "In Handle Client\n");
+  xprintf("In Handle Client\n");
   fflush(stdout);
 
   socklen_t len;
@@ -426,7 +461,7 @@ void handleClient(int pSock, char *pPass
 
   // deal with both IPv4 and IPv6:
   if (addr.ss_family == AF_INET) {
-      slog(LOG_DEBUG_V, "Constructing ipv4 address\n");
+      xprintf("Constructing ipv4 address\n");
       struct sockaddr_in *s = (struct sockaddr_in *)&addr;
       port = ntohs(s->sin_port);
       inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
@@ -446,20 +481,20 @@ void handleClient(int pSock, char *pPass
       if(memcmp(&addr.bin[0], "\x00\x00\x00\x00" "\x00\x00\x00\x00" "\x00\x00\xff\xff", 12) == 0)
       {
         // its ipv4...
-        slog(LOG_DEBUG_V, "Constructing ipv4 from ipv6 address\n");
+        xprintf("Constructing ipv4 from ipv6 address\n");
         memcpy(ipbin, &addr.bin[12], 4);
         ipbinlen = 4;
       }
       else
       {
-        slog(LOG_DEBUG_V, "Constructing ipv6 address\n");
+        xprintf("Constructing ipv6 address\n");
         memcpy(ipbin, &s->sin6_addr, 16);
         ipbinlen = 16;
       }
   }
 
-  slog(LOG_DEBUG_V, "Peer IP address: %s\n", ipstr);
-  slog(LOG_DEBUG_V, "Peer port      : %d\n", port);
+  xprintf("Peer IP address: %s\n", ipstr);
+  xprintf("Peer port      : %d\n", port);
 
   int tMoreDataNeeded = 1;
   struct keyring     tKeys;
@@ -478,18 +513,19 @@ void handleClient(int pSock, char *pPass
     while(1 == tMoreDataNeeded)
     {
       tError = readDataFromClient(pSock, &(tConn.recv));
-      if(!tError && strlen(tConn.recv.data) > 0)
+      //if(!tError && strlen(tConn.recv.data) > 0)
+      if(!tError && tConn.recv.current > 0)
       {
-        slog(LOG_DEBUG_VV, "Finished Reading some data from client\n");
+        xprintf("Finished Reading some data from client\n");
         // parse client request
         tMoreDataNeeded = parseMessage(&tConn, ipbin, ipbinlen, pHWADDR);
         if(1 == tMoreDataNeeded)
         {
-          slog(LOG_DEBUG_VV, "\n\nNeed to read more data\n");
+          xprintf("\n\nNeed to read more data\n");
         }
         else if(-1 == tMoreDataNeeded) // Forked process down below ended.
         {
-          slog(LOG_DEBUG_V, "Forked Process ended...cleaning up\n");
+          xprintf("Forked Process ended...cleaning up\n");
           cleanup(&tConn);
           // pSock was already closed
           return;
@@ -498,13 +534,13 @@ void handleClient(int pSock, char *pPass
       }
       else
       {
-        slog(LOG_DEBUG, "Error reading from socket, closing client\n");
+        xprintf("Error reading from socket, closing client\n");
         // Error reading data....quit.
         cleanup(&tConn);
         return;
       }
     }
-    slog(LOG_DEBUG_VV, "Writing: %d chars to socket\n", tConn.resp.current);
+    xprintf("Writing: %d chars to socket\n", tConn.resp.current);
     //tConn->resp.data[tConn->resp.current-1] = '\0';
     writeDataToClient(pSock, &(tConn.resp));
    // Finished reading one message...
@@ -517,9 +553,9 @@ void handleClient(int pSock, char *pPass
 
 void writeDataToClient(int pSock, struct shairbuffer *pResponse)
 {
-  slog(LOG_DEBUG_VV, "\n----Beg Send Response Header----\n%.*s\n", pResponse->current, pResponse->data);
+  xprintf("\n----Beg Send Response Header----\n%.*s\n", pResponse->current, pResponse->data);
   send(pSock, pResponse->data, pResponse->current,0);
-  slog(LOG_DEBUG_VV, "----Send Response Header----\n");
+  xprintf("----Send Response Header----\n");
 }
 
 int readDataFromClient(int pSock, struct shairbuffer *pClientBuffer)
@@ -532,7 +568,7 @@ int readDataFromClient(int pSock, struct
   while(tRetval > 0 && tEnd < 0)
   {
      // Read from socket until \n\n, \r\n\r\n, or \r\r is found
-      slog(LOG_DEBUG_V, "Waiting To Read...\n");
+      xprintf("Waiting To Read...\n");
       fflush(stdout);
       tRetval = read(pSock, tReadBuf, MAX_SIZE);
       // if new buffer contains the end of request string, only copy partial buffer?
@@ -543,40 +579,40 @@ int readDataFromClient(int pSock, struct
         {
           pClientBuffer->marker = tEnd+1; // Marks start of content
         }
-        slog(SOCKET_LOG_LEVEL, "Found end of http request at: %d\n", tEnd);
+        xprintf("Found end of http request at: %d\n", tEnd);
         fflush(stdout);        
       }
       else
       {
         tEnd = MAX_SIZE;
-        slog(SOCKET_LOG_LEVEL, "Read %d of data so far\n%s\n", tRetval, tReadBuf);
+        xprintf("Read %d of data so far\n%s\n", tRetval, tReadBuf);
         fflush(stdout);
       }
       if(tRetval > 0)
       {
         // Copy read data into tReceive;
-        slog(SOCKET_LOG_LEVEL, "Read %d data, using %d of it\n", tRetval, tEnd);
+        xprintf("Read %d data, using %d of it\n", tRetval, tEnd);
         addNToShairBuffer(pClientBuffer, tReadBuf, tRetval);
-        slog(LOG_DEBUG_VV, "Finished copying data\n");
+        xprintf("Finished copying data\n");
       }
       else
       {
-        slog(LOG_DEBUG, "Error reading data from socket, got: %d bytes", tRetval);
+        xprintf("Error reading data from socket, got: %d bytes", tRetval);
         return tRetval;
       }
   }
   if(tEnd + 1 != tRetval)
   {
-    slog(SOCKET_LOG_LEVEL, "Read more data after end of http request. %d instead of %d\n", tRetval, tEnd+1);
+    xprintf("Read more data after end of http request. %d instead of %d\n", tRetval, tEnd+1);
   }
-  slog(SOCKET_LOG_LEVEL, "Finished Reading Data:\n%s\nEndOfData\n", pClientBuffer->data);
+  xprintf("Finished Reading Data:\n%s\nEndOfData\n", pClientBuffer->data);
   fflush(stdout);
   return 0;
 }
 
 char *getFromBuffer(char *pBufferPtr, const char *pField, int pLenAfterField, int *pReturnSize, char *pDelims)
 {
-  slog(LOG_DEBUG_V, "GettingFromBuffer: %s\n", pField);
+  xprintf("GettingFromBuffer: %s\n", pField);
   char* tFound = strstr(pBufferPtr, pField);
   int tSize = 0;
   if(tFound != NULL)
@@ -597,7 +633,7 @@ char *getFromBuffer(char *pBufferPtr, co
     }
     
     tSize = (int) (tShortest - tFound);
-    slog(LOG_DEBUG_VV, "Found %.*s  length: %d\n", tSize, tFound, tSize);
+    xprintf("Found %s  length: %d\n",tFound, tSize);
     if(pReturnSize != NULL)
     {
       *pReturnSize = tSize;
@@ -605,7 +641,7 @@ char *getFromBuffer(char *pBufferPtr, co
   }
   else
   {
-    slog(LOG_DEBUG_V, "Not Found\n");
+    xprintf("Not Found\n");
   }
   return tFound;
 }
@@ -639,10 +675,10 @@ int buildAppleResponse(struct connection
   {
     char tTrim[tFoundSize + 2];
     getTrimmed(tFound, tFoundSize, TRUE, TRUE, tTrim);
-    slog(LOG_DEBUG_VV, "HeaderChallenge:  [%s] len: %d  sizeFound: %d\n", tTrim, strlen(tTrim), tFoundSize);
+    xprintf("HeaderChallenge:  [%s] len: %d  sizeFound: %d\n", tTrim, strlen(tTrim), tFoundSize);
     int tChallengeDecodeSize = 16;
     char *tChallenge = decode_base64((unsigned char *)tTrim, tFoundSize, &tChallengeDecodeSize);
-    slog(LOG_DEBUG_VV, "Challenge Decode size: %d  expected 16\n", tChallengeDecodeSize);
+    xprintf("Challenge Decode size: %d  expected 16\n", tChallengeDecodeSize);
 
     int tCurSize = 0;
     unsigned char tChalResp[38];
@@ -664,7 +700,7 @@ int buildAppleResponse(struct connection
     }
 
     char *tTmp = encode_base64((unsigned char *)tChalResp, tCurSize);
-    slog(LOG_DEBUG_VV, "Full sig: %s\n", tTmp);
+    xprintf("Full sig: %s\n", tTmp);
     free(tTmp);
 
     // RSA Encrypt
@@ -709,15 +745,15 @@ int parseMessage(struct connection *pCon
   if(tContent != NULL)
   {
     int tContentSize = atoi(tContent);
-    if(pConn->recv.marker == 0 || strlen(pConn->recv.data+pConn->recv.marker) != tContentSize)
+    if(pConn->recv.marker == 0 || pConn->recv.current-pConn->recv.marker != tContentSize)
     {
       if(isLogEnabledFor(HEADER_LOG_LEVEL))
       {
-        slog(HEADER_LOG_LEVEL, "Content-Length: %s value -> %d\n", tContent, tContentSize);
+        xprintf("Content-Length: %s value -> %d\n", tContent, tContentSize);
         if(pConn->recv.marker != 0)
         {
-          slog(HEADER_LOG_LEVEL, "ContentPtr has %d, but needs %d\n", 
-                  strlen(pConn->recv.data+pConn->recv.marker), tContentSize);
+          xprintf("ContentPtr has %d, but needs %d\n", 
+                  (pConn->recv.current-pConn->recv.marker), tContentSize);
         }
       }
       // check if value in tContent > 2nd read from client.
@@ -726,7 +762,7 @@ int parseMessage(struct connection *pCon
   }
   else
   {
-    slog(LOG_DEBUG_VV, "No content, header only\n");
+    xprintf("No content, header only\n");
   }
 
   // "Creates" a new Response Header for our response message
@@ -739,7 +775,7 @@ int parseMessage(struct connection *pCon
     {
       tLen = 20;
     }
-    slog(LOG_INFO, "********** RECV %.*s **********\n", tLen, pConn->recv.data);
+    xprintf("********** RECV %.*s **********\n", tLen, pConn->recv.data);
   }
 
   if(pConn->password != NULL)
@@ -749,7 +785,7 @@ int parseMessage(struct connection *pCon
 
   if(buildAppleResponse(pConn, pIpBin, pIpBinLen, pHWID)) // need to free sig
   {
-    slog(LOG_DEBUG_V, "Added AppleResponse to Apple-Challenge request\n");
+    xprintf("Added AppleResponse to Apple-Challenge request\n");
   }
 
   // Find option, then based on option, do different actions.
@@ -769,14 +805,14 @@ int parseMessage(struct connection *pCon
       int tKeySize = 0;
       char tEncodedAesIV[tSize + 2];
       getTrimmed(tHeaderVal, tSize, TRUE, TRUE, tEncodedAesIV);
-      slog(LOG_DEBUG_VV, "AESIV: [%.*s] Size: %d  Strlen: %d\n", tSize, tEncodedAesIV, tSize, strlen(tEncodedAesIV));
+      xprintf("AESIV: [%.*s] Size: %d  Strlen: %d\n", tSize, tEncodedAesIV, tSize, strlen(tEncodedAesIV));
       char *tDecodedIV =  decode_base64((unsigned char*) tEncodedAesIV, tSize, &tSize);
 
       // grab the key, copy it out of the receive buffer
       tHeaderVal = getFromContent(tContent, "a=rsaaeskey", &tKeySize);
       char tEncodedAesKey[tKeySize + 2]; // +1 for nl, +1 for \0
       getTrimmed(tHeaderVal, tKeySize, TRUE, TRUE, tEncodedAesKey);
-      slog(LOG_DEBUG_VV, "AES KEY: [%s] Size: %d  Strlen: %d\n", tEncodedAesKey, tKeySize, strlen(tEncodedAesKey));
+      xprintf("AES KEY: [%s] Size: %d  Strlen: %d\n", tEncodedAesKey, tKeySize, strlen(tEncodedAesKey));
       // remove base64 coding from key
       char *tDecodedAesKey = decode_base64((unsigned char*) tEncodedAesKey,
                               tKeySize, &tKeySize);  // Need to free DecodedAesKey
@@ -785,7 +821,7 @@ int parseMessage(struct connection *pCon
       int tFmtpSize = 0;
       char *tFmtp = getFromContent(tContent, "a=fmtp", &tFmtpSize);  // Don't need to free
       tFmtp = getTrimmedMalloc(tFmtp, tFmtpSize, TRUE, FALSE); // will need to free
-      slog(LOG_DEBUG_VV, "Format: %s\n", tFmtp);
+      xprintf("Format: %s\n", tFmtp);
 
       RSA *rsa = loadKey();
       // Decrypt the binary aes key
@@ -794,11 +830,11 @@ int parseMessage(struct connection *pCon
       if(RSA_private_decrypt(tKeySize, (unsigned char *)tDecodedAesKey, 
       (unsigned char*) tDecryptedKey, rsa, RSA_PKCS1_OAEP_PADDING) >= 0)
       {
-        slog(LOG_DEBUG, "Decrypted AES key from RSA Successfully\n");
+        xprintf("Decrypted AES key from RSA Successfully\n");
       }
       else
       {
-        slog(LOG_INFO, "Error Decrypting AES key from RSA\n");
+        xprintf("Error Decrypting AES key from RSA\n");
       }
       free(tDecodedAesKey);
       RSA_free(rsa);
@@ -814,13 +850,13 @@ int parseMessage(struct connection *pCon
 //    struct comms *tComms = pConn->hairtunes;
 //   if (! (pipe(tComms->in) == 0 && pipe(tComms->out) == 0))
 //    {
-//      slog(LOG_INFO, "Error setting up hairtunes communications...some things probably wont work very well.\n");
+//      xprintf("Error setting up hairtunes communications...some things probably wont work very well.\n");
 //    }
     
     // Setup fork
     char tPort[8] = "6000";  // get this from dup()'d stdout of child pid
 
-    printf("******** SETUP!!!!!\n");
+    xprintf("******** SETUP!!!!!\n",NULL);
 #ifndef XBMC
     int tPid = fork();
     if(tPid == 0)
@@ -836,11 +872,11 @@ int parseMessage(struct connection *pCon
       tFound = getFromSetup(pConn->recv.data, "timing_port", &tSize);
       getTrimmed(tFound, tSize, 1, 0, tTPortStr);
 
-      slog(LOG_DEBUG_VV, "converting %s and %s from str->int\n", tCPortStr, tTPortStr);
+      xprintf("converting %s and %s from str->int\n", tCPortStr, tTPortStr);
       int tControlport = atoi(tCPortStr);
       int tTimingport = atoi(tTPortStr);
 
-      slog(LOG_DEBUG_V, "Got %d for CPort and %d for TPort\n", tControlport, tTimingport);
+      xprintf("Got %d for CPort and %d for TPort\n", tControlport, tTimingport);
       char *tRtp = NULL;
       char *tPipe = NULL;
       char *tAoDriver = NULL;
@@ -875,7 +911,7 @@ int parseMessage(struct connection *pCon
                       tDataport, tRtp, tPipe, tAoDriver, tAoDeviceName, tAoDeviceId);
 #ifndef XBMC
       // Quit when finished.
-      slog(LOG_DEBUG, "Returned from hairtunes init....returning -1, should close out this whole side of the fork\n");
+      xprintf("Returned from hairtunes init....returning -1, should close out this whole side of the fork\n");
       return -1;
     }
     else if(tPid >0)
@@ -888,7 +924,7 @@ int parseMessage(struct connection *pCon
       int tRead = read(tComms->out[0], tFromHairtunes, 80);
       if(tRead <= 0)
       {
-        slog(LOG_INFO, "Error reading port from hairtunes function, assuming default port: %d\n", tPort);
+        xprintf("Error reading port from hairtunes function, assuming default port: %d\n", tPort);
       }
       else
       {
@@ -900,7 +936,7 @@ int parseMessage(struct connection *pCon
         }
         else
         {
-          slog(LOG_INFO, "Read %d bytes, Error translating %s into a port\n", tRead, tFromHairtunes);
+          xprintf("Read %d bytes, Error translating %s into a port\n", tRead, tFromHairtunes);
         }
       }
 
@@ -921,7 +957,7 @@ int parseMessage(struct connection *pCon
     }
     else
     {
-      slog(LOG_INFO, "Error forking process....dere' be errors round here.\n");
+      xprintf("Error forking process....dere' be errors round here.\n");
       return -1;
     }
 #endif
@@ -933,7 +969,7 @@ int parseMessage(struct connection *pCon
     propogateCSeq(pConn);
 #ifndef XBMC
     close(pConn->hairtunes->in[1]);
-    slog(LOG_DEBUG, "Tearing down connection, closing pipes\n");
+    xprintf("Tearing down connection, closing pipes\n");
 #else
     hairtunes_cleanup();
 #endif
@@ -954,21 +990,73 @@ int parseMessage(struct connection *pCon
   {
     propogateCSeq(pConn);
     int tSize = 0;
+    char *buffer = NULL;
+    char *contentType = getFromHeader(pConn->recv.data, "Content-Type", &tSize);
+    char *tContent = getFromHeader(pConn->recv.data, "Content-Length", NULL);
+    int iContentSize = 0;
+    int isJpg = 0;
+    
+    if(tContent != NULL)
+    {
+      iContentSize = atoi(tContent);
+    }
+
+    if( tSize > 1 && 
+        (strncmp(contentType, "application/x-dmap-tagged", tSize) == 0) ||
+        (strncmp(contentType, "image/jpeg", tSize) == 0)                 )
+    {
+      if( (pConn->recv.current - pConn->recv.marker) == iContentSize && pConn->recv.marker != 0)
+      {
+        if(strncmp(contentType, "image/jpeg", tSize) == 0)
+        {
+          isJpg = 1;
+        }
+        buffer = (char *)malloc(iContentSize * sizeof(char));
+        memcpy(buffer, pConn->recv.data + pConn->recv.marker, iContentSize);                                                                                                                                     
+      }
+      else
+      {
+        iContentSize = 0;
+      }
+    }
+    else
+    {
+      iContentSize = 0;
+    }
     char *tVol = getFromHeader(pConn->recv.data, "volume", &tSize);
-    slog(LOG_DEBUG_VV, "About to write [vol: %.*s] data to hairtunes\n", tSize, tVol);
+    if( tVol)
+    {
+      xprintf("About to write [vol: %.*s] data to hairtunes\n", tSize, tVol);
+    }
     // TBD VOLUME
 #ifndef XBMC
     write(pConn->hairtunes->in[1], "vol: ", 5);
     write(pConn->hairtunes->in[1], tVol, tSize);
     write(pConn->hairtunes->in[1], "\n", 1);
 #else
-    hairtunes_setvolume(atof(tVol));
+    if(tVol)
+    {
+      hairtunes_setvolume(atof(tVol));
+    }
+    
+    if(iContentSize)
+    {
+      if(isJpg)
+      {
+        hairtunes_set_metadata_coverart(buffer, iContentSize);      
+      }
+      else
+      {
+        hairtunes_set_metadata(buffer, iContentSize);
+      }
+      free(buffer);
+    }
 #endif
-    slog(LOG_DEBUG_VV, "Finished writing data write data to hairtunes\n");
+    xprintf("Finished writing data write data to hairtunes\n");
   }
   else
   {
-    slog(LOG_DEBUG, "\n\nUn-Handled recv: %s\n", pConn->recv.data);
+    xprintf("\n\nUn-Handled recv: %s\n", pConn->recv.data);
     propogateCSeq(pConn);
   }
   addToShairBuffer(&(pConn->resp), "\r\n");
@@ -1047,7 +1135,7 @@ int startAvahi(const char *pHWStr, const
     char tName[100 + HWID_SIZE + 3];
     if(strlen(pServerName) > tMaxServerName)
     {
-      slog(LOG_INFO,"Hey dog, we see you like long server names, "
+      xprintf("Hey dog, we see you like long server names, "
               "so we put a strncat in our command so we don't buffer overflow, while you listen to your flow.\n"
               "We just used the first %d characters.  Pick something shorter if you want\n", tMaxServerName);
     }
@@ -1058,7 +1146,7 @@ int startAvahi(const char *pHWStr, const
     strcat(tName, pHWStr);
     strcat(tName, "@");
     strncat(tName, pServerName, tMaxServerName);
-    slog(AVAHI_LOG_LEVEL, "Avahi/DNS-SD Name: %s\n", tName);
+    xprintf("Avahi/DNS-SD Name: %s\n", tName);
     
     execlp("avahi-publish-service", "avahi-publish-service", tName,
          "_raop._tcp", tPort, "tp=UDP","sm=false","sv=false","ek=1","et=0,1",
@@ -1070,12 +1158,12 @@ int startAvahi(const char *pHWStr, const
             perror("error");
     }
 
-    slog(LOG_INFO, "Bad error... couldn't find or failed to run: avahi-publish-service OR dns-sd\n");
-    exit(1);
+    xprintf("Bad error... couldn't find or failed to run: avahi-publish-service OR dns-sd\n");
+    //exit(1);
   }
   else
   {
-    slog(LOG_DEBUG_VV, "Avahi/DNS-SD started on PID: %d\n", tPid);
+    xprintf("Avahi/DNS-SD started on PID: %d\n", tPid);
   }
   return tPid;
 }
@@ -1083,7 +1171,7 @@ int startAvahi(const char *pHWStr, const
 
 void printBufferInfo(struct shairbuffer *pBuf, int pLevel)
 {
-  slog(pLevel, "Buffer: [%s]  size: %d  maxchars:%d\n", pBuf->data, pBuf->current, pBuf->maxsize/sizeof(char));
+  xprintf("Buffer: [%s]  size: %d  maxchars:%d\n", pBuf->data, pBuf->current, pBuf->maxsize/sizeof(char));
 }
 
 int getAvailChars(struct shairbuffer *pBuf)
@@ -1164,7 +1252,8 @@ void slog(int pLevel, char *pFormat, ...
   {
     va_list argp;
     va_start(argp, pFormat);
-    vprintf(pFormat, argp);
+    xprintf(pFormat, argp);
+    //vprintf(pFormat, argp);
     va_end(argp);
   }
   //#endif
@@ -1218,9 +1307,9 @@ void initBuffer(struct shairbuffer *pBuf
 {
   if(pBuf->data != NULL)
   {
-    slog(LOG_DEBUG_VV, "Hrm, buffer wasn't cleaned up....trying to free\n");
+    xprintf("Hrm, buffer wasn't cleaned up....trying to free\n");
     free(pBuf->data);
-    slog(LOG_DEBUG_VV, "Free didn't seem to seg fault....huzzah\n");
+    xprintf("Free didn't seem to seg fault....huzzah\n");
   }
   pBuf->current = 0;
   pBuf->marker = 0;
@@ -1278,6 +1367,6 @@ RSA *loadKey()
   BIO *tBio = BIO_new_mem_buf(AIRPORT_PRIVATE_KEY, -1);
   RSA *rsa = PEM_read_bio_RSAPrivateKey(tBio, NULL, NULL, NULL); //NULL, NULL, NULL);
   BIO_free(tBio);
-  slog(RSA_LOG_LEVEL, "RSA Key: %d\n", RSA_check_key(rsa));
+  xprintf("RSA Key: %d\n", RSA_check_key(rsa));
   return rsa;
 }
