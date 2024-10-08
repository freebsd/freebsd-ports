--- thirdparty/compoundfilereader/compoundfilereader.h.orig	2023-04-13 20:27:39 UTC
+++ thirdparty/compoundfilereader/compoundfilereader.h
@@ -129,7 +129,7 @@ struct helper
     }
 };
 
-typedef std::basic_string<uint16_t> utf16string;
+typedef std::basic_string<char16_t> utf16string;
 typedef std::function<void(const COMPOUND_FILE_ENTRY*, const utf16string& dir, int level)> 
     EnumFilesCallback;
 
@@ -246,7 +246,7 @@ class CompoundFileReader (private)
             utf16string newDir = dir;
             if (dir.length() != 0)
                 newDir.append(1, '\n');
-            newDir.append(entry->name, entry->nameLen / 2);
+            newDir.append(reinterpret_cast<const char16_t*>(entry->name), entry->nameLen / 2);
             EnumNodes(GetEntry(entry->childID), currentLevel + 1, maxLevel, newDir, callback);
         }
 
