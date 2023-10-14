--- src/main.cpp.orig	2023-10-13 13:46:01 UTC
+++ src/main.cpp
@@ -226,7 +226,7 @@ int main(int argc, char *argv[]){
 
     #ifdef _WIN32
        _putenv_s("OMP_NUM_THREADS", to_string(thread_num).c_str());
-    #elif defined __linux__ || defined __APPLE__
+    #elif defined __FreeBSD__ || defined __linux__ || defined __APPLE__
         setenv("OMP_NUM_THREADS", to_string(thread_num).c_str(), 1);
     #else
         #error Only Windows, Mac and Linux are supported.
