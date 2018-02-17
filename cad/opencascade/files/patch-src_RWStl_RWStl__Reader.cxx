--- src/RWStl/RWStl_Reader.cxx.orig	2017-08-30 13:28:29 UTC
+++ src/RWStl/RWStl_Reader.cxx
@@ -264,7 +264,7 @@ Standard_Boolean RWStl_Reader::ReadAscii
 
   // report progress every 1 MiB of read data
   const int aStepB = 1024 * 1024;
-  const Standard_Integer aNbSteps = 1 + Standard_Integer((theUntilPos - aStartPos) / aStepB);
+  const Standard_Integer aNbSteps = 1 + Standard_Integer(((int64_t)theUntilPos - aStartPos) / aStepB);
   Message_ProgressSentry aPSentry (theProgress, "Reading text STL file", 0, aNbSteps, 1);
 
   int64_t aProgressPos = aStartPos + aStepB;
