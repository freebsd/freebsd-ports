--- kaptain/process.h.orig	Wed Aug 14 12:17:20 2002
+++ kaptain/process.h	Fri Dec 20 16:14:31 2002
@@ -3,13 +3,13 @@
 
 #include <list>
 #include <string>
+#include <iostream>
 
-using namespace std;
 
 void clean_up_child_process(int);
 void POSIX_init();
-int exec_async(list<string> &);
-string exec_sync_stdout(string &);
-string exec_sync_stdout(list<string> &);
+int exec_async(std::list<std::string> &);
+std::string exec_sync_stdout(std::string &);
+std::string exec_sync_stdout(std::list<std::string> &);
 
 #endif // PROCESS_HH
