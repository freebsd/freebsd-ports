--- src/score.h.orig	Sun Oct 30 00:53:49 2005
+++ src/score.h	Sun Oct 30 00:54:22 2005
@@ -20,34 +20,37 @@
 #define _SCORE_H
 
 #include <list>
+#include <iostream>
 #include <string>
 
+using namespace std;
+
 class Score {
-   std::string	_name;
+   string	_name;
    int		_seconds;
 protected:
 public:
    Score() {}
-   Score(const std::string& name, int seconds) : _name(name), 
+   Score(const string& name, int seconds) : _name(name), 
       _seconds(seconds) {}
    int operator<(Score& score);
-   friend std::ostream& operator<<(std::ostream& s, const Score& score);
-   friend std::istream& operator>>(std::istream& s, Score& score);
-   const std::string& GetName() const {return _name;}
+   friend ostream& operator<<(ostream& s, const Score& score);
+   friend istream& operator>>(istream& s, Score& score);
+   const string& GetName() const {return _name;}
    int GetSeconds() const {return _seconds;}
 };
 
 class ScoreList {
-   std::list<Score> _list;
+   list<Score> _list;
 protected:
 public:
    ScoreList() {}
    bool IsNewHighScore(int seconds);
    void AddHighScore(Score& score);
-   friend std::ostream& operator<<(std::ostream& s, const ScoreList& slist);
-   friend std::istream& operator>>(std::istream& s, ScoreList& slist);
-   std::list<Score>::const_iterator Begin() const {return _list.begin();}
-   std::list<Score>::const_iterator End() const {return _list.end();}
+   friend ostream& operator<<(ostream& s, const ScoreList& slist);
+   friend istream& operator>>(istream& s, ScoreList& slist);
+   list<Score>::const_iterator Begin() const {return _list.begin();}
+   list<Score>::const_iterator End() const {return _list.end();}
 };
 
 #endif // _SCORE_H
