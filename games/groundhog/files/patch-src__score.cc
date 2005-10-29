--- src/score.cc.orig	Sun Oct 30 00:52:15 2005
+++ src/score.cc	Sun Oct 30 00:53:45 2005
@@ -17,20 +17,21 @@
  */
 
 #include <iostream>
+using namespace std;
 #include "score.h"
 
-std::ostream&
-operator<<(std::ostream& s, const Score& score)
+ostream&
+operator<<(ostream& s, const Score& score)
 {
    return s << "(\"" << score._name << "\" " << score._seconds << ')';
 }
 
-std::istream&
-operator>>(std::istream& s, Score& score)
+istream&
+operator>>(istream& s, Score& score)
 {
    char c;
-   std::ios::fmtflags flag = s.flags();
-   s.flags(flag & ~std::ios::skipws);
+   ios::fmtflags flag = s.flags();
+   s.flags(flag & ~ios::skipws);
 
    score._name = "";
    s >> c >> c;
@@ -54,14 +55,14 @@
 bool 
 ScoreList::IsNewHighScore(int seconds)
 {
-   std::list<Score>::iterator last = _list.end();
+   list<Score>::iterator last = _list.end();
    return _list.size() < 10 || seconds < (*--last).GetSeconds();
 }
 
 void 
 ScoreList::AddHighScore(Score& score)
 {
-   std::list<Score>::iterator i;
+   list<Score>::iterator i;
    for (i = _list.begin(); i != _list.end(); i++)
       if (score < *i)
 	 break;
@@ -74,18 +75,18 @@
    }
 }
 
-std::ostream&
-operator<<(std::ostream& s, const ScoreList& slist)
+ostream&
+operator<<(ostream& s, const ScoreList& slist)
 {
-   s << '(' << std::endl;
-   for (std::list<Score>::const_iterator i = slist._list.begin(); 
+   s << '(' << endl;
+   for (list<Score>::const_iterator i = slist._list.begin(); 
 	i != slist._list.end(); i++)
-      s << *i << std::endl;
-   return s << ')' << std::endl;
+      s << *i << endl;
+   return s << ')' << endl;
 }
 
-std::istream&
-operator>>(std::istream& s, ScoreList& slist)
+istream&
+operator>>(istream& s, ScoreList& slist)
 {
    char c;
    s >> c;
