--- tcl/ayam.tcl.orig	2011-01-04 13:54:09.000000000 +0100
+++ tcl/ayam.tcl	2011-01-04 13:54:31.000000000 +0100
@@ -555,7 +555,7 @@
  pady 3
  failsafe 0
  showsplash 1
- aysplash "../lib/ayam-splash.gif"
+ aysplash "%%DATADIR%%/ayam-splash.gif"
  filename ""
  tmpfiles ""
  ayamrc "~/.ayamrc"
