diff -u -r1.100 mod_tls.c
--- contrib/mod_tls.c	29 Nov 2006 03:47:56 -0000	1.100
+++ contrib/mod_tls.c	29 Nov 2006 04:09:06 -0000
@@ -3103,17 +3103,25 @@
   long datalen = 0;
   int ok;
    
-  if ((ok = X509_NAME_print_ex(mem, x509_name, 0, XN_FLAG_ONELINE)))
-     datalen = BIO_get_mem_data(mem, &data);
+  ok = X509_NAME_print_ex(mem, x509_name, 0, XN_FLAG_ONELINE);
+  if (ok) {
+    datalen = BIO_get_mem_data(mem, &data);
 
-  if (data) {
-    memset(&buf, '\0', sizeof(buf));
-    memcpy(buf, data, datalen);
-    buf[datalen] = '\0';
-    buf[sizeof(buf)-1] = '\0';
+    if (data) {
+      memset(&buf, '\0', sizeof(buf));
 
-    BIO_free(mem);
-    return buf;
+      if (datalen >= sizeof(buf)) {
+        datalen = sizeof(buf)-1;
+      }
+
+      memcpy(buf, data, datalen);
+
+      buf[datalen] = '\0';
+      buf[sizeof(buf)-1] = '\0';
+
+      BIO_free(mem);
+      return buf;
+    }
   }
 
   BIO_free(mem);
