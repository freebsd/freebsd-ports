--- playlist.h.orig	Wed Aug 18 01:56:28 2004
+++ playlist.h	Tue Aug 31 16:03:12 2004
@@ -3,10 +3,11 @@
 
 #include "immsconf.h"
 #include "basicdb.h"
+#include "utils.h"
 
 #include <vector>
 
-class PlaylistDb : virtual public BasicDb
+class PlaylistDb : protected ImmsRandom, virtual public BasicDb
 {
 public:
     void playlist_insert_item(int pos, const string &path);
