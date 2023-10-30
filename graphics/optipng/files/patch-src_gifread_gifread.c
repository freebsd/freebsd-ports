--- src/gifread/gifread.c.orig	2017-12-10 23:49:00 UTC
+++ src/gifread/gifread.c
@@ -363,6 +363,11 @@ static int LZWGetCode(int code_size, int init_flag, FI
         lastbit = (2 + count) * 8;
     }
 
+    if (code_size && (size_t)(curbit + code_size - 1) / 8 >= sizeof(buffer)) {
+        GIFError("Malformed GIF (CVE-2023-43907)");
+        return -1;
+    }
+
     ret = 0;
     for (i = curbit, j = 0; j < code_size; ++i, ++j)
         ret |= ((buffer[i / 8] & (1 << (i % 8))) != 0) << j;
