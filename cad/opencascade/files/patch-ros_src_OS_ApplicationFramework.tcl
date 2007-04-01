--- ros/src/OS/ApplicationFramework.tcl.orig	Thu Sep 22 19:55:08 2005
+++ ros/src/OS/ApplicationFramework.tcl	Thu Aug 10 22:46:41 2006
@@ -68,6 +68,12 @@
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
@@ -98,6 +104,11 @@
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
