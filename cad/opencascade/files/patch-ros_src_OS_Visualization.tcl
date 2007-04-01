--- ros/src/OS/Visualization.tcl.orig	Fri Jun 25 19:07:24 2004
+++ ros/src/OS/Visualization.tcl	Thu Aug 10 22:42:55 2006
@@ -47,6 +47,12 @@
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
 	    lappend l "\$OPENWINHOME/include"
 	    lappend l "/usr/openwin/include/X11"
@@ -76,6 +82,11 @@
 	}
 	Linux {
 	    lappend l /usr/X11R6/lib
+	}
+	FreeBSD {
+	    lappend l /usr/X11R6/lib
+	    lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib -R[wokparam -v %CSF_TCL_HOME]/lib -ltcl"
+	    lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib -R[wokparam -v %CSF_TCL_HOME]/lib -ltk"
 	}
 	SunOS {
 	    lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib -R[wokparam -v %CSF_TCL_HOME]/lib -ltcl"
