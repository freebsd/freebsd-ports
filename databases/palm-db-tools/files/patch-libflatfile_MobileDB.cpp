--- libflatfile/MobileDB.cpp.orig	2003-06-19 23:37:46 UTC
+++ libflatfile/MobileDB.cpp
@@ -221,7 +221,7 @@ PalmLib::FlatFile::MobileDB::parse_recor
         if (field + 1 > fields.size()) fields.resize(field + 1);
 
         // Now search for the end of the current field.
-        pi_char_t* q = reinterpret_cast<pi_char_t*>
+        const pi_char_t* q = reinterpret_cast<const pi_char_t*>
             (memchr(p, 0, rec.end() - p));
         if (!q)
             throw PalmLib::error("field terminiator is missing");
