--- src/scorelist.cpp.orig	2013-09-14 02:20:35.651231123 +0400
+++ src/scorelist.cpp	2013-09-14 02:22:39.837225946 +0400
@@ -98,7 +98,7 @@
 ostream & operator << (ostream & o,const ScoreList & s) {
     STDStreamPrinter sp(o);
     OStreamUTF8Encoder sc(&sp);
-    for (multimap<int,string>::const_iterator i=s.scores.begin();i!=s.scores.end();i++)
+    for (ScoreList::Map::const_iterator i=s.scores.begin();i!=s.scores.end();i++)
         sc<<'"'<<stows(i->second)<<"\" "<<i->first<<'\n';
     return o;
 };
