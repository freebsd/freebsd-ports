--- tkcon.tcl.orig	2009-02-27 01:17:21.000000000 +0100
+++ tkcon.tcl	2013-09-26 16:10:14.000000000 +0200
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
@@ -5018,6 +5018,11 @@
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
