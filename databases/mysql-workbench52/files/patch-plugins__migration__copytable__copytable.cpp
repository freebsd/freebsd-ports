--- plugins/migration/copytable/copytable.cpp.orig
+++ plugins/migration/copytable/copytable.cpp
@@ -555,7 +555,7 @@
   //log_debug3("Convert string with %i chars to buffer size %i\n", inbuf_len, outbuf_len);
   
   // convert data from UCS-2 to utf-8
-#ifdef _WIN32
+#if defined(_WIN32) || defined(__FreeBSD__)
   converted = iconv(_iconv, 
                     (const char**)&inbuf, &inbuf_len,
                     (char**)&outbuf, &outbuf_len);
@@ -617,7 +617,7 @@
       //log_debug3("Convert string with %i chars to buffer size %i\n", inbuf_len, outbuf_len);
 
       // convert data from UCS-2 to utf-8
-#ifdef _WIN32
+#if defined(_WIN32) || defined(__FreeBSD__)
       converted = iconv(_iconv, 
                         (const char**)&inbuf, &inbuf_len,
                         (char**)&outbuf, &outbuf_len);      
