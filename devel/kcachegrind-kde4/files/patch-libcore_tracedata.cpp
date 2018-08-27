--- libcore/tracedata.cpp.orig	2018-08-27 21:22:51 UTC
+++ libcore/tracedata.cpp
@@ -3259,7 +3259,7 @@ bool TraceData::activateAll(bool active)
 
 void TraceData::addPart(TracePart* part)
 {
-    if (_parts.contains(part)>0) return;
+    if (bool(_parts.contains(part))) return;
 
     if ((part->partNumber()==0) &&
         (part->processID()==0)) {
