
$FreeBSD$

--- source/gamedlg.cpp.orig	Fri Oct 18 19:39:24 2002
+++ source/gamedlg.cpp	Fri Oct 18 19:40:48 2002
@@ -3788,7 +3791,7 @@
                             int step =  ( target->service[displayed[mp]].maxAmount - target->service[displayed[mp]].minAmount ) / 100;
                             if ( step == 0 )
                                step = 1;
-                            step = int( pow ( 10, int ( log10 ( step ))));
+                            step = int( pow ( (double)10, int ( log10 ( (double)step ))));
 
                             oldpos[mp] = newpos[mp];
 
