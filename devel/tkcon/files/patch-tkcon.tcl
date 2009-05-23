--- tkcon.tcl.orig	2009-02-27 09:17:21.000000000 +0900
+++ tkcon.tcl	2009-05-16 18:38:23.000000000 +0900
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
