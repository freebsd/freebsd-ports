--- configure_start.sh.orig	Sat Feb  8 05:00:52 2003
+++ configure_start.sh	Sun Feb  9 22:49:19 2003
@@ -45,16 +45,17 @@
 pkgetcdir	= $pkgetcdir
 pkglibdir	= $pkglibdir
 pkgincludedir	= $pkgincludedir
-manprefix	= $datadir
-mandir		= $mandir
-man1dir		= $man1dir
-man2dir		= $man2dir
-man3dir		= $man3dir
-man4dir		= $man4dir
-man5dir		= $man5dir
-man6dir		= $man6dir
-man7dir		= $man7dir
-man8dir		= $man8dir
-manndir		= $manndir
-manldir		= $manldir
-EOF
\ No newline at end of file
+manprefix	= \$(prefix)
+mandir		= \$(manprefix)/man
+man1dir		= \$(mandir)/man1
+man2dir		= \$(mandir)/man2
+man3dir		= \$(mandir)/man3
+man4dir		= \$(mandir)/man4
+man5dir		= \$(mandir)/man5
+man6dir		= \$(mandir)/man6
+man7dir		= \$(mandir)/man7
+man8dir		= \$(mandir)/man8
+manndir		= \$(mandir)/mann
+manldir		= \$(mandir)/manl
+EOF
+
