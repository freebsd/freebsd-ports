===================================================================
RCS file: /usr/repos/kde/kdegraphics/ksvg/ecma/ksvg_bridge.h,v
retrieving revision 1.69
retrieving revision 1.69.2.2
diff -u -p -r1.69 -r1.69.2.2
--- ksvg/ecma/ksvg_bridge.h	2003/10/13 20:24:12	1.69
+++ ksvg/ecma/ksvg_bridge.h	2004/06/12 18:10:53	1.69.2.2
@@ -23,7 +23,9 @@
 
 #include <kdebug.h>
 
-#include "ksvg_lookup.h"
+#include <kjs/object.h>
+#include <kjs/lookup.h>
+#include <kjs/interpreter.h> // for ExecState
 
 namespace KJS
 {
@@ -90,7 +92,7 @@ public:
 //			kdDebug(26004) << "KSVGBridge::put(), " << propertyName.qstring() << " Name: " << classInfo()->className << " Object: " << m_impl << endl;
 
 		// Try to see if we know this property (and need to take special action)
-		if(m_impl->put(exec, propertyName, value, attr))
+		if(this->m_impl->put(exec, propertyName, value, attr))
 			return;
 
 		// We don't -> set property in ObjectImp.
