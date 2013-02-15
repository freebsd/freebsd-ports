--- kmrml/kmrml/mrml_elements.h.orig	2012-06-18 18:08:26.000000000 +0000
+++ kmrml/kmrml/mrml_elements.h
@@ -157,7 +157,7 @@ namespace KMrml
                 QDomElement elem = list.item( i ).toElement();
                 t item( elem );
                 if ( item.isValid() )
-                    append( item );
+                    this->append( item );
             }
         }
 
