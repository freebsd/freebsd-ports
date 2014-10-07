--- tkcon.tcl.orig	2009-02-27 01:17:21.000000000 +0100
+++ tkcon.tcl	2013-10-01 11:43:39.000000000 +0200
@@ -1,6 +1,6 @@
 #!/bin/sh
 # \
-exec wish "$0" ${1+"$@"}
+exec %%WISH%% "$0" ${1+"$@"}
 
 #
 ## tkcon.tcl
@@ -194,7 +194,7 @@
 	RCS		{RCS: @(#) $Id: tkcon.tcl,v 1.102 2008/02/07 21:02:53 hobbs Exp $}
 	HEADURL		{http://tkcon.cvs.sourceforge.net/tkcon/tkcon/tkcon.tcl?rev=HEAD}
 
-	docs		"http://tkcon.sourceforge.net/"
+	docs		"file:%%DOCSDIR%%/index.html"
 	email		{jeff(a)hobbs(.)org}
 	root		.
 	uid		0
@@ -1586,8 +1586,8 @@
     foreach m [list [menu $w.help] [menu $w.pop.help]] {
 	$m add command -label "About " -underline 0 -accel Ctrl-A \
 		-command ::tkcon::About
-	$m add command -label "Retrieve Latest Version" -underline 0 \
-		-command ::tkcon::Retrieve
+	# $m add command -label "Retrieve Latest Version" -underline 0 \
+	# 	-command ::tkcon::Retrieve
 	if {![catch {package require ActiveTcl} ver]} {
 	    set cmd ""
 	    if {$tcl_platform(platform) == "windows"} {
@@ -2497,13 +2497,19 @@
     proc ::tkcon::Destroy {{slave {}}} {
 	variable PRIV
 
+	set confirmed 0
+	if {[tk_messageBox -parent $PRIV(root) -title "Close window?" \
+	    -message "Close the current window?" -default no \
+	    -icon question -type yesno] == "yes"} { set confirmed 1}
+
+	if {!$confirmed} {
+	    return
+	}
+
 	# Just close on the last one
 	if {[llength $PRIV(interps)] == 1} { exit }
 	if {"" == $slave} {
 	    ## Main interpreter close request
-	    if {[tk_messageBox -parent $PRIV(root) -title "Quit tkcon?" \
-		     -message "Close all windows and exit tkcon?" \
-		     -icon question -type yesno] == "yes"} { exit }
 	    return
 	} elseif {$slave == $::tkcon::OPT(exec)} {
 	    set name  [tk appname]
@@ -5018,6 +5024,11 @@
     ## We really didn't want the newline insertion
     bind TkConsole <Control-Key-o> {}
 
+    ## in 8.6b3, the virtual events <<NextLine>> and <<PrevLine>>
+    #  mess up our history feature
+    bind TkConsole <<NextLine>> {}
+    bind TkConsole <<PrevLine>> {}
+
     ## Now make all our virtual event bindings
     foreach {ev key} [subst -nocommand -noback {
 	<<TkCon_Exit>>		<Control-q>
