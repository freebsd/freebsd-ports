--- docs/docbook-xsl-ns-html-customization-freebsd.xsl.orig	2023-02-18 11:01:11 UTC
+++ docs/docbook-xsl-ns-html-customization-freebsd.xsl
@@ -0,0 +1,10 @@
+<?xml version='1.0'?>
+<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
+
+<!-- import the original docbook template -->
+<xsl:import href="%%LOCALBASE%%/share/xsl/docbook-ns/html/docbook.xsl"/>
+
+<!-- import the sjasmplus customization -->
+<xsl:import href="docbook-xsl-ns-html-customization.xsl"/>
+
+</xsl:stylesheet>
