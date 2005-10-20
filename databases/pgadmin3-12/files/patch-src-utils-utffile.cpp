--- src/utils/utffile.cpp.orig	Thu May 26 19:54:45 2005
+++ src/utils/utffile.cpp	Sun Oct 16 23:42:59 2005
@@ -16,10 +16,6 @@
 extern wxMBConvUTF32BE wxConvUTF32BE;
 extern wxMBConvUTF32LE wxConvUTF32LE;
 
-#if !wxUSE_UNICODE
-#error utffile.cpp is implemented for unicode only.
-#endif
-
 
 // these are the magic characters identifying an Unicode file
 #define BOM_UTF8    "\357\273\277"
@@ -87,7 +83,12 @@
             if (decr)
                 Seek(-decr, wxFromCurrent);
 
-            m_conversion->MB2WC((wchar_t*)(wxChar*)wxStringBuffer(str, nLen+1), (const char*)buffer, (size_t)(nLen+1));
+#if wxUSE_UNICODE
+            size_t buf_len = nLen + 1;
+#else
+            size_t buf_len = (nLen + 1) * sizeof(wchar_t);
+#endif
+            m_conversion->MB2WC((wchar_t*)(wxChar*)wxStringBuffer(str, buf_len), (const char*)buffer, (size_t)(nLen+1));
         }
         else
             str = (wxChar*)buffer;
