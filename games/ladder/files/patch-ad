--- lplay.c.org	Tue Nov 11 20:01:51 1997
+++ lplay.c	Wed Feb 18 22:33:56 1998
@@ -54,7 +54,7 @@
         mvaddstr(row,0,t);
 
         /* find points of release */
-        for( s = t; s = strchr(s,CRELEAS); s++ )
+        for( s = t; (s = strchr(s,CRELEAS)); s++ )
         {
             rel->row = row;
             rel->col = s - t;
@@ -67,7 +67,7 @@
 
     /* find lad */
     for( row = 0; row < DIMROW; row++ ) 
-        for( s = t = bg[row]; s = strchr(s,CLAD); s++ )
+        for( s = t = bg[row]; (s = strchr(s,CLAD)); s++ )
         {
             /* nasty, check for CLAD's surrounded by CFREEs */
             if( s[-1] != CFREE || s[1] != CFREE )
@@ -433,6 +433,8 @@
                     else
                         dir = STOP;
                     break;
+				default:
+					break;
             }
         }
 
