--- pref.tcl.orig	2004-03-11 11:26:56 UTC
+++ pref.tcl
@@ -116,10 +116,16 @@
     }
 
     # XXX People do not seem to like the motif-style popup behavior
-#    global tk_strictMotif
-#    if {!$tk_strictMotif} {
-#	bind Menubutton <Any-ButtonRelease-1> {tkMenuUnpost {}}
-#    }
+    global tk_strictMotif
+    if {!$tk_strictMotif} {
+	bind Menubutton <Any-ButtonRelease-1> {tkMenuUnpost {}}
+	set tv [info tclversion]
+	if {[package vcompare $tv 8.4] >= 0} {
+	    bind Menubutton <Any-ButtonRelease-1> {::tk::MenuUnpost {}}
+	} else {
+	    bind Menubutton <Any-ButtonRelease-1> {tkMenuUnpost {}}
+	}
+    }
 
     # Handle command line preferences
     global ical
