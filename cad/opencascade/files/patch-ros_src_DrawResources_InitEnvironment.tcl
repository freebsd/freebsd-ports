--- ros/src/DrawResources/InitEnvironment.tcl.orig	Fri Sep 21 09:50:26 2001
+++ ros/src/DrawResources/InitEnvironment.tcl	Thu Aug 10 22:58:39 2006
@@ -7,6 +7,8 @@
     set LINE_FROM_UNAME [ exec uname -a ] ;
     if { [ regexp SunOS $LINE_FROM_UNAME ] } {
 	return "sun"
+    }  elseif { [ regexp FreeBSD $LINE_FROM_UNAME ] } {
+	return "bsd"
     }  elseif { [ regexp IRIX $LINE_FROM_UNAME ] } {
 	return "sil"
     } elseif { [ regexp OSF $LINE_FROM_UNAME ] } {
