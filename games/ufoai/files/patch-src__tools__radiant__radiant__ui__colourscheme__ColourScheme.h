--- ./src/tools/radiant/radiant/ui/colourscheme/ColourScheme.h.orig	2014-06-05 06:18:39.000000000 +0200
+++ ./src/tools/radiant/radiant/ui/colourscheme/ColourScheme.h	2014-08-07 16:51:10.093299939 +0200
@@ -52,8 +52,6 @@
 		ColourItem _emptyColour;
 
 	public:
-		// Constructors
-		ColourScheme() {};
 		// Constructs a ColourScheme from a given xml::node
 		ColourScheme(xml::Node& schemeNode);
 
