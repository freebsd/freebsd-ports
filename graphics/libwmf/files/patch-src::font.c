--- src/font.c.orig	Wed May 15 18:34:08 2002
+++ src/font.c	Fri May 17 23:56:23 2002
@@ -833,8 +833,8 @@
 
 #ifdef HAVE_XML2
 
-#include <libxml/parser.h>
-#include <libxml/parserInternals.h>
+#include <libxml2/libxml/parser.h>
+#include <libxml2/libxml/parserInternals.h>
 
 static void xml2_start (void* user_data,const char* tag,const char** attributes)
 {	const char** attr;
