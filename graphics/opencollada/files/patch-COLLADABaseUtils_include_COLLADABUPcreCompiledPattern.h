--- COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h.orig	2018-03-26 12:11:34 UTC
+++ COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h
@@ -13,8 +13,8 @@
 
 #include "COLLADABUPrerequisites.h"
 
-struct real_pcre;
-typedef struct real_pcre pcre;
+struct real_pcre8_or_16;
+typedef struct real_pcre8_or_16 pcre;
 
 
 namespace COLLADABU
