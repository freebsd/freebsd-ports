$FreeBSD$

--- ../../j2se/src/share/native/sun/awt/font/fontmanager/fontobjects/fontObject.cpp.orig	Wed Jul  7 09:33:52 2004
+++ ../../j2se/src/share/native/sun/awt/font/fontmanager/fontobjects/fontObject.cpp	Wed Jul  7 13:26:03 2004
@@ -416,7 +416,11 @@
     fUseCount += 1;
 
     if (length > 0 && fFileSize > 0) {
-        assert(offset < fFileSize);
+        if (offset >= fFileSize) {
+            fUseCount--;
+            return NULL;
+        }
+
         if ((offset + length) > fFileSize)
             length = fFileSize - offset;
 
@@ -431,13 +435,14 @@
                   "fileFontObject::ReadChunk(UInt32,UInt32,void*)\n"
                   );
 #endif
+          fUseCount--;
           return NULL;
         }
 
         off_t err = lseek(fFile, offset, SEEK_SET);
 #ifdef DEBUG
         if (err == (off_t)-1) {
-            fprintf(stderr, "seek(%d) returned %d\n", offset, (int) err);
+            fprintf(stderr, "seek(%ld) returned %d\n", offset, (int) err);
         }
 #endif
 
@@ -448,7 +453,7 @@
             int tellvalue = lseek(fFile, 0, SEEK_END);
 #ifdef DEBUG
             fprintf(stderr,
-                    "<%s> of %d, ln %d, rd %d, sz %d, tell %d, err %d\n",
+                    "<%s> of %ld, ln %ld, rd %d, sz %ld, tell %d, err %d\n",
                     (char *)fFileName, offset, length, (int)bytesRead,
                     fFileSize, tellvalue, (int) err);
 #endif
@@ -1457,7 +1462,9 @@
               return false;
             }
 
-            this->ReadChunk(sizeof theHeader, fFontCount * sizeof *offsets, offsets);
+            if (this->ReadChunk(sizeof theHeader, fFontCount * sizeof *offsets, offsets) == NULL) {
+                return false;
+            }
             for (int i=0; i<fFontCount; i++) {
                 offsets[i] = GET32(offsets[i]);
             }
