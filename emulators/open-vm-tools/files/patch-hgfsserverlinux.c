--- lib/hgfsServer/hgfsServerLinux.c.orig
+++ lib/hgfsServer/hgfsServerLinux.c
@@ -551,7 +551,7 @@
 
    arraySize = ARRAYSIZE(HgfsServerOpenFlags);
 
-   if (flagsIn < 0 || flagsIn >= arraySize) {
+   if (flagsIn >= arraySize) {
       Log("%s: Invalid HgfsOpenFlags %d\n", __FUNCTION__, flagsIn);
 
       return FALSE;
