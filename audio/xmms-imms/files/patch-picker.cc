--- picker.cc.orig	Thu Apr 15 16:15:24 2004
+++ picker.cc	Sat Aug 14 11:19:33 2004
@@ -2,6 +2,7 @@
 #include <algorithm>
 
 #include <math.h>
+#include <math.h>
 
 #include "picker.h"
 #include "strmanip.h"
@@ -53,9 +54,12 @@
 
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
 
     if (fetch_song_info(data))
     {
@@ -83,8 +87,9 @@
 
 void SongPicker::do_events()
 {
-    bool more;
-    for (int i = 0; i < 4 && (more = add_candidate()); ++i);
+    bool more = true;
+    for (int i = 0; i < 4 && more; ++i)
+	more = add_candidate();
     if (!more)
         identify_more();
 }
