
$FreeBSD$

--- source/building.cpp	2002/10/18 13:03:04	1.1
+++ source/building.cpp	2002/10/18 13:03:22
@@ -1022,7 +1022,7 @@
 
 int getstepwidth ( int max )
 {
-   double ep = log10 ( max );
+   double ep = log10 ( (double)max );
    if ( ep > 2.0 )
       ep -= 2.0;
    else
