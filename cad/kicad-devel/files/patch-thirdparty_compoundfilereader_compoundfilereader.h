--- thirdparty/compoundfilereader/compoundfilereader.h.orig	2024-10-11 09:03:05 UTC
+++ thirdparty/compoundfilereader/compoundfilereader.h
@@ -131,7 +131,7 @@ struct helper
     }
 };
 
-typedef std::basic_string<uint16_t> utf16string;
+typedef std::basic_string<char16_t> utf16string;
 typedef std::function<int(const COMPOUND_FILE_ENTRY*, const utf16string& dir, int level)>
     EnumFilesCallback;
 
@@ -249,7 +249,7 @@ class CompoundFileReader (private)
             utf16string newDir = dir;
             if (dir.length() != 0)
                 newDir.append(1, '\n');
-            newDir.append(entry->name, entry->nameLen / 2);
+            newDir.append(reinterpret_cast<const char16_t*>(entry->name), entry->nameLen / 2);
             EnumNodes(GetEntry(entry->childID), currentLevel + 1, maxLevel, newDir, callback);
         }
 
