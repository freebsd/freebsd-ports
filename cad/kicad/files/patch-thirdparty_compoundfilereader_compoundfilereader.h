commit daf1a8f45de54265106ed1337048503cadd0b713
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    fix build with libc++ 19
    
    As noted in the libc++ 19 release notes [1], std::char_traits<> is now
    only provided for char, char8_t, char16_t, char32_t and wchar_t, and any
    instantiation for other types will fail.
    
    Original Patch by Dimitry Andric <dim@FreeBSD.org>

diff --git thirdparty/compoundfilereader/compoundfilereader.h thirdparty/compoundfilereader/compoundfilereader.h
index 8c840d24e5..119b2b48e8 100644
--- thirdparty/compoundfilereader/compoundfilereader.h
+++ thirdparty/compoundfilereader/compoundfilereader.h
@@ -262,7 +262,7 @@ struct helper
     }
 };
 
-typedef std::basic_string<uint16_t> utf16string;
+typedef std::basic_string<char16_t> utf16string;
 typedef std::function<int(const COMPOUND_FILE_ENTRY*, const utf16string& dir, int level)>
     EnumFilesCallback;
 
@@ -402,7 +402,7 @@ private:
             utf16string newDir = dir;
             if (dir.length() != 0)
                 newDir.append(1, '\n');
-            newDir.append(entry->name, entry->nameLen / 2 - 1);
+            newDir.append(reinterpret_cast<const char16_t*>(entry->name), entry->nameLen / 2 - 1);
             EnumNodes(child, currentLevel + 1, maxLevel, newDir, callback, visited);
         }
 
@@ -636,4 +636,4 @@ private:
     const PROPERTY_SET_STREAM_HDR* m_hdr;
 };
 
-}
\ No newline at end of file
+}
