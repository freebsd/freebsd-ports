--- src/ipa/ipa/font.h.orig	Sat Mar 30 21:02:34 2002
+++ src/ipa/ipa/font.h	Sat Mar 30 21:02:47 2002
@@ -851,8 +851,8 @@
 
 #ifdef HAVE_XML2
 
-#include <parser.h>
-#include <parserInternals.h>
+#include <libxml2/libxml/parser.h>
+#include <libxml2/libxml/parserInternals.h>
 
 static void xml2_start (void* user_data,const char* tag,const char** attributes)
 {	const char** attr;
