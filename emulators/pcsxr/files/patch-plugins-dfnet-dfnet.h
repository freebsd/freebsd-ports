--- plugins/dfnet/dfnet.h.orig	2020-09-07 22:26:23 UTC
+++ plugins/dfnet/dfnet.h
@@ -56,7 +56,7 @@ __private_extern char* PLUGLOC(char* toloc);
 
 typedef void* HWND;
 
-struct timeval tm;
+extern struct timeval tm;
 
 #define CALLBACK
 
@@ -70,24 +70,24 @@ typedef struct {
 	char ipAddress[32];
 } Config;
 
-Config conf;
+extern Config conf;
 
 void LoadConf();
 void SaveConf();
 
-int sock;
-char *PadSendData;
-char *PadRecvData;
-char PadSendSize;
-char PadRecvSize;
-char PadSize[2];
-int PadCount;
-int PadCountMax;
-int PadInit;
-int Ping;
-volatile int WaitCancel;
-fd_set rset;
-fd_set wset;
+extern int sock;
+extern char *PadSendData;
+extern char *PadRecvData;
+extern char PadSendSize;
+extern char PadRecvSize;
+extern char PadSize[2];
+extern int PadCount;
+extern int PadCountMax;
+extern int PadInit;
+extern int Ping;
+extern volatile int WaitCancel;
+extern fd_set rset;
+extern fd_set wset;
 
 long sockInit();
 long sockShutdown();
