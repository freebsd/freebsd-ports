--- configure_start.sh.orig	Sat Feb  8 05:00:52 2003
+++ configure_start.sh	Mon Feb 10 18:30:53 2003
@@ -28,33 +28,41 @@
 #define VERSION "$VERSION"
 EOF
 
+case `uname` in 
+    *BSD) 
+	manprefix="\$(prefix)";;
+    *)	
+	manprefix="\$(datadir)";;
+esac
+
 cat > config.mk <<EOF
 prefix		= $prefix
-bindir		= $bindir
-sbindir		= $sbindir
-libexecdir	= $libexecdir
-datadir		= $datadir
-sysconfdir	= $sysconfdir
-sharedstatedir	= $sharedstatedir
-localstatedir	= $localstatedir
-libdir		= $libdir
-infodir		= $infodir
-includedir	= $includedir
-pkgdatadir	= $pkgdatadir
-docdir		= $docdir
-pkgetcdir	= $pkgetcdir
-pkglibdir	= $pkglibdir
-pkgincludedir	= $pkgincludedir
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
+bindir		= \$(prefix)/bin
+sbindir		= \$(prefix)/sbin
+libexecdir	= \$(prefix)/libexec
+datadir		= \$(prefix)/share
+sysconfdir	= \$(prefix)/etc
+sharedstatedir	= \$(prefix)/com
+localstatedir	= \$(prefix)/var
+libdir		= \$(prefix)/lib
+infodir		= \$(prefix)/info
+includedir	= \$(prefix)/include
+pkgdatadir	= \$(datadir)/$PACKAGE
+docdir		= \$(datadir)/doc/$PACKAGE
+pkgetcdir	= \$(sysconfdir)/$PACKAGE
+pkglibdir	= \$(libdir)/$PACKAGE
+pkgincludedir	= \$(includedir)/$PACKAGE
+manprefix	= $manprefix
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
