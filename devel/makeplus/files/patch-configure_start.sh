--- configure_start.sh.orig	Sun Feb  9 22:27:05 2003
+++ configure_start.sh	Sun Feb  9 22:27:43 2003
@@ -45,7 +45,7 @@
 pkgetcdir	= $pkgetcdir
 pkglibdir	= $pkglibdir
 pkgincludedir	= $pkgincludedir
-manprefix	= $datadir
+manprefix	= $prefix
 mandir		= $mandir
 man1dir		= $man1dir
 man2dir		= $man2dir
@@ -57,4 +57,5 @@
 man8dir		= $man8dir
 manndir		= $manndir
 manldir		= $manldir
-EOF
\ No newline at end of file
+EOF
+
