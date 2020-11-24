--- src/io_helpers.cpp.orig	2003-03-02 00:23:00 UTC
+++ src/io_helpers.cpp
@@ -363,9 +363,10 @@ size_t io::writeUnicodeText(ID3_Writer& writer, String
     // Write the BOM: 0xFEFF
     unicode_t BOM = 0xFEFF;
     writer.writeChars((const unsigned char*) &BOM, 2);
+    const unsigned char* pdata = (const unsigned char*)data.c_str();
     for (size_t i = 0; i < size; i += 2)
     {
-      unicode_t ch = (data[i] << 8) | data[i+1];
+      unicode_t ch = (pdata[i] << 8) | pdata[i+1];
       writer.writeChars((const unsigned char*) &ch, 2);
     }
   }
