--- picker.cc.orig	Sun Jan 25 16:55:21 2004
+++ picker.cc	Wed Feb 11 18:47:20 2004
@@ -1,4 +1,5 @@
 #include <iostream>
+#include <math.h>
 
 #include "picker.h"
 #include "strmanip.h"
@@ -31,9 +32,12 @@
 
     SongData data(position, path);
 
-    if (find(candidates.begin(), candidates.end(), data)
-            != candidates.end())
-        return true;
+    Candidates::iterator i = candidates.begin();
+    while (i != candidates.end()) {
+	if (*i == data)
+	    return true;
+	i++;
+    }
 
     int cost = fetch_song_info(data);
 
