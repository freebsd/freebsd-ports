
$FreeBSD$

--- source/sg.cpp	2001/02/17 16:28:29	1.1
+++ source/sg.cpp	2001/02/17 16:28:40
@@ -1262,7 +1259,7 @@
                else {
                   delete actmap;
                   actmap = NULL;
-                  throw NoMapLoaded();
+                  goto except1;
                }
             }
          } else
@@ -1273,7 +1270,7 @@
          if (choice_dlg("Do you want to continue playing ?","~y~es","~n~o") == 2) {
             delete actmap;
             actmap = NULL;
-            throw NoMapLoaded();
+            goto except1;
          } else {
             actmap->continueplaying = 1;
             if ( actmap->replayinfo ) {
@@ -1283,6 +1280,10 @@
          }
       }
    }
+   return;
+
+except1:
+   throw NoMapLoaded();
 }
 
 
