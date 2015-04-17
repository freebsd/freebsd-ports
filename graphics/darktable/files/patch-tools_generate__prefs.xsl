--- tools/generate_prefs.xsl.orig	2015-04-03 13:59:08 UTC
+++ tools/generate_prefs.xsl
@@ -231,7 +231,9 @@
 		<xsl:text>    gint min = 0;&#xA;    gint max = G_MAXINT;&#xA;</xsl:text>
 		<xsl:apply-templates select="type" mode="range"/>
 		<xsl:text>  </xsl:text><xsl:apply-templates select="type" mode="factor"/>
-		<xsl:text>    min *= factor; max *= factor;
+		<xsl:text>    double tmp;
+    tmp = min * (double)factor; min = tmp;
+    tmp = max * (double)factor; max = tmp;
     widget = gtk_spin_button_new_with_range(min, max, 1);
     gtk_spin_button_set_digits(GTK_SPIN_BUTTON(widget), 0);
     gtk_spin_button_set_value(GTK_SPIN_BUTTON(widget), dt_conf_get_int("</xsl:text><xsl:value-of select="name"/><xsl:text>") * factor);
