--- src/aprsd.cpp.orig	2003-05-29 03:09:39 UTC
+++ src/aprsd.cpp
@@ -98,7 +98,8 @@ string szAprsPath;
 int msgsn;
 
 const string HOMEDIR("/home/aprsd2");
-const string CONFPATH("");
+const string LOGPATH("/var/log/aprsd/");
+const string CONFPATH("/usr/local/etc/aprsd/");
 const string CONFFILE("aprsd.conf");
 const string MAINLOG("aprsd.log");
 const string STSMLOG("thirdparty.log");
@@ -126,7 +127,7 @@ void serverQuit(void)      /* Invoked by console 'q' q
     WriteLog(string("Server Shutdown"), MAINLOG);
     tcsetattr(fileno(stdin),TCSANOW,&initial_settings); //restore terminal mode
 
-    string outFile = CONFPATH;
+    string outFile = LOGPATH;
     outFile += SAVE_HISTORY;
     int n = SaveHistory(outFile);
 
@@ -872,8 +873,8 @@ int daemonInit(void)
     if (f.is_open()) {
         f.read(s, 10);
         xx = atoi(s);
-        kill(xx, SIGCHLD);      // Meaningless kill to determine if pid is used
-        if (errno != ESRCH) {
+        kill(xx, 0);      // Meaningless kill to determine if pid is used
+        if (errno == 0) {
             cout << "aprsd already running" << endl;
             cout << "PID: " << pid_file << endl;
             exit(1);
@@ -977,7 +978,7 @@ int main(int argc, char *argv[])
 
     //fdump = fopen("dump.txt","w+");  //debug
 
-        string histFile = CONFPATH;
+        string histFile = LOGPATH;
         histFile += SAVE_HISTORY;
         ReadHistory(histFile);
         
