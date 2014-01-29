--- ./pgheader.c.orig	2012-09-20 13:50:00.000000000 +0200
+++ ./pgheader.c	2014-01-11 04:44:10.000000000 +0100
@@ -47,13 +47,13 @@
 #ifndef WIN32
 #define O_BINARY 0x0
 #endif
-
+/*
 #ifdef _MSC_VER
   typedef unsigned __int64 uint64_t;
 #else
   typedef unsigned long long int uint64_t;
 #endif
-
+*/
 static int int_from_file(FILE *f, int l, uint64_t *r){
     int i,c;
     for(i=0;i<l;i++){
