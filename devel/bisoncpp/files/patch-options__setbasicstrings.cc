--- ./options/setbasicstrings.cc.orig	2013-06-24 15:10:12.000000000 +0200
+++ ./options/setbasicstrings.cc	2013-11-27 18:56:48.000000000 +0100
@@ -35,7 +35,7 @@
 
     string nTokens;
     if (d_arg.option(&nTokens, "required-tokens"))
-        d_requiredTokens = stoul(nTokens);
+        d_requiredTokens = A2x(nTokens);
     
     d_arg.option(&d_genericFilename, 'f');
     if (d_genericFilename.empty())
