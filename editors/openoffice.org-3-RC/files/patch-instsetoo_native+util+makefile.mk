For instsetoo_native project, we should use FORMAT*=-format bsd.
However, for FreeBSD, we cannot write script towards multiple line,
so -format bsd break builds. We temporary set -format portable at
the moment so that we can treat as we want.

Index: instsetoo_native/util/makefile.mk
===================================================================
RCS file: /cvs/installation/instsetoo_native/util/makefile.mk,v
retrieving revision 1.13
diff -u -r1.13 makefile.mk
--- instsetoo_native/util/makefile.mk	10 Dec 2004 17:03:50 -0000	1.13
+++ instsetoo_native/util/makefile.mk	20 Dec 2004 11:32:33 -0000
@@ -82,6 +82,12 @@
 FORMAT*=-format pkg
 .ENDIF
 
+.IF "$(OS)" == "FREEBSD"
+#bsd is preffered but epm does not produce valid packages atm
+#FORMAT*=-format bsd
+FORMAT*=-format portable
+.ENDIF
+
 # epm supports the following formats:
 # aix - AIX software distribution
 # bsd - FreeBSD, NetBSD, or OpenBSD software distribution
