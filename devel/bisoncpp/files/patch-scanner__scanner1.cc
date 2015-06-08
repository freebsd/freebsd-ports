--- scanner/scanner1.cc.orig	2013-06-23 18:13:49 UTC
+++ scanner/scanner1.cc
@@ -15,7 +15,7 @@ Scanner::Scanner(std::string const &infi
 
     string value;
     if (arg.option(&value, "max-inclusion-depth"))
-        d_maxDepth = stoul(value);
+        d_maxDepth = A2x(value);
     else
         d_maxDepth = 10;
 }
