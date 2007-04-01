--- ros/src/OS/ModelingAlgorithms.tcl.orig	Thu Jun 30 11:18:06 2005
+++ ros/src/OS/ModelingAlgorithms.tcl	Thu Aug 10 22:18:25 2006
@@ -45,10 +45,16 @@
 	HP-UX {
 	}
 	Linux {
-	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
-	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/solaris"
-	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
-           lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]" 
+	   lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
+	   lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/linux"
+	   lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
+           lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
+	}
+	FreeBSD {
+	   lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
+	   lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/freebsd"
+	   lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
+           lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
 	}
 	SunOS {
 	    lappend l "/usr/openwin/include"
@@ -77,6 +83,8 @@
 	HP-UX {
 	}
 	Linux {
+	}
+	FreeBSD {
 	}
 	SunOS {
 	    lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib -R[wokparam -v %CSF_TCL_HOME]/lib -ltcl"
