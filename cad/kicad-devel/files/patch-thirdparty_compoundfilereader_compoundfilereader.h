--- thirdparty/compoundfilereader/compoundfilereader.h.orig	2026-03-05 18:35:46 UTC
+++ thirdparty/compoundfilereader/compoundfilereader.h
@@ -261,7 +261,7 @@ struct helper
     }
 };
 
-typedef std::basic_string<uint16_t> utf16string;
+typedef std::basic_string<char16_t> utf16string;
 typedef std::function<int(const COMPOUND_FILE_ENTRY*, const utf16string& dir, int level)>
     EnumFilesCallback;
 
@@ -379,7 +379,7 @@ class CompoundFileReader (private)
             utf16string newDir = dir;
             if (dir.length() != 0)
                 newDir.append(1, '\n');
-            newDir.append(entry->name, entry->nameLen / 2);
+            newDir.append(reinterpret_cast<const char16_t*>(entry->name), entry->nameLen / 2);
             EnumNodes(GetEntry(entry->childID), currentLevel + 1, maxLevel, newDir, callback);
         }
 
@@ -610,4 +610,4 @@ class PropertySetStream (private)
     const PROPERTY_SET_STREAM_HDR* m_hdr;
 };
 
-}
\ No newline at end of file
+}
