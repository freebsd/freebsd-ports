$FreeBSD$

--- ../../deploy/src/plugin/src/share/classes/sun/plugin/liveconnect/SecureInvocation.java	22 Oct 2003 23:04:21 -0000	1.1
+++ ../../deploy/src/plugin/src/share/classes/sun/plugin/liveconnect/SecureInvocation.java	3 Dec 2004 03:56:58 -0000	1.2
@@ -1,7 +1,7 @@
 /*
  * @(#)SecureInvocation.java	1.21 02/08/20
  *
- * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
+ * Copyright 2004 Sun Microsystems, Inc. All rights reserved.
  * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
  */
 
@@ -9,7 +9,8 @@
 
 import java.lang.reflect.Constructor;
 import java.lang.reflect.Field;
-import java.lang.reflect.Method;
+import java.lang.reflect.Method;
+import java.lang.reflect.Modifier;
 import java.lang.Thread;
 import java.io.FilePermission;
 import java.security.AccessControlContext;
@@ -29,7 +30,10 @@
 import java.net.URL;
 import java.net.MalformedURLException;
 import sun.plugin.util.Trace;
-import sun.plugin.services.PlatformService;
+import sun.plugin.services.PlatformService;
+import sun.plugin.javascript.JSClassLoader;
+import sun.plugin.javascript.ReflectUtil;
+
 
 /**
  * <P> SecureInvocation is for implementating nsISecureJNI which allows 
@@ -98,64 +102,64 @@
 	    throw e;
 	}
     }
-
-    static class CallMethodThread extends Thread {
-	public CallMethodThread(int handle, Class clazz, Object obj, Method method, Object[] args,
-		  		    String origin, boolean isUniversalBrowserRead,
-				    boolean isUniversalJavaPermission) {
-	    this.handle = handle;
-	    this.clazz = clazz;
-	    this.obj = obj;
-	    this.method = method;
-	    this.args = args;
-	    this.origin = origin;
-	    this.isUniversalBrowserRead = isUniversalBrowserRead;
-	    this.isUniversalJavaPermission = isUniversalJavaPermission;
-	}
-
-	public void run() {
-	    try {
-		result = CallMethod(clazz, obj, method, args, origin, isUniversalBrowserRead, isUniversalJavaPermission);
-	    }
-	    catch(Exception e) {
-		exception = e;
-	    }
-	    finally {
-		PlatformService.getService().signalEvent(handle);
-	    }
-	}
-
-
-	public Object getResult() throws Exception {
-	    if(exception != null)
-		throw exception;
-	    return result;
-	}
-
-	private Exception   exception = null;
-	private Object	    result = null;
-
-	private int	    handle;
-	private Class	    clazz;
-	private Object	    obj;
-	private Method	    method;
-	private Object[]    args;
-	private String	    origin;
-	private boolean	    isUniversalBrowserRead;
-	private boolean	    isUniversalJavaPermission;
-
-    }
-
-    public static Object CallMethod(final int handle, final Class clazz, final Object obj, final Method method, final Object[] args, 
-		  		    final String origin, final boolean isUniversalBrowserRead,
-				    final boolean isUniversalJavaPermission) 
-    throws Exception {
-	CallMethodThread callThread = new CallMethodThread(handle, clazz, obj, method, args, origin, isUniversalBrowserRead, isUniversalJavaPermission);	
-	callThread.start();
-	PlatformService.getService().waitEvent(handle);
-	return callThread.getResult();
-    }
-
+
+    static class CallMethodThread extends Thread {
+	public CallMethodThread(int handle, Class clazz, Object obj, Method method, Object[] args,
+		  		    String origin, boolean isUniversalBrowserRead,
+				    boolean isUniversalJavaPermission) {
+	    this.handle = handle;
+	    this.clazz = clazz;
+	    this.obj = obj;
+	    this.method = method;
+	    this.args = args;
+	    this.origin = origin;
+	    this.isUniversalBrowserRead = isUniversalBrowserRead;
+	    this.isUniversalJavaPermission = isUniversalJavaPermission;
+	}
+
+	public void run() {
+	    try {
+		result = CallMethod(clazz, obj, method, args, origin, isUniversalBrowserRead, isUniversalJavaPermission);
+	    }
+	    catch(Exception e) {
+		exception = e;
+	    }
+	    finally {
+		PlatformService.getService().signalEvent(handle);
+	    }
+	}
+
+
+	public Object getResult() throws Exception {
+	    if(exception != null)
+		throw exception;
+	    return result;
+	}
+
+	private Exception   exception = null;
+	private Object	    result = null;
+
+	private int	    handle;
+	private Class	    clazz;
+	private Object	    obj;
+	private Method	    method;
+	private Object[]    args;
+	private String	    origin;
+	private boolean	    isUniversalBrowserRead;
+	private boolean	    isUniversalJavaPermission;
+
+    }
+
+    public static Object CallMethod(final int handle, final Class clazz, final Object obj, final Method method, final Object[] args, 
+		  		    final String origin, final boolean isUniversalBrowserRead,
+				    final boolean isUniversalJavaPermission) 
+    throws Exception {
+	CallMethodThread callThread = new CallMethodThread(handle, clazz, obj, method, args, origin, isUniversalBrowserRead, isUniversalJavaPermission);	
+	callThread.start();
+	PlatformService.getService().waitEvent(handle);
+	return callThread.getResult();
+    }
+
 
     /**
      * <P> Call a method on Java object with security context.
@@ -197,8 +201,8 @@
 			AccessControlContext context = new AccessControlContext(domains);
 
 			// Perform the method invocation.
-			return AccessController.doPrivileged(new PrivilegedCallMethodAction(method, obj, args),
-							     context);
+			return AccessController.doPrivileged(new PrivilegedCallMethodAction(method, 
+					    obj, args), context);
 		    } catch (Exception e) {
 			Trace.liveConnectPrintException(e);
 			throw e;
@@ -323,32 +327,6 @@
 	}
     }
 
-
-    /**
-     * <P> Set up a protection domain according to the origin and
-     * the other security related information.
-     */
-    private static ProtectionDomain getProtectionDomain(Class clazz, 
-							String origin, 
-							boolean byPassOrigin, 
-							boolean allPermission)
-				    throws OriginNotAllowedException, MalformedURLException
-    {
-	boolean trust = false;
-
-	// First, check if the call is allowed
-	checkLiveConnectCaller(clazz, origin, byPassOrigin);
-
-	if (allPermission)
-	{
-	    return getTrustedProtectionDomain();
-	}
-	else
-	{
-	    return getDefaultProtectionDomain(origin);
-	}
-    }
-
     /**
      * <P> Check if LiveConnect call is allowed at all.
      * </P>
@@ -447,7 +425,7 @@
 
 	// Obtain Java policy
 	Policy policy = Policy.getPolicy();
-	CodeSource cs = new CodeSource(url, null);
+	CodeSource cs = new CodeSource(url, (java.security.cert.Certificate[])null);
 	final PermissionCollection pc = policy.getPermissions(cs);
 
 	if (url == null || url.getProtocol().equals("file")) {
@@ -516,16 +494,19 @@
 
     PrivilegedConstructObjectAction(Constructor constructor, Object[] args)
     {
-	this.constructor = constructor;
-	this.args = args;
+		this.constructor = constructor;
+		this.args = args;
 
-	// Ensure the argument is not null
-	if (this.args == null)
-	    this.args = new Object[0];
+		// Ensure the argument is not null
+		if (this.args == null)
+			this.args = new Object[0];
     }
 
     public Object run() throws Exception {
-	return constructor.newInstance(args);
+		/* Check whether the caller has package access permission */
+		JSClassLoader.checkPackageAccess(constructor.getDeclaringClass());
+
+		return constructor.newInstance(args);
     }
 }
 
@@ -543,17 +524,54 @@
 
     PrivilegedCallMethodAction(Method method, Object obj, Object[] args)
     {
-	this.method = method;
-	this.obj = obj;
-	this.args = args;
-
-	// Ensure the argument is not null
-	if (this.args == null)
-	    this.args = new Object[0];
+		this.method = method;
+	
+		this.obj = obj;
+		this.args = args;
+
+		// Ensure the argument is not null
+		if (this.args == null)
+			this.args = new Object[0];
     }
 
     public Object run() throws Exception {
-	return method.invoke(obj, args);
+	/*
+	 *  Browser uses reflection to collect methods/fields/constructors 
+	 *  through this method call. Therefore JSClassLoader is not used
+	 *  in such cases. However it requires filtering to avoid exposing
+	 *  inaccessible methods/fields/constructors. 
+	 *
+	 *  Also, Mozilla ignores abstract methods, therefore those are 
+	 *  replaced by the concrete class methods
+	 */
+	if(obj instanceof Class) {
+	    String name = method.getName();
+	    Class cls = (Class)obj;
+	    if(name.equals("getMethods")) {
+		Method[] methods = ReflectUtil.getJScriptMethods(cls);
+		for (int i=0; i < methods.length; i++) {
+		    Method m = methods[i];
+		    if (Modifier.isAbstract(m.getModifiers())) {
+			Class[] params = m.getParameterTypes();
+			methods[i] = cls.getMethod(m.getName(), params);
+		    }
+		}
+		return methods; 
+	    }else if (name.equals("getFields")) {
+		return ReflectUtil.getJScriptFields(cls);		
+	    }else if (name.equals("getConstructors")) {
+		if (!Modifier.isPublic(cls.getModifiers()) ||
+		    !JSClassLoader.isPackageAccessible(cls)) {
+		    return new Constructor[0];
+		}
+	    }
+	}
+
+	Method actualMethod = ReplaceMethod.getJScriptMethod(method);
+	if(actualMethod != null)
+	    return JSClassLoader.invoke(actualMethod, obj, args);
+	else
+	    throw new NoSuchMethodException(method.getName());
     }
 }
 
@@ -564,18 +582,20 @@
  * </P>
  */
 class PrivilegedGetFieldAction implements PrivilegedExceptionAction {
-
     Field field;
     Object obj;
 
     PrivilegedGetFieldAction(Field field, Object obj)
     {
-	this.field = field;
-	this.obj = obj;
+		this.field = field;
+		this.obj = obj;
     }
 
-    public Object run() throws Exception {
-	return field.get(obj);
+    public Object run() throws Exception {	
+		/* Check whether the caller has package access permission */
+		JSClassLoader.checkPackageAccess(field.getDeclaringClass());
+
+		return field.get(obj);
     }
 }
 
@@ -593,15 +613,18 @@
 
     PrivilegedSetFieldAction(Field field, Object obj, Object val)
     {
-	this.field = field;
-	this.obj = obj;
-	this.val = val;
+		this.field = field;
+		this.obj = obj;
+		this.val = val;
     }
 
     public Object run() throws Exception {
-	field.set(obj, val);
+		/* Check whether the caller has package access permission */
+		JSClassLoader.checkPackageAccess(field.getDeclaringClass());
+	
+		field.set(obj, val);
     	return null;
     }
 }
-
-
+
+
