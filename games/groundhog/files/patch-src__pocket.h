--- src/pocket.h.orig	Sun Oct 30 00:51:58 2005
+++ src/pocket.h	Sun Oct 30 00:52:09 2005
@@ -20,6 +20,7 @@
 #define _POCKET_H_
 
 #include <list>
+using namespace std;
 
 #include <gtk/gtk.h>
 
@@ -54,7 +55,7 @@
 };
 
 class SetOffPockets {
-   std::list<Pocket*> _set;
+   list<Pocket*> _set;
 public:
    SetOffPockets() {}
    void Add(Pocket* pocket) {_set.push_back(pocket);}
