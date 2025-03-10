commit da74335d50a951b916c2f3e65d17b6c9e6dcd318
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    fix build with libc++ 19
    
    As noted in the libc++ 19 release notes [1], std::char_traits<> is now
    only provided for char, char8_t, char16_t, char32_t and wchar_t, and any
    instantiation for other types will fail.
    
    Original Patch by Dimitry Andric <dim@FreeBSD.org>

diff --git thirdparty/compoundfilereader/compoundfilereader.h thirdparty/compoundfilereader/compoundfilereader.h
index 5ca6657529..929aa41e19 100644
--- thirdparty/compoundfilereader/compoundfilereader.h
+++ thirdparty/compoundfilereader/compoundfilereader.h
@@ -131,7 +131,7 @@ struct helper
     }
 };
 
-typedef std::basic_string<uint16_t> utf16string;
+typedef std::basic_string<char16_t> utf16string;
 typedef std::function<int(const COMPOUND_FILE_ENTRY*, const utf16string& dir, int level)>
     EnumFilesCallback;
 
@@ -249,7 +249,7 @@ private:
             utf16string newDir = dir;
             if (dir.length() != 0)
                 newDir.append(1, '\n');
-            newDir.append(entry->name, entry->nameLen / 2);
+            newDir.append(reinterpret_cast<const char16_t*>(entry->name), entry->nameLen / 2);
             EnumNodes(GetEntry(entry->childID), currentLevel + 1, maxLevel, newDir, callback);
         }
 
@@ -480,4 +480,4 @@ private:
     const PROPERTY_SET_STREAM_HDR* m_hdr;
 };
 
-}
\ No newline at end of file
+}
