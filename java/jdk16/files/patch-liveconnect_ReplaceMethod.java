$FreeBSD$

--- ../../deploy/src/plugin/src/share/classes/sun/plugin/liveconnect/ReplaceMethod.java	1 Jan 1970 00:00:00 -0000
+++ ../../deploy/src/plugin/src/share/classes/sun/plugin/liveconnect/ReplaceMethod.java	3 Dec 2004 03:56:58 -0000	1.1
@@ -0,0 +1,88 @@
+/*
+ * @(#)ReplaceMethod.java	1.1 04/06/20
+ *
+ * Copyright 2004 Sun Microsystems, Inc. All rights reserved.
+ * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
+ */
+package sun.plugin.liveconnect;
+
+import java.lang.reflect.Method;
+import java.lang.reflect.Modifier;
+import sun.plugin.javascript.JSClassLoader;
+
+public class ReplaceMethod {
+    /*
+     * Replace the inaccessible method by a suitable method on public
+     * class/interface accessible to the calling JavaScript code. 
+     * Returns null if accessible method is not found.
+     */
+     static Method getJScriptMethod(Method start) {
+	Class cls = start.getDeclaringClass();
+
+        if (Modifier.isPublic(cls.getModifiers())) {
+	    return start;
+        }
+
+	String name = start.getName();
+	Class[] params = start.getParameterTypes();
+
+	Method result = null;
+	while (cls != null && result == null) {
+	    result = getPublicMethod(cls, name, params);
+	    if (result == null) {
+	        result = getJScriptInterfaceMethod(cls, name, params);
+	    }
+	    cls = cls.getSuperclass();
+	}
+	return result;
+    }
+
+    /*
+     * Process the immediate interfaces of this class or interface.
+     */
+    static Method getJScriptInterfaceMethod(Class cls, String name, Class[] params) {
+	Method result = null;
+	Class[] intfs = cls.getInterfaces();
+	for (int i=0; i < intfs.length && result == null; i++) {
+	    Class intf = intfs[i];
+	    result = getPublicMethod(intf, name, params);
+	    if (result == null) {
+	        result = getJScriptInterfaceMethod(intf, name, params);
+	    }
+	}
+	return result;
+    }
+
+    /*
+     *
+     * Process the methods in this class or interface
+     */
+    static private Method getPublicMethod(Class cls, String name, Class[] params) {
+	try {
+	    /*
+	     * This class or interface is non-public so we
+	     * can't use any of it's methods. Go back and
+	     * try again with a superclass or superinterface.
+	     */
+	    if (!Modifier.isPublic(cls.getModifiers())) {
+		return null;
+	    }
+
+	    /*
+	     * This call will fail if 'cls' is in a restricted
+	     * package and we don't have permission to access
+	     * it.
+	     */
+	    if (!JSClassLoader.isPackageAccessible(cls)) {
+		return null;
+	    }
+	    return cls.getMethod(name, params);
+	} catch (NoSuchMethodException nsme) {
+	    return null;
+	} catch (SecurityException se) {
+	    return null;
+        }
+    }
+}
+
+
