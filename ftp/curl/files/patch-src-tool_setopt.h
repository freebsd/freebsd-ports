Obtained from:	https://github.com/curl/curl/commit/f4f485c17b9a8b41c23ad1fa9fbcfc1973172ead

--- src/tool_setopt.h.orig	2019-04-15 07:05:14 UTC
+++ src/tool_setopt.h
@@ -29,11 +29,14 @@
  * Macros used in operate()
  */
 
-#define SETOPT_CHECK(v) do { \
-  result = (v); \
-  if(result) \
-    goto show_error; \
-} WHILE_FALSE
+#define SETOPT_CHECK(v,opt) do {                \
+    result = tool_real_error((v), opt);         \
+    if(result)                                  \
+      goto show_error;                          \
+  } WHILE_FALSE
+
+/* allow removed features to simulate success: */
+CURLcode tool_real_error(CURLcode result, CURLoption tag);
 
 #ifndef CURL_DISABLE_LIBCURL_OPTION
 
@@ -97,25 +100,25 @@ CURLcode tool_setopt(CURL *curl, bool st
                      const char *name, CURLoption tag, ...);
 
 #define my_setopt(x,y,z) \
-  SETOPT_CHECK(tool_setopt(x, FALSE, global, #y, y, z))
+  SETOPT_CHECK(tool_setopt(x, FALSE, global, #y, y, z), y)
 
 #define my_setopt_str(x,y,z) \
-  SETOPT_CHECK(tool_setopt(x, TRUE, global, #y, y, z))
+  SETOPT_CHECK(tool_setopt(x, TRUE, global, #y, y, z), y)
 
 #define my_setopt_enum(x,y,z) \
-  SETOPT_CHECK(tool_setopt_enum(x, global, #y, y, setopt_nv_ ## y, z))
+  SETOPT_CHECK(tool_setopt_enum(x, global, #y, y, setopt_nv_ ## y, z), y)
 
 #define my_setopt_flags(x,y,z) \
-  SETOPT_CHECK(tool_setopt_flags(x, global, #y, y, setopt_nv_ ## y, z))
+  SETOPT_CHECK(tool_setopt_flags(x, global, #y, y, setopt_nv_ ## y, z), y)
 
 #define my_setopt_bitmask(x,y,z) \
-  SETOPT_CHECK(tool_setopt_bitmask(x, global, #y, y, setopt_nv_ ## y, z))
+  SETOPT_CHECK(tool_setopt_bitmask(x, global, #y, y, setopt_nv_ ## y, z), y)
 
 #define my_setopt_mimepost(x,y,z) \
-  SETOPT_CHECK(tool_setopt_mimepost(x, global, #y, y, z))
+  SETOPT_CHECK(tool_setopt_mimepost(x, global, #y, y, z), y)
 
 #define my_setopt_slist(x,y,z) \
-  SETOPT_CHECK(tool_setopt_slist(x, global, #y, y, z))
+  SETOPT_CHECK(tool_setopt_slist(x, global, #y, y, z), y)
 
 #define res_setopt(x,y,z) tool_setopt(x, FALSE, global, #y, y, z)
 
@@ -126,25 +129,25 @@ CURLcode tool_setopt(CURL *curl, bool st
 /* No --libcurl, so pass options directly to library */
 
 #define my_setopt(x,y,z) \
-  SETOPT_CHECK(curl_easy_setopt(x, y, z))
+  SETOPT_CHECK(curl_easy_setopt(x, y, z), y)
 
 #define my_setopt_str(x,y,z) \
-  SETOPT_CHECK(curl_easy_setopt(x, y, z))
+  SETOPT_CHECK(curl_easy_setopt(x, y, z), y)
 
 #define my_setopt_enum(x,y,z) \
-  SETOPT_CHECK(curl_easy_setopt(x, y, z))
+  SETOPT_CHECK(curl_easy_setopt(x, y, z), y)
 
 #define my_setopt_flags(x,y,z) \
-  SETOPT_CHECK(curl_easy_setopt(x, y, z))
+  SETOPT_CHECK(curl_easy_setopt(x, y, z), y)
 
 #define my_setopt_bitmask(x,y,z) \
-  SETOPT_CHECK(curl_easy_setopt(x, y, z))
+  SETOPT_CHECK(curl_easy_setopt(x, y, z), y)
 
 #define my_setopt_mimepost(x,y,z) \
-  SETOPT_CHECK(curl_easy_setopt(x, y, z))
+  SETOPT_CHECK(curl_easy_setopt(x, y, z), y)
 
 #define my_setopt_slist(x,y,z) \
-  SETOPT_CHECK(curl_easy_setopt(x, y, z))
+  SETOPT_CHECK(curl_easy_setopt(x, y, z), y)
 
 #define res_setopt(x,y,z) curl_easy_setopt(x,y,z)
 
