--- xsl/titlepage2.xsl.orig	Sat Oct 16 20:19:35 2004
+++ xsl/titlepage2.xsl	Sat Oct 16 20:20:35 2004
@@ -4,6 +4,8 @@
 <!-- This is a customization layer, to change some of the things in
    auto-generated titlepage.xsl -->
 
+   <xsl:import href="titlepage.xsl"/>
+
 <xsl:template xmlns:xsl="http://www.w3.org/1999/XSL/Transform" name="book.titlepage">
 <!-- Added to create a separate titlepage -->
   <xsl:param name="next" select="."/>
@@ -217,4 +219,4 @@
     </xsl:otherwise>
    </xsl:choose>
 </xsl:template>
-</xsl:stylesheet>
\ No newline at end of file
+</xsl:stylesheet>
