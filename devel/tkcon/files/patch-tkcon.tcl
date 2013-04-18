--- tkcon.tcl.orig	2009-02-27 01:17:21.000000000 +0100
+++ tkcon.tcl	2013-04-16 09:25:50.000000000 +0200
@@ -194,7 +192,7 @@
 	RCS		{RCS: @(#) $Id: tkcon.tcl,v 1.102 2008/02/07 21:02:53 hobbs Exp $}
 	HEADURL		{http://tkcon.cvs.sourceforge.net/tkcon/tkcon/tkcon.tcl?rev=HEAD}
 
-	docs		"http://tkcon.sourceforge.net/"
+	docs		"file:%%DOCSDIR%%/index.html"
 	email		{jeff(a)hobbs(.)org}
 	root		.
 	uid		0
@@ -1586,8 +1584,8 @@
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
