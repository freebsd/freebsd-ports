$FreeBSD$

--- ../../deploy/src/plugin/src/share/classes/sun/plugin/javascript/JSClassLoader.java	1 Jan 1970 00:00:00 -0000
+++ ../../deploy/src/plugin/src/share/classes/sun/plugin/javascript/JSClassLoader.java	3 Dec 2004 03:56:58 -0000	1.1
@@ -0,0 +1,238 @@
+/*
+ * @(#)JSClassLoader.java	1.1 04/06/20
+ *
+ * Copyright 2004 Sun Microsystems, Inc. All rights reserved.
+ * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
+ */
+
+package sun.plugin.javascript;
+
+import java.security.AllPermission;
+import java.security.AccessController;
+import java.security.PermissionCollection;
+import java.security.SecureClassLoader;
+import java.security.PrivilegedExceptionAction;
+import java.security.CodeSource;
+import java.io.InputStream;
+import java.io.BufferedInputStream;
+import java.io.IOException;
+import java.net.URL;
+import java.net.URLConnection;
+import java.net.HttpURLConnection;
+import java.lang.reflect.Method;
+import java.lang.reflect.InvocationTargetException;
+import java.lang.reflect.AccessibleObject;
+import sun.net.www.ParseUtil;
+import sun.security.util.SecurityConstants;
+
+/*
+ * Create a trampoline class for JavaScript to Java
+ * method invocations.
+ * 
+ */
+public final class JSClassLoader extends SecureClassLoader {
+    private static String JS_PROXY_PKG = "sun.plugin.javascript.invoke.";
+    private static String TRAMPOLINE = JS_PROXY_PKG + "JSInvoke";
+    private static Method bounce; 
+
+    /*
+     * Bounce through the trampoline.
+     */
+    public static Object invoke(Method m, Object obj, Object[] params)
+	throws Exception {
+	try {
+	    return bounce().invoke(null, new Object[] {m, obj, params});
+	} catch (InvocationTargetException ie) {
+	    Throwable t = ie.getCause();
+
+	    if (t instanceof InvocationTargetException) {
+		throw (InvocationTargetException)t;
+	    } else {
+		throw ie;
+	    }
+	}
+    }
+
+    /**
+     * Check the package access permission by giving a class
+     * 
+     * @param clazz: The Class object trying to get access to
+     *
+     */
+    public static void checkPackageAccess(Class clazz) {
+	String clsname = clazz.getName();
+	int index = clsname.lastIndexOf(".");
+	if (index != -1) {
+	    String pkgname = clsname.substring(0, index);
+	    SecurityManager s = System.getSecurityManager();
+	    if (s != null) {
+		s.checkPackageAccess(pkgname);
+	    }
+	}
+    }
+
+    public static boolean isPackageAccessible(Class clazz) {
+	try {
+	    checkPackageAccess(clazz);
+	} catch (SecurityException e) {
+	    return false;
+	}
+	return true;
+    }
+
+
+    private synchronized static Method bounce() throws Exception {
+	if (bounce == null) {
+	    bounce = (Method) AccessController.doPrivileged(new PrivilegedExceptionAction() {
+		public Object run() throws Exception {
+	    	    Class[] types;
+	    	    Class t = getTrampoline();
+		    Method b;
+
+	    	    types = new Class[] {Method.class, Object.class, Object[].class};
+	            b = t.getDeclaredMethod("invoke", types);
+	    	    ((AccessibleObject)b).setAccessible(true);
+		    return b;
+		}
+	    });
+	}
+	return bounce;
+    }
+
+    private static Class getTrampoline() {
+        try {
+	    return Class.forName(TRAMPOLINE, true, new JSClassLoader());
+	} catch (ClassNotFoundException e) {
+	}
+	return null;
+    }
+
+
+    protected synchronized Class loadClass(String name, boolean resolve)
+	throws ClassNotFoundException
+    {
+	SecurityManager s = System.getSecurityManager();
+	if (s != null) {
+	    String cname = name.replace('/', '.');
+	    if (cname.startsWith("[")) {
+		int b = cname.lastIndexOf('[') + 2;
+		if (b > 1 && b < cname.length()) {
+		    cname = cname.substring(b);
+		}
+	    }
+	    int i = cname.lastIndexOf('.');
+	    if (i != -1) {
+		s.checkPackageAccess(cname.substring(0, i));
+	    }
+	}
+	// First, check if the class has already been loaded
+	Class c = findLoadedClass(name);
+	if (c == null) {
+	    try {
+	        c = findClass(name);
+	    } catch (ClassNotFoundException e) {
+		// Fall through ...
+	    }
+	    if (c == null) {
+		c = getParent().loadClass(name);
+	    }
+	}
+	if (resolve) {
+	    resolveClass(c);
+	}
+	return c;
+    }
+
+
+    protected Class findClass(final String name)
+	throws ClassNotFoundException
+    {
+	if (!name.startsWith(JS_PROXY_PKG)) {
+	    throw new ClassNotFoundException(name);
+	}
+	String path = name.replace('.', '/').concat(".class");
+	URL res = getResource(path);
+	if (res != null) {
+	    try {
+		return defineClass(name, res);
+	    } catch (IOException e) {
+		throw new ClassNotFoundException(name, e);
+	    }
+	} else {
+	    throw new ClassNotFoundException(name);
+	}
+    }
+
+
+    /*
+     * Define the JavaScript proxy classes
+     */
+    private Class defineClass(String name, URL url) throws IOException {
+	byte[] b = getBytes(url);
+	CodeSource cs = new CodeSource(null, (java.security.cert.Certificate[])null);
+	if (!name.equals(TRAMPOLINE)) {
+	    throw new IOException("JSClassLoader: bad name " + name);
+	}
+	return defineClass(name, b, 0, b.length, cs);
+    }
+
+
+    /*
+     * Returns the contents of the specified URL as an array of bytes.
+     */
+    private static byte[] getBytes(URL url) throws IOException {
+	URLConnection uc = url.openConnection();
+        if (uc instanceof java.net.HttpURLConnection) {
+            java.net.HttpURLConnection huc = (java.net.HttpURLConnection) uc;
+            int code = huc.getResponseCode();
+            if (code >= java.net.HttpURLConnection.HTTP_BAD_REQUEST) {
+                throw new IOException("open HTTP connection failed.");
+            }
+        }
+        int len = uc.getContentLength();
+        InputStream in = new BufferedInputStream(uc.getInputStream());
+	
+        byte[] b;
+        try {
+            if (len != -1) {
+                // Read exactly len bytes from the input stream
+                b = new byte[len];
+                while (len > 0) {
+                    int n = in.read(b, b.length - len, len);
+                    if (n == -1) {
+                        throw new IOException("unexpected EOF");
+                    }
+                    len -= n;
+                }
+            } else {
+                b = new byte[8192];
+                int total = 0;
+                while ((len = in.read(b, total, b.length - total)) != -1) {
+                    total += len;
+                    if (total >= b.length) {
+                        byte[] tmp = new byte[total * 2];
+                        System.arraycopy(b, 0, tmp, 0, total);
+                        b = tmp;
+                    }
+                }
+                // Trim array to correct size, if necessary
+                if (total != b.length) {
+                    byte[] tmp = new byte[total];
+                    System.arraycopy(b, 0, tmp, 0, total);
+                    b = tmp;
+                }
+            }
+        } finally {
+            in.close();
+        }
+        return b;
+    }
+
+
+    protected PermissionCollection getPermissions(CodeSource codesource)
+    {
+	PermissionCollection perms = super.getPermissions(codesource);
+	perms.add(new AllPermission());
+	return perms;
+    }
+}
