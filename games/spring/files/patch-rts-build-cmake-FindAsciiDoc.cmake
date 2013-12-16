--- rts/build/cmake/FindAsciiDoc.cmake.orig	2013-11-09 03:59:29.984998154 +0400
+++ rts/build/cmake/FindAsciiDoc.cmake	2013-11-09 04:04:52.833206309 +0400
@@ -41,6 +41,7 @@
 	PATH_SUFFIXES
 		xml/docbook/stylesheet/nwalsh/manpages
 		sgml/docbook/xsl-stylesheets/manpages
+		xsl/docbook/manpages
 	DOC "DocBook XSL Style-Sheet"
 	)
 
