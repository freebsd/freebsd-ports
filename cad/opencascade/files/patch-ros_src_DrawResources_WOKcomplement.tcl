--- ros/src/DrawResources/WOKcomplement.tcl.orig	Fri Sep 21 09:50:27 2001
+++ ros/src/DrawResources/WOKcomplement.tcl	Tue Aug  1 21:13:53 2006
@@ -6,7 +6,10 @@
     set LINE_FROM_UNAME [ exec uname -a ] ;
     if { [ regexp SunOS $LINE_FROM_UNAME ] } {
 	return "sun"
-    } 
+    }
+    elseif { [ regexp FreeBSD $LINE_FROM_UNAME ] } {
+	return "bsd"
+    }
     elseif { [ regexp IRIX $LINE_FROM_UNAME ] } {
 	return "sil"
     }
