--- ros/src/OS/DataExchange.tcl.orig	Mon Jul 25 08:47:10 2005
+++ ros/src/OS/DataExchange.tcl	Tue Aug  1 21:03:42 2006
@@ -59,6 +59,12 @@
 	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
            lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]" 
 	}
+	FreeBSD {
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/freebsd"
+	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
+            lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
+	}
 	SunOS {
 	    lappend l "/usr/openwin/include"
 	    lappend l "/usr/dt/include"
@@ -86,6 +92,8 @@
 	HP-UX {
 	}
 	Linux {
+	}
+	FreeBSD {
 	}
 	SunOS {
 	    lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib -R[wokparam -v %CSF_TCL_HOME]/lib -ltcl"
