--- kfile-plugins/vcf/kfile_vcf.cpp     2003-07-16 21:12:41.000000000 +0200
+++ kfile-plugins/vcf/kfile_vcf.cpp     2003-12-16 15:38:20.000000000 +0100
@@ -90,17 +90,17 @@
     while (!done) {
     
         // read a line
-        file.readLine(linebuf, 4096);
+        file.readLine(linebuf, sizeof(linebuf));
         
         // have we got something useful?
         if (memcmp(linebuf, id_name, 3) == 0) {
             // we have a name
             myptr = linebuf + 3;
-            strncpy(buf_name, myptr, 999);
+            strlcpy(buf_name, myptr, sizeof( buf_name ));
         } else if (memcmp(linebuf, id_email, 15) == 0) {
             // we have a name
             myptr = linebuf + 15;
-            strncpy(buf_email, myptr, 999);
+            strlcpy(buf_email, myptr, sizeof( buf_email ));
         }
         
         // are we done yet?

