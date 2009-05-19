Fix two minor grammatical errors in comments.

--- a/include/curl/curl.h
+++ b/include/curl/curl.h
@@ -186,7 +186,7 @@
                                       size_t nitems,
                                       void *outstream);
 
-/* this is the return codes for the seek callbacks */
+/* those are the return codes for the seek callbacks */
 #define CURL_SEEKFUNC_OK       0
 #define CURL_SEEKFUNC_FAIL     1 /* fail the entire transfer */
 #define CURL_SEEKFUNC_CANTSEEK 2 /* tell libcurl seeking can't be done, so
@@ -1516,7 +1516,7 @@
  * DESCRIPTION
  *
  * curl_global_init() should be invoked exactly once for each application that
- * uses libcurl and before any call of other libcurl function.
+ * uses libcurl and before any call of other libcurl functions.
  *
  * This function is not thread-safe!
  */
