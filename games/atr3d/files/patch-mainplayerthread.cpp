--- mainplayerthread.cpp.orig	2008-02-19 18:54:17.000000000 +0100
+++ mainplayerthread.cpp	2008-02-19 18:59:50.000000000 +0100
@@ -21,7 +21,7 @@
 void *MainPlayerThread(void *threadid);
 void SetupShipSendData(int shipnum, int threadnum, ShipDesc *ShipData);
 void SetupObjSendData(int objnum, struct ObjectDesc *ObjData);
-void SendPlayerData(int threadnum);
+void SendPlayerData(size_t threadnum);
 void SetupStatusSendData(char *GameStatus, int playernum);
 void TransferData(char *SendData, int *DataSize, int threadnum);
 
@@ -29,10 +29,10 @@
 void *MainPlayerThread(void *threadid)
 {
   int n, rc;
-  int threadnum;
+  size_t threadnum;
   pthread_t readthread;
 
-  threadnum=(int)threadid;
+  threadnum=(size_t)threadid;
 
   SendPlayerData(threadnum);
 
@@ -41,7 +41,7 @@
 
 
 // Main function which loops and continuously sends data to the player
-void SendPlayerData(int threadnum)
+void SendPlayerData(size_t threadnum)
 {
   int i, j;
   int DataSize=0;
@@ -53,7 +53,7 @@
   while(!StopServer) {
     pthread_mutex_lock(&ServerLock);
 #ifdef DEBUG
-    printf("Main Player Thread %d Awake\n", threadnum);
+    printf("Main Player Thread %zd Awake\n", threadnum);
 #endif
     if (!ServerShips[threadnum]) {
       pthread_mutex_unlock(&ServerLock);
