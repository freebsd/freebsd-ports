--- src/ConnectionSTREAM_UNITE/ConnectionSTREAM_UNITEEntry.cpp.orig	2020-10-29 09:52:56 UTC
+++ src/ConnectionSTREAM_UNITE/ConnectionSTREAM_UNITEEntry.cpp
@@ -16,7 +16,7 @@ static ConnectionSTREAM_UNITEEntry STREAM_UNITEEntry;
 }
 
 ConnectionSTREAM_UNITEEntry::ConnectionSTREAM_UNITEEntry(void):
-    ConnectionFX3Entry("STREAM+UNITE")
+    ConnectionFX3Entry()
 {
 
 }
