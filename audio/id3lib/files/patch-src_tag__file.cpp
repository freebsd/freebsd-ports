
$FreeBSD$

--- src/tag_file.cpp.orig	Mon Sep 11 09:46:32 2000
+++ src/tag_file.cpp	Sun Jul 21 15:13:19 2002
@@ -184,7 +184,7 @@
     }
   }
   
-  file.write(sTag, tag_size);
+  file.write((const char*) sTag, tag_size);
 
   return tag_size;
 }
@@ -221,7 +221,7 @@
     file.seekp(0, ios::beg);
     if (buffer)
     {
-      file.write(buffer, tag_size);
+      file.write((const char*) buffer, tag_size);
     }
   }
   else
@@ -282,8 +282,9 @@
       remove(sTempFile);
       ID3_THROW_DESC(ID3E_NoFile, "couldn't open temp file");
     }
-
-    ofstream tmpOut(fd);
+    
+    close(fd);
+    ofstream tmpOut(sTempFile);
     if (!tmpOut)
     {
       tmpOut.close();
@@ -292,15 +293,15 @@
     }
     if (buffer)
     {
-      tmpOut.write(buffer, tag_size);
+      tmpOut.write((const char*) buffer, tag_size);
     }
     file.seekg(tag.GetPrependedBytes(), ios::beg);
     uchar buffer2[BUFSIZ];
     while (file)
     {
-      file.read(buffer2, BUFSIZ);
+      file.read((char*) buffer2, BUFSIZ);
       size_t nBytes = file.gcount();
-      tmpOut.write(buffer2, nBytes);
+      tmpOut.write((const char*) buffer2, nBytes);
     }
       
     tmpOut.close();
@@ -431,7 +432,7 @@
     while (!file.eof())
     {
       size_t nBytesToRead = MIN(nBytesRemaining - nBytesCopied, BUFSIZ);
-      file.read(aucBuffer, nBytesToRead);
+      file.read((char*) aucBuffer, nBytesToRead);
       size_t nBytesRead = file.gcount();
 
       if (nBytesRead != nBytesToRead)
@@ -444,7 +445,7 @@
       {
         long offset = nBytesRead + this->GetPrependedBytes();
         file.seekp(-offset, ios::cur);
-        file.write(aucBuffer, nBytesRead);
+        file.write((const char*) aucBuffer, nBytesRead);
         file.seekg(this->GetPrependedBytes(), ios::cur);
         nBytesCopied += nBytesRead;
       }
