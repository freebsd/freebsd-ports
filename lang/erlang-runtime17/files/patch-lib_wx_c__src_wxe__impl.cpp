--- lib/wx/c_src/wxe_impl.cpp.orig	2017-01-30 23:13:25 UTC
+++ lib/wx/c_src/wxe_impl.cpp
@@ -666,7 +666,7 @@ void * WxeApp::getPtr(char * bp, wxeMemE
     throw wxe_badarg(index);
   }
   void * temp = memenv->ref2ptr[index];
-  if((index < memenv->next) && ((index == 0) || (temp > NULL)))
+  if((index < memenv->next) && ((index == 0) || (temp != NULL)))
     return temp;
   else {
     throw wxe_badarg(index);
@@ -678,7 +678,7 @@ void WxeApp::registerPid(char * bp, ErlD
   if(!memenv)
     throw wxe_badarg(index);
   void * temp = memenv->ref2ptr[index];
-  if((index < memenv->next) && ((index == 0) || (temp > NULL))) {
+  if((index < memenv->next) && ((index == 0) || (temp != NULL))) {
     ptrMap::iterator it;
     it = ptr2ref.find(temp);
     if(it != ptr2ref.end()) {
