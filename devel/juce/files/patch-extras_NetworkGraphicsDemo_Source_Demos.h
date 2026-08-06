-- Replace removed Drawable::createFromSVG(XmlElement) with createFromSVGString.
-- The API changed in JUCE 9; the demo ships with the old call.
--- extras/NetworkGraphicsDemo/Source/Demos.h.orig	2026-08-05 19:49:26 UTC
+++ extras/NetworkGraphicsDemo/Source/Demos.h
@@ -92,7 +92,7 @@ struct BackgroundLogo : public AnimatedContent
             </svg>
             )blahblah";
 
-        logo = Drawable::createFromSVG (*parseXML (logoData));
+        logo = Drawable::createFromSVGString (logoData);
     }
 
     String getName() const override      { return "Background Image"; }
