--- stafproc/STAFFSService.cpp.orig	2016-12-31 04:11:18 UTC
+++ stafproc/STAFFSService.cpp
@@ -4451,12 +4451,11 @@ STAFServiceResult STAFFSService::handleG
 
             unsigned int fileLength = lowerSize;
 
-            EVP_MD_CTX mdctx;
+            EVP_MD_CTX* mdctx = EVP_MD_CTX_create();
             unsigned char md_value[EVP_MAX_MD_SIZE];
             unsigned int md_len;
 
-            EVP_MD_CTX_init(&mdctx);
-            EVP_DigestInit_ex(&mdctx, md, NULL);
+            EVP_DigestInit_ex(mdctx, md, NULL);
 
             // Read the entire file using a buffer size of 4096 bytes and
             // update the digest with the buffer
@@ -4475,7 +4474,7 @@ STAFServiceResult STAFFSService::handleG
 
                 if (rc != kSTAFOk) break;
 
-                EVP_DigestUpdate(&mdctx, fileBuffer, writeLength);
+                EVP_DigestUpdate(mdctx, fileBuffer, writeLength);
                 fileLength -= writeLength;
                 bytesCopied += writeLength;
             }
@@ -4485,10 +4484,10 @@ STAFServiceResult STAFFSService::handleG
             if (rc == kSTAFOk)
             {
                 // Get the checksum value
-                EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
+                EVP_DigestFinal_ex(mdctx, md_value, &md_len);
             }
 
-            EVP_MD_CTX_cleanup(&mdctx);
+            EVP_MD_CTX_destroy(mdctx);
 
             if (rc == kSTAFOk)
             {
