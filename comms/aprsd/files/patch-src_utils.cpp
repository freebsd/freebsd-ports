--- src/utils.cpp.orig	2003-10-01 16:58:27 UTC
+++ src/utils.cpp
@@ -41,6 +41,7 @@ int CountDefault = 7;		   //Max of 7 instances of one 
 
 static RecursiveMutex pmtxLog;
 
+const string LOGPATH("/var/log/aprsd/");
 
 int WriteLog(const string& sp, const string& LogFile)
 {
@@ -50,11 +51,12 @@ int WriteLog(const string& sp, const string& LogFile)
     static Lock locker(pmtxLog, false);
 
     locker.get();
+    string pLogFile = LOGPATH + LogFile;
 
-    ofstream ofs(LogFile.c_str(), ios::out | ios::app);
+    ofstream ofs(pLogFile.c_str(), ios::out | ios::app);
 
     if (!ofs)
-        cerr << "File I/O Error: Unable to open/create file " << LogFile << endl;
+        cerr << "File I/O Error: Unable to open/create file " << pLogFile << endl;
 
     time(&ltime);                                       // Timestamp
     ctime_r(&ltime, szTime);                            // "threadsafe" ctime
@@ -91,8 +93,8 @@ int WriteLog(const char* pch, const char* LogFile)
 
     pthread_mutex_lock(pmtxLog);
 
-    char* pLogFile = new char[CONFPATH.length() + strlen(LogFile) +1];
-    strcpy(pLogFile,CONFPATH.c_str());
+    char* pLogFile = new char[LOGPATH.length() + strlen(LogFile) +1];
+    strcpy(pLogFile,LOGPATH.c_str());
     strcat(pLogFile, LogFile);
 
     f = fopen(pLogFile, "a");
