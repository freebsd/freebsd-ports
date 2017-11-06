--- cmake/readline.cmake.orig	2016-09-30 11:41:40 UTC
+++ cmake/readline.cmake
@@ -173,11 +173,11 @@ MACRO (FIND_SYSTEM_EDITLINE)
     #include <readline.h>
     int main(int argc, char **argv)
     {
-      typedef int MYFunction(const char*, int);
+      typedef char *MYFunction(const char*, int);
       MYFunction* myf= rl_completion_entry_function;
-      int res= (myf)(NULL, 0);
+      char *res= (myf)(NULL, 0);
       completion_matches(0,0);
-      return res;
+      return (res != NULL);
     }"
     EDITLINE_HAVE_COMPLETION)
 
