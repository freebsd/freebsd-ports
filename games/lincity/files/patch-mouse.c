--- mouse.c.orig	2004-07-03 08:03:17 UTC
+++ mouse.c
@@ -1057,7 +1057,7 @@ choose_residence (void)
    and set to 1 if the existing transport if the more expensive sort
    (e.g. GROUP_RAIL when overwriting GROUP_ROAD).
 */
-inline int
+int
 mt_erase(int x, int y)
 {
     if (x < 0 || y < 0 || x >= WORLD_SIDE_LEN || y >= WORLD_SIDE_LEN)
@@ -1094,7 +1094,7 @@ mt_erase(int x, int y)
     return 0;
 }
 
-inline int
+int
 mt_temp(int x, int y)
 {
     if (x < 0 || y < 0 || x >= WORLD_SIDE_LEN || y >= WORLD_SIDE_LEN)
@@ -1128,7 +1128,7 @@ mt_temp(int x, int y)
     return 0;
 }
 
-inline int
+int
 mt_perm(int x, int y)
 {
     /* By now, it has already been mt_erase()'d */
