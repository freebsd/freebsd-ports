--- ros/src/OS/FoundationClasses.tcl.orig	Thu Jun 30 11:18:06 2005
+++ ros/src/OS/FoundationClasses.tcl	Thu Aug 10 22:14:31 2006
@@ -44,7 +44,13 @@
 	}
 	Linux {
 	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
-	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/inclide/linux"
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/linux"
+	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
+            lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
+	}
+	FreeBSD {
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/FreeBSD"
 	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
             lappend l "[lindex [lindex [wokparam -v %STLPortInclude] 0] 0]"
 	}
@@ -53,7 +59,7 @@
 	    lappend l "/usr/dt/include"
 	    lappend l "[lindex [wokparam -v %CSF_CXX_INCLUDE] 0]"
 	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include"
-	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/inclide/solaris"
+	    lappend l "-I[lindex [wokparam -v %CSF_JavaHome] 0]/include/solaris"
 	    lappend l "[lindex [wokparam -v %CSF_TCL_HOME] 0]/include"
 	}
 	IRIX {
@@ -75,6 +81,8 @@
 	HP-UX {
 	}
 	Linux {
+	}
+	FreeBSD {
 	}
 	SunOS {
 	}
