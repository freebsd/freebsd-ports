--- Main.h.orig	2011-12-22 00:11:25.000000000 +0800
+++ Main.h	2011-12-22 00:11:41.000000000 +0800
@@ -45,6 +45,6 @@ void CloseTraceLog(void);
 void CloseLogs(void);
 void StartupMsgs(void);
 void Startup(void);
-void main(int, char **);
+int main(int, char **);
 void SaveHistory(void);
 void LoadHistory(void);
