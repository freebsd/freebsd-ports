--- src/Machine.cpp.orig	Thu May  2 05:14:47 2002
+++ src/Machine.cpp	Sun Dec 22 03:23:36 2002
@@ -31,7 +31,7 @@
 
 
 /// Constructor.
-Machine::Machine(QObject* parent=NULL, const char* n=0)
+Machine::Machine(QObject* parent, const char* n)
 	: QObject(parent, n)
 {
   name = "";
