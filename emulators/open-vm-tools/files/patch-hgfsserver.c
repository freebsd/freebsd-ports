--- lib/hgfsServer/hgfsServer.c.orig
+++ lib/hgfsServer/hgfsServer.c
@@ -3557,7 +3557,7 @@
     * delimiter on copy. Allow 0 length drives so that hidden feature "" can
     * work.
     */
-   if (pathLength < 0 || pathLength >= sizeof p.mountPoint) {
+   if (pathLength >= sizeof p.mountPoint) {
       LOG(4, ("%s: could not get the volume name\n", __FUNCTION__));
 
       return FALSE;
