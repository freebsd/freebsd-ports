--- bardecode/code128.hh.orig	2010-01-16 23:58:07.000000000 -0500
+++ bardecode/code128.hh	2010-01-16 23:38:25.000000000 -0500
@@ -235,7 +235,7 @@
         switch (code_set) {
         case code_set_c:
             if (c < 100) {
-                char str[2];
+                char str[3];
                 sprintf(str,"%02d",c);
                 return std::string(str);
             } else {
