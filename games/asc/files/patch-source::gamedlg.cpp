
$FreeBSD$

--- source/gamedlg.cpp	2002/10/18 12:57:12	1.2
+++ source/gamedlg.cpp	2002/10/18 12:57:38
@@ -3794,7 +3794,7 @@
                             int step =  ( target->service[displayed[mp]].maxAmount - target->service[displayed[mp]].minAmount ) / 100;
                             if ( step == 0 )
                                step = 1;
-                            step = int( pow ( 10, int ( log10 ( (double)step ))));
+                            step = int( pow ( (double)10, int ( log10 ( (double)step ))));
 
                             oldpos[mp] = newpos[mp];
 
