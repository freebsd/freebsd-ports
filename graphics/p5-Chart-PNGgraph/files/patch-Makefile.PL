--- Makefile.PL.orig	Wed Apr  5 02:45:37 2000
+++ Makefile.PL	Thu Aug 29 21:56:59 2002
@@ -37,8 +37,8 @@
 # HAVE EDITED GIFgraph::Convert.
-if (GD::Image->can('gif'))
-{
-	print "Checking for conversion of GIF to PNG\n";
-	require GIFgraph::Convert;
-	GIFgraph::Convert::checkImageMagick();
-}
+#if (GD::Image->can('gif'))
+#{
+#	print "Checking for conversion of GIF to PNG\n";
+#	require GIFgraph::Convert;
+#	GIFgraph::Convert::checkImageMagick();
+#}
 
