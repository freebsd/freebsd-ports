===================================================================
RCS file: /usr/repos/kde/kdegraphics/ksvg/impl/SVGHelperImpl.h,v
retrieving revision 1.22
retrieving revision 1.22.2.1
diff -u -p -r1.22 -r1.22.2.1
--- ksvg/impl/SVGHelperImpl.h	2003/08/27 20:08:25	1.22
+++ ksvg/impl/SVGHelperImpl.h	2004/06/12 10:32:59	1.22.2.1
@@ -26,7 +26,7 @@
 #include "SVGLengthImpl.h"
 
 #include "ksvg_lookup.h"
-
+#include "SVGElementImpl.h"
 class QRect;
 class QString;
 
@@ -56,7 +56,7 @@ public:
 		{
 			T *cast = dynamic_cast<T *>(element->ownerDoc()->getElementFromHandle(node.handle()));
 			if(cast)
-				cast->putValueProperty(element->ownerDoc()->ecmaEngine()->globalExec(), token, KJS::String(value), Internal);
+				cast->putValueProperty(element->ownerDoc()->ecmaEngine()->globalExec(), token, KJS::String(value), KJS::Internal);
 		}
 	}
 
