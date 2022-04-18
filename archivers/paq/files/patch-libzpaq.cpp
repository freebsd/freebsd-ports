--- libzpaq.cpp.orig	2022-04-18 09:32:11 UTC
+++ libzpaq.cpp
@@ -2745,7 +2745,7 @@ void Compressor::writeTag() {
 void Compressor::startBlock(int level) {
 
   // Model 1 - min.cfg
-  static const char models[]={
+  static const signed char models[]={
   26,0,1,2,0,0,2,3,16,8,19,0,0,96,4,28,
   59,10,59,112,25,10,59,10,59,112,56,0,
 
@@ -2774,7 +2774,7 @@ void Compressor::startBlock(int level) {
   0,0}; // 0,0 = end of list
 
   if (level<1) error("compression level must be at least 1");
-  const char* p=models;
+  const char* p=(const char*)models;
   int i;
   for (i=1; i<level && toU16(p); ++i)
     p+=toU16(p)+2;
