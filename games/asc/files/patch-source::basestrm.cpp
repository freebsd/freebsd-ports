
$FreeBSD$

--- source/basestrm.cpp	2001/02/17 15:08:39	1.1
+++ source/basestrm.cpp	2001/02/17 15:08:54
@@ -895,7 +892,7 @@
    while (actpos2 < size) { 
       if (datasize == 0) 
           if ( excpt ) {
-             throw treadafterend ( getDeviceName() );
+             goto except1;
 			}
           else
              return actpos2;
@@ -915,6 +912,9 @@
    } 
 
    return actpos2;
+
+except1:
+   throw treadafterend ( getDeviceName() );
 } 
 
 
@@ -945,10 +945,14 @@
       } 
       else 
          if (actmempos > memsize) 
-            throw tinternalerror ( __FILE__, __LINE__ );
+            goto except1;
                                    
       actpos2 += s;
    } 
+   return;
+
+except1:
+   throw tinternalerror ( __FILE__, __LINE__ );
 } 
 
 
