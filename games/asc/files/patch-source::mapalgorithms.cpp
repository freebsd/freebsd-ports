
$FreeBSD$

--- source/mapalgorithms.cpp	2002/10/18 12:38:06	1.1
+++ source/mapalgorithms.cpp	2002/10/18 12:38:23
@@ -117,7 +117,7 @@
 
    int dx = xp2-xp1;
    int dy = yp2-yp1;
-   double at = atan2 ( dy, dx );
+   double at = atan2 ( (double)dy, (double)dx );
    // printf("%d / %d / %f \n", dx, dy, at);
    at -= offset;
    while ( at < 0 )
