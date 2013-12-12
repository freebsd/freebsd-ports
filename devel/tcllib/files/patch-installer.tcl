--- installer.tcl.orig	2013-04-26 17:00:27.000000000 +0200
+++ installer.tcl	2013-04-26 17:00:45.000000000 +0200
@@ -218,7 +218,7 @@
 
 	if {[file exists $aexe.man]} {
 	    if {$config(doc,nroff)} {
-		_manfile $aexe.man nroff n $config(doc,nroff,path)
+		_manfile $aexe.man nroff tcllib.n $config(doc,nroff,path)
 	    }
 	    if {$config(doc,html)} {
 		_manfile $aexe.man html html $config(doc,html,path)
@@ -247,7 +247,7 @@
 	xinstall   pkg $config(pkg,path)
 	gen_main_index $config(pkg,path) $package_name $package_version
 	if {$config(doc,nroff)} {
-	    xinstall doc nroff n    $config(doc,nroff,path)
+	    xinstall doc nroff tcllib.n $config(doc,nroff,path)
 	}
 	if {$config(doc,html)}  {
 	    xinstall doc html  html $config(doc,html,path)
