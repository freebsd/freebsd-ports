--- ./Global/SSAHAMain.h.orig	2004-03-01 13:51:28.000000000 -0300
+++ ./Global/SSAHAMain.h	2008-06-12 15:39:31.000000000 -0300
@@ -131,7 +131,7 @@
   -1,        // int    queryEnd; 
   -1,        // int    wordLength;
   -1,        // int    stepLength;
-  100000,    // int    maxToStore; 
+  10000,     // int    maxToStore; 
   1,         // int    minToPrint;
   -1,        // int    maxGap;
   0,         // int    maxInsert;
@@ -174,6 +174,7 @@
 
   CommandLineArg( const string& nameLong, const string& nameShort ) :
     nameLong_( nameLong ), nameShort_( nameShort ) {}
+  virtual ~CommandLineArg() {};  // base class with virtual functions requires virtual constructor
   // Is the current argument equal to 'my' argument name?
   virtual bool isThisMe( const string& argName )
   { 
