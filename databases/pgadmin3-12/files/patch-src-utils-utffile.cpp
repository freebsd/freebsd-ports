--- src/utils/utffile.cpp.orig	Thu Feb 24 00:41:36 2005
+++ src/utils/utffile.cpp	Thu Feb 24 00:41:18 2005
@@ -83,7 +83,12 @@
             if (decr)
                 Seek(-decr, wxFromCurrent);
 
-            m_conversion->MB2WC((wchar_t*)(wxChar*)wxStringBuffer(str, nLen), (const char*)buffer, (size_t)(nLen+1));
+#if wxUSE_UNICODE
+            size_t buf_len = nLen;
+#else
+            size_t buf_len = nLen * sizeof(wchar_t);
+#endif
+            m_conversion->MB2WC((wchar_t*)(wxChar*)wxStringBuffer(str, buf_len), (const char*)buffer, (size_t)(nLen+1));
         }
         else
             str = (wxChar*)buffer;
