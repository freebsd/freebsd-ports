--- libflatfile/Database.cpp.orig	2012-11-30 14:43:18.000000000 +0100
+++ libflatfile/Database.cpp	2012-11-30 14:48:11.000000000 +0100
@@ -208,7 +208,7 @@
     // Ensure that the field numbers are within range.
     for (PalmLib::FlatFile::ListView::const_iterator i = lv.begin();
          i != lv.end(); ++i) {
-        if ((*i).field < 0 || (*i).field >= getNumOfFields())
+        if ((*i).field >= getNumOfFields())
             return;
     }
     m_listviews.push_back(lv);
