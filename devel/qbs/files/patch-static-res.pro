The freshly built qbs binary requires the library that also freshly created library. Make it find it. 

--- static-res.pro.orig	2018-03-29 21:04:38 UTC
+++ static-res.pro
@@ -15,6 +15,7 @@ else: \
 
 qbsres.target = $$builddirname/default/default.bg
 qbsres.commands = \
+    env LD_LIBRARY_PATH=$$shell_path($$qbsbindir/../lib) \
     $$shell_quote($$shell_path($$qbsbindir/qbs)) \
     build \
     --settings-dir $$shell_quote($$builddirname/settings) \
