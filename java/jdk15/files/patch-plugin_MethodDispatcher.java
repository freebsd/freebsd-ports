$FreeBSD$

--- ../../deploy/src/plugin/src/share/classes/sun/plugin/com/MethodDispatcher.java	22 Oct 2003 23:04:20 -0000	1.1
+++ ../../deploy/src/plugin/src/share/classes/sun/plugin/com/MethodDispatcher.java	3 Dec 2004 03:56:58 -0000	1.2
@@ -1,7 +1,7 @@
 /*
- * @(#)MethodDispatcher.java	1.5 03/01/23
+ * @(#)MethodDispatcher.java	1.10 04/06/20
  *
- * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
+ * Copyright 2004 Sun Microsystems, Inc. All rights reserved.
  * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
  */
 
@@ -9,6 +9,7 @@
 
 import java.lang.reflect.Method;
 import sun.plugin.util.Trace;
+import sun.plugin.javascript.JSClassLoader;
 
 /**
  * A <code>MethodDispatcher</code> provides information about,
@@ -47,11 +48,16 @@
 	Object retObj = null;
 	if(method != null && obj != null) {
 	    Trace.msgLiveConnectPrintln("com.method.invoke", new Object[] {method});
+	    Class theClass = obj.getClass();
 	    Object[] params = TypeConverter.convertObjectArray(
 				    method.getParameterTypes(), args);
-	    retObj = Utils.convertReturn( method.getReturnType(), 
-					  method.invoke(obj, params ));
+	    // check if the class is private and the method is public
+	    retObj = JSClassLoader.invoke(method, obj, params);
 	}
 	return retObj;
+    }
+
+    public Class getReturnType() {
+	return method.getReturnType();
     }
 }
