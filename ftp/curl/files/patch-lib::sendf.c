--- lib/sendf.c.orig	Tue Dec 21 10:13:04 2004
+++ lib/sendf.c	Tue Dec 21 10:16:45 2004
@@ -155,10 +155,6 @@
 {
   va_list ap;
   va_start(ap, fmt);
-  if(data->set.errorbuffer && !data->state.errorbuf) {
-    vsnprintf(data->set.errorbuffer, CURL_ERROR_SIZE, fmt, ap);
-    data->state.errorbuf = TRUE; /* wrote error string */
-  }
   if(data->set.verbose) {
       size_t len;
 
@@ -170,6 +166,15 @@
         data->state.buffer[++len] = '\0';
       }
       Curl_debug(data, CURLINFO_TEXT, data->state.buffer, len, NULL);
+      data->state.buffer[len] = '\0';
+  }
+  if(data->set.errorbuffer && !data->state.errorbuf) {
+    if (data->set.verbose)
+      snprintf(data->set.errorbuffer, CURL_ERROR_SIZE, "%s",
+	  data->state.buffer);
+    else
+      vsnprintf(data->set.errorbuffer, CURL_ERROR_SIZE, fmt, ap);
+    data->state.errorbuf = TRUE; /* wrote error string */
   }
 
   va_end(ap);
