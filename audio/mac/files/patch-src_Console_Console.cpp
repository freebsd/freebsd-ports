Console.cpp:36:3: error: cannot initialize a member subobject of type 'int' with an rvalue of type 'nullptr_t'
  NULL
  ^~~~
/usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
#define NULL    nullptr
                ^~~~~~~
Console.cpp:36:3: warning: suggest braces around initialization of subobject [-Wmissing-braces]
  NULL
  ^~~~
  {   }
/usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
#define NULL    nullptr
                ^~~~~~~
Console.cpp:36:3: warning: suggest braces around initialization of subobject [-Wmissing-braces]
  NULL
  ^~~~
  {   }
/usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
#define NULL    nullptr
                ^~~~~~~

--- src/Console/Console.cpp.orig	2010-02-28 19:42:04 UTC
+++ src/Console/Console.cpp
@@ -33,7 +33,6 @@ typedef struct
 
 _ErrorDesc ErrorList[][2] = {
   ERROR_EXPLANATION
-  NULL
 };
 #endif
 
@@ -91,7 +90,7 @@ char *ErrorToString(int nErrNo)
 {
     int i = 0;
 
-    while (ErrorList[i])
+    while (i < sizeof(ErrorList)/sizeof(ErrorList[0]))
     {
         if (ErrorList[i]->nErrorNum == nErrNo)
             return ErrorList[i]->sErrorString;
