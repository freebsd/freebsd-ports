$FreeBSD$

--- ../../deploy/src/plugin/src/share/classes/sun/plugin/javascript/ReflectUtil.java	1 Jan 1970 00:00:00 -0000
+++ ../../deploy/src/plugin/src/share/classes/sun/plugin/javascript/ReflectUtil.java	3 Dec 2004 03:56:58 -0000	1.1
@@ -0,0 +1,307 @@
+/*
+ * @(#)ReflectUtil.java	1.1 04/06/20
+ *
+ * Copyright 2004 Sun Microsystems, Inc. All rights reserved.
+ * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
+ */
+package sun.plugin.javascript;
+
+import java.lang.reflect.Method;
+import java.lang.reflect.Field;
+import java.lang.reflect.Modifier;
+import java.lang.reflect.InvocationTargetException;
+import java.util.HashMap;
+import java.util.ArrayList;
+import java.util.List;
+import java.util.Map;
+import java.util.Iterator;
+import sun.plugin.javascript.JSClassLoader;
+
+public class ReflectUtil {
+    /*
+     * Discover the public methods on public classes
+     * and interfaces accessible to the calling
+     * JavaScript code. 
+     */
+     public static Method[] getJScriptMethods(Class cls) {
+	List m = new ArrayList(); /* the valid methods we find */
+
+	/*
+	 * Temporary map of method signatures when we decide
+	 * that a simple call to target.getMethods() returns
+	 * inaccessible methods and we must search for alternative
+	 * supermethods that might be accessible. We can toss
+	 * this when we're done searching.
+	 */
+	Map sigs = new HashMap();
+
+	while (cls != null) {
+	    boolean done = getPublicMethods(cls, m, sigs);
+	    if (done) {
+		break;
+	    }
+	    getJScriptInterfaceMethods(cls, m, sigs);
+	    cls = cls.getSuperclass();
+	}
+	return (Method[]) m.toArray(new Method[m.size()]);
+    }
+
+    /*
+     * Process the immediate interfaces of this class or interface.
+     */
+    private static void getJScriptInterfaceMethods(Class cls, List m, Map sigs) {
+	Class[] intfs = cls.getInterfaces();
+	for (int i=0; i < intfs.length; i++) {
+	    Class intf = intfs[i];
+	    boolean done = getPublicMethods(intf, m, sigs);
+	    if (!done) {
+	        getJScriptInterfaceMethods(intf, m, sigs);
+	    }
+	}
+    }
+
+    /*
+     *
+     * Process the methods in this class or interface
+     */
+    private static boolean getPublicMethods(Class cls, List m, Map sigs) {
+	Method[] methods = null;
+	try {
+
+	    /*
+	     * This class or interface is non-public so we
+	     * can't use any of it's methods. Go back and
+	     * try again with a superclass or superinterface.
+	     */
+	    if (!Modifier.isPublic(cls.getModifiers())) {
+		return false;
+	    }
+
+	    if (!JSClassLoader.isPackageAccessible(cls)) {
+		return false;
+	    }
+
+	    methods = cls.getMethods();
+	} catch (SecurityException se) {
+	    return false;
+        }
+
+	/*
+	 * Check for inherited methods with non-public
+	 * declaring classes. They might override and hide
+	 * methods from their superclasses or
+	 * superinterfaces.
+	 */
+	boolean done = true;
+	for (int i=0; i < methods.length; i++) {
+	    Class dc = methods[i].getDeclaringClass();
+	    if (!Modifier.isPublic(dc.getModifiers())) {
+		done = false;
+		break;
+	    }
+	}
+
+	/*
+	 * Belatedly initialize the signature map if
+	 * this is not the first time here.
+	 */
+	if (sigs.isEmpty() && !m.isEmpty()) {
+	    initSignatureMap(m, sigs);
+	}
+
+	if (done) {
+	    /*
+	     * We're done. Spray all the methods into
+	     * the list and then we're out of here.
+	     */
+	    for (int i=0; i < methods.length; i++) {
+		addMethod(m, sigs, methods[i]);
+	    }
+	} else {
+	    /*
+	     * Simulate cls.getDeclaredMethods() by
+	     * stripping away inherited methods.
+	     */
+	    for (int i=0; i < methods.length; i++) {
+		Class dc = methods[i].getDeclaringClass();
+		if (cls.equals(dc)) {
+		    addMethod(m, sigs, methods[i]);
+		}
+	    }
+	}
+	return done;
+    }
+
+    private static void initSignatureMap(List m, Map sigs) {
+	Iterator i = m.iterator();
+	while (i.hasNext()) {
+	    Method entry = (Method) i.next();
+	    sigs.put(getSignature(entry), entry);
+	}
+    }
+
+    private static void addMethod(List m, Map sigs, Method method) {
+	/*
+	 * Avoid work. We ignore the signature matching
+	 * until the map is initialized in initSignatureMap.
+ 	 * This has the effect of avoiding the signature
+	 * work for the first call of getPublicMethods().
+	 */
+	if (sigs.isEmpty()) {
+	    m.add(method);
+	    return;
+	}
+
+	/*
+	 * Avoid adding duplicate accessible methods on
+	 * the list.
+	 */
+	String signature = getSignature(method);
+	if (!sigs.containsKey(signature)) {
+	    m.add(method);
+	    sigs.put(signature, method);
+	}
+    }
+
+    /*
+     * Return a canonical method signature for the method.
+     * We care only about the simple method name and the
+     * the number, type and order of the parameters.
+     * Exception declarations are not part of a method
+     * signature nor is the return type.
+     */
+    private static String getSignature(Method method) {
+	StringBuffer sb = new StringBuffer();
+
+	sb.append(method.getName());
+	Class[] params = method.getParameterTypes();
+	sb.append('(');
+	if (params.length > 0) {
+	    sb.append(params[0].getName());
+	}
+	for (int i=1; i < params.length; i++) {
+	    sb.append(',');
+	    sb.append(params[i].getName());
+	}
+        sb.append(')');
+	
+	return sb.toString();
+    }
+
+    /*
+     * Discover the public fields on public classes
+     * and interfaces accessible to the calling
+     * JavaScript code. 
+     */
+     public static Field[] getJScriptFields(Class cls) {
+	List m = new ArrayList(); /* the valid fields we find */
+
+	/*
+	 * Temporary map of field name when we decide
+	 * that a simple call to target.getFields() returns
+	 * inaccessible fields and we must search for alternative
+	 * supermethods that might be accessible. We can toss
+	 * this when we're done searching.
+	 */
+	Map names = new HashMap();
+
+	while (cls != null) {
+	    boolean done = getPublicFields(cls, m, names);
+	    if (done) {
+		break;
+	    }
+	    getJScriptInterfaceFields(cls, m, names);
+	    cls = cls.getSuperclass();
+	}
+	return (Field[]) m.toArray(new Field[m.size()]);
+    }
+
+    /*
+     * Process the immediate interfaces of this class or interface.
+     */
+    private static void getJScriptInterfaceFields(Class cls, List m, Map names) {
+	Class[] intfs = cls.getInterfaces();
+	for (int i=0; i < intfs.length; i++) {
+	    Class intf = intfs[i];
+	    boolean done = getPublicFields(intf, m, names);
+	    if (!done) {
+	        getJScriptInterfaceFields(intf, m, names);
+	    }
+	}
+    }
+
+    /*
+     *
+     * Process the fields in this class or interface
+     */
+    private static boolean getPublicFields(Class cls, List m, Map names) {
+	Field[] fields = null;
+	try {
+
+	    /*
+	     * This class or interface is non-public so we
+	     * can't use any of it's fields. Go back and
+	     * try again with a superclass or superinterface.
+	     */
+	    if (!Modifier.isPublic(cls.getModifiers())) {
+		return false;
+	    }
+
+	    if (!JSClassLoader.isPackageAccessible(cls)) {
+		return false;
+	    }
+	    fields = cls.getFields();
+	} catch (SecurityException se) {
+	    return false;
+        }
+
+	/*
+	 * Check for inherited fields with non-public
+	 * declaring classes. They might hide
+	 * fields from public classes or interfaces.
+	 */
+	boolean done = true;
+	for (int i=0; i < fields.length; i++) {
+	    Class dc = fields[i].getDeclaringClass();
+	    if (!Modifier.isPublic(dc.getModifiers())) {
+		done = false;
+		break;
+	    }
+	}
+	if (done) {
+	    /*
+	     * We're done. Spray all the fields into
+	     * the list and then we're out of here.
+	     */
+	    for (int i=0; i < fields.length; i++) {
+		addField(m, names, fields[i]);
+	    }
+	} else {
+	    /*
+	     * Simulate cls.getDeclaredFields() by
+	     * stripping away inherited fields.
+	     */
+	    for (int i=0; i < fields.length; i++) {
+		Class dc = fields[i].getDeclaringClass();
+		if (cls.equals(dc)) {
+		    addField(m, names, fields[i]);
+		}
+	    }
+	}
+	return done;
+    }
+
+    private static void addField(List m, Map names, Field field) {
+	/*
+	 * Avoid adding duplicate accessible fields on
+	 * the list.
+	 */
+	String name = field.getName();
+	if (!names.containsKey(name)) {
+	    m.add(field);
+	    names.put(name, field);
+	}
+    }
+}
+
+
