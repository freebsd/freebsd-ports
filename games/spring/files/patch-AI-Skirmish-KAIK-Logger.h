--- AI/Skirmish/KAIK/Logger.h.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/Logger.h	2013-11-11 04:04:46.414772522 +0400
@@ -2,10 +2,8 @@
 #define KAIK_LOGGER_HDR
 
 #include <string>
-//FIXME:compile hack for macosx
-#undef tm
 #include <fstream>
-#define tm GetThreatMap()
+#define thm GetThreatMap()
 
 namespace springLegacyAI {
 	class IAICallback;
