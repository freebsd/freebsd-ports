
$FreeBSD$

--- source/basestrm.cpp.orig	Tue Oct  1 16:11:44 2002
+++ source/basestrm.cpp	Fri Oct 18 15:04:21 2002
@@ -1008,7 +1011,7 @@
    while (actpos2 < size) {
       if (datasize == 0)
           if ( excpt ) {
-             throw treadafterend ( getDeviceName() );
+             goto except1;
 			}
           else
              return actpos2;
@@ -1028,6 +1031,9 @@
    } 
 
    return actpos2;
+
+except1:
+   throw treadafterend ( getDeviceName() );
 } 
 
 
@@ -1058,10 +1064,14 @@
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
 
 
