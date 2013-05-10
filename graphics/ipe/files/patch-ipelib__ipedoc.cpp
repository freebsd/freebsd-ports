--- ipelib/ipedoc.cpp.orig
+++ ipelib/ipedoc.cpp
@@ -850,7 +850,7 @@
     if (!file)
       return ErrWritingSource;
 
-    char *inbuf = (char *) utf8.data();
+    const char *inbuf = utf8.data();
     size_t inbytesleft = utf8.size();
 
     FileStream fstream(file);
