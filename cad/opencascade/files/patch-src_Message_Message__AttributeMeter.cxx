--- src/Message/Message_AttributeMeter.cxx.orig	2023-12-04 15:53:08 UTC
+++ src/Message/Message_AttributeMeter.cxx
@@ -253,6 +253,6 @@ void Message_AttributeMeter::DumpJson (Standard_OStrea
        anIterator.More(); anIterator.Next())
   {
     OCCT_DUMP_VECTOR_CLASS (theOStream, Message::MetricToString (anIterator.Key()),
-                            2, anIterator.Value(), anIterator.Value())
+                            2, anIterator.Value().first, anIterator.Value().second)
   }
 }
