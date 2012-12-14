--- cmn/xetp.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/xetp.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -29,9 +29,9 @@
 
 #include "stdafx.h"
 
-#include <iostream.h>
+#include <iostream>
 #if X11
-#include <strstream.h>
+#include <sstream>
 #endif
 #if WIN32
 #include <strstrea.h>
@@ -53,6 +53,8 @@
 #include "xetp.h"
 
 
+using namespace std;
+
 
 void XETP::check_sizes() {
   XETPBasic::check_sizes();
@@ -159,7 +161,7 @@
   for (n = 0; n < physicals.length(); n++) {
     PhysicalP p = (PhysicalP)physicals.get(n);
     // computing object_length twice, but who cares.
-    _send_object(out,p,turn,(TickType)tickTypes.get(n),
+    _send_object(out,p,turn,(long)tickTypes.get(n),
                  compute_object_length(p));
   }
   
@@ -274,7 +276,7 @@
 
 
 
-void XETP::send_message(OutStreamP out,char *msg) {
+void XETP::send_message(OutStreamP out,const char *msg) {
   assert(msg);
   u_int len = strlen(msg);
   
@@ -293,7 +295,7 @@
 
 
 
-void XETP::send_arena_message(OutStreamP out,int time,char *msg) {
+void XETP::send_arena_message(OutStreamP out,int time,const char *msg) {
   assert(msg);
   u_int len = sizeof(int) +  // time
     strlen(msg);             // string body
