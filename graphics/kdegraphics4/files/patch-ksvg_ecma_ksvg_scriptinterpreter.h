===================================================================
RCS file: /usr/repos/kde/kdegraphics/ksvg/ecma/ksvg_scriptinterpreter.h,v
retrieving revision 1.12
retrieving revision 1.12.2.1
diff -u -p -r1.12 -r1.12.2.1
--- ksvg/ecma/ksvg_scriptinterpreter.h	2003/05/10 09:32:50	1.12
+++ ksvg/ecma/ksvg_scriptinterpreter.h	2004/06/04 16:53:16	1.12.2.1
@@ -100,7 +100,7 @@ inline KJS::Object cacheGlobalBridge(KJS
 	{
 		ClassCtor* ctor = new ClassCtor(exec); // create the ClassCtor instance
 		KJS::Object newObject(new KSVGBridge<ClassCtor>(exec, ctor)); // create the bridge around it
-		exec->interpreter()->globalObject().put(exec, propertyName, newObject, Internal);
+		exec->interpreter()->globalObject().put(exec, propertyName, newObject, KJS::Internal);
 		return newObject;
 	}
 }
