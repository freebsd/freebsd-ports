--- src/squirrel/squirrel.h.orig	2007-08-12 19:46:49.000000000 +0200
+++ src/squirrel/squirrel.h	2007-08-12 19:47:31.000000000 +0200
@@ -44,7 +44,7 @@
 typedef int SQInt32; //must be 32 bits(also on 64bits processors)
 typedef void* SQUserPointer;
 typedef unsigned int SQUnsignedInteger;
-typedef unsigned int SQHash; //should be the same size of a pointer
+typedef unsigned long SQHash; //should be the same size of a pointer
 typedef SQUnsignedInteger SQBool;
 typedef SQInteger SQRESULT;
 
