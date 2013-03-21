--- src/font.c.orig	2005-07-27 22:35:06.000000000 +0200
+++ src/font.c	2013-03-21 03:00:23.000000000 +0100
@@ -881,8 +881,8 @@
 
 #ifdef HAVE_LIBXML2
 
-#include <libxml/parser.h>
-#include <libxml/parserInternals.h>
+#include <libxml2/libxml/parser.h>
+#include <libxml2/libxml/parserInternals.h>
 
 static void xml2_start (void* user_data,const char* tag,const char** attributes)
 {	const char** attr;
