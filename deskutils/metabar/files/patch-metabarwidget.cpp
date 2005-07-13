--- src/metabarwidget.cpp.orig	Wed Jul 13 20:30:46 2005
+++ src/metabarwidget.cpp	Wed Jul 13 20:31:20 2005
@@ -369,7 +369,7 @@
       
         DOM::DOMString innerHTML;
         innerHTML += QString("<ul style=\"width: %1px; height: %1px\">").arg(image.width(), image.height());
-        innerHTML += "<object class=\preview\" type=\"";
+        innerHTML += "<object class=\"preview\" type=\"";
         innerHTML += item->mimetype();
         innerHTML += "\" data=\"";
         innerHTML += item->url().url();
