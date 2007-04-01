--- ros/src/OS/WOK.tcl.orig	Wed Nov 26 09:36:37 2003
+++ ros/src/OS/WOK.tcl	Tue Aug  1 20:59:22 2006
@@ -69,6 +69,13 @@
            lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]" 
 	}
 
+	FreeBSD {
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/freebsd"
+	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
+            lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
+	}
+
 	SunOS {
 	    lappend l "/usr/openwin/include"
 	    lappend l "/usr/dt/include"
@@ -95,6 +102,10 @@
 	HP-UX {
 	}
 	Linux {
+	    lappend l /usr/X11R6/lib
+	}
+
+	FreeBSD {
 	    lappend l /usr/X11R6/lib
 	}
 
