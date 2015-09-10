--- options/setbasicstrings.cc.orig	2014-02-17 12:30:08 UTC
+++ options/setbasicstrings.cc
@@ -34,7 +34,7 @@ void Options::setBasicStrings()
 
     string nTokens;
     if (d_arg.option(&nTokens, "required-tokens"))
-        d_requiredTokens = stoul(nTokens);
+        d_requiredTokens = A2x(nTokens);
     
     d_arg.option(&d_genericFilename, 'f');
     if (d_genericFilename.empty())
