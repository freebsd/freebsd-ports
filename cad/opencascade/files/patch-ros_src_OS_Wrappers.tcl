--- ros/src/OS/Wrappers.tcl.orig	Mon Dec  6 14:30:49 2004
+++ ros/src/OS/Wrappers.tcl	Tue Aug  1 21:05:53 2006
@@ -48,6 +48,12 @@
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
@@ -75,6 +81,8 @@
 	HP-UX {
 	}
 	Linux {
+	}
+	FreeBSD {
 	}
 	SunOS {
 	}
