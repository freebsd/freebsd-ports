--- HTTPCache.cc.orig	2022-03-16 11:02:01 UTC
+++ HTTPCache.cc
@@ -1031,7 +1031,7 @@ HTTPCache::read_metadata(const string &cachename, vect
     const unsigned long line_buf_len = 1024;
     char line[line_buf_len];
     while (!feof(md) && fgets(line, line_buf_len, md)) {
-        line[min(line_buf_len, strnlen(line, line_buf_len))-1] = '\0'; // erase newline
+        line[min<size_t>(line_buf_len, strnlen(line, line_buf_len))-1] = '\0'; // erase newline
         headers.push_back(string(line));
     }
 
