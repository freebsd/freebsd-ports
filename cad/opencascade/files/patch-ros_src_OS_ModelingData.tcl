--- ros/src/OS/ModelingData.tcl.orig	Wed Nov 26 09:36:01 2003
+++ ros/src/OS/ModelingData.tcl	Thu Aug 10 22:21:03 2006
@@ -43,6 +43,12 @@
 	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
            lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]" 
 	}
+	FreeBSD {
+	   lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
+	   lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/freebsd"
+	   lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
+           lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
+	}
 	SunOS {
 	    lappend l "/usr/openwin/include"
 	    lappend l "/usr/dt/include"
@@ -70,6 +76,8 @@
 	HP-UX {
 	}
 	Linux {
+	}
+	FreeBSD {
 	}
 	SunOS {
 	    lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib -R[wokparam -v %CSF_TCL_HOME]/lib -ltcl"
