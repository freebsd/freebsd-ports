--- kenwood/ts2000.c.orig	Mon Apr 10 01:08:30 2006
+++ kenwood/ts2000.c	Mon Apr 10 01:09:48 2006
@@ -259,7 +259,8 @@
 int ts2000_get_level(RIG *rig, vfo_t vfo, setting_t level, value_t *val)
 {
 		unsigned char lvlbuf[50];
-		int lvl_len, retval;
+		int retval;
+		size_t lvl_len;
 		int lvl;
 		int i, ret, agclevel;
 
