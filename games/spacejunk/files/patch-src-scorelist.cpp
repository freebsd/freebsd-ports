--- src/scorelist.cpp.orig	2010-05-07 18:21:19 UTC
+++ src/scorelist.cpp
@@ -98,7 +98,7 @@ string ScoreList::getPoints() const {
 ostream & operator << (ostream & o,const ScoreList & s) {
     STDStreamPrinter sp(o);
     OStreamUTF8Encoder sc(&sp);
-    for (multimap<int,string>::const_iterator i=s.scores.begin();i!=s.scores.end();i++)
+    for (ScoreList::Map::const_iterator i=s.scores.begin();i!=s.scores.end();i++)
         sc<<'"'<<stows(i->second)<<"\" "<<i->first<<'\n';
     return o;
 };
