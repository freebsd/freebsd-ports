--- krss/rssparser.cpp.orig	Wed Feb 20 14:39:36 2002
+++ krss/rssparser.cpp	Wed May 21 10:35:29 2003
@@ -35,6 +35,8 @@
 #include "mychannelbaritem.h"
 #include "filterhandler.h"
 
+using namespace std;
+
 RSSParser::RSSParser()
 : QXmlDefaultHandler()
 {
