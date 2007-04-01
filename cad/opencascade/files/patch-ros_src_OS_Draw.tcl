--- ros/src/OS/Draw.tcl.orig	Wed Nov 26 09:30:49 2003
+++ ros/src/OS/Draw.tcl	Thu Aug 10 22:08:37 2006
@@ -50,6 +50,13 @@
 	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
             lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]" 
 	}
+	FreeBSD {
+	    lappend l "-I/usr/local/include"
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/freebsd"
+	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
+            lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
+	}
 	SunOS {
 	    lappend l "/usr/openwin/include"
 	    lappend l "/usr/dt/include"
@@ -79,6 +86,12 @@
 	HP-UX {
 	}
 	Linux {
+	    lappend l -L/usr/X11R6/lib
+            lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib"
+            lappend l "-L[wokparam -v %STLPortHome]/lib"
+	}
+	FreeBSD {
+	    lappend l -L/usr/local/lib
 	    lappend l -L/usr/X11R6/lib
             lappend l "-L[wokparam -v %CSF_TCL_HOME]/lib"
             lappend l "-L[wokparam -v %STLPortHome]/lib"
