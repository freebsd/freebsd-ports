$FreeBSD$

--- ../../deploy/src/plugin/src/share/classes/sun/plugin/com/DispatchImpl.java	22 Oct 2003 23:04:20 -0000	1.1
+++ ../../deploy/src/plugin/src/share/classes/sun/plugin/com/DispatchImpl.java	3 Dec 2004 03:56:58 -0000	1.2
@@ -1,7 +1,7 @@
 /*
- * @(#)DispatchImpl.java	1.6 03/01/23
+ * @(#)DispatchImpl.java	1.16 04/06/20
  *
- * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
+ * Copyright 2004 Sun Microsystems, Inc. All rights reserved.
  * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
  */
 
@@ -9,8 +9,32 @@
 
 import sun.plugin.util.Trace;
 import sun.plugin.javascript.ocx.JSObject;
-import java.applet.Applet;
+import sun.plugin.liveconnect.JavaScriptProtectionDomain;
 import sun.plugin.viewer.context.IExplorerAppletContext;
+import sun.plugin.security.PluginClassLoader;
+import java.applet.Applet;
+import java.net.URL;
+import java.net.MalformedURLException;
+import java.net.InetAddress;
+import java.net.UnknownHostException;
+import java.net.SocketPermission;
+import java.io.FilePermission;
+import java.io.File;
+import java.security.AccessControlContext;
+import java.security.AccessController;
+import java.security.CodeSource;
+import java.security.Policy;
+import java.security.ProtectionDomain;
+import java.security.AllPermission;
+import java.security.Permissions;
+import java.security.Permission;
+import java.security.PermissionCollection;
+import java.security.PrivilegedAction;
+import java.security.PrivilegedExceptionAction;
+import java.security.AccessControlException;
+import java.security.PrivilegedActionException;
+import sun.net.www.ParseUtil;
+import sun.security.util.SecurityConstants;
 
 /**
  *  DispatchImpl encapsulates a Java Object and provides Dispatch interface
@@ -22,14 +46,19 @@
 {
     JavaClass targetClass = null;
     Object targetObj = null;
+    int handle = 0;
+    int wndHandle = 0;
+    AccessControlContext context = null;
+    boolean isBridge = false;
 
     /*
      * Constructor
      * @param obj the object to be wrapped
      */
-    public DispatchImpl(Object obj)
+    public DispatchImpl(Object obj, int id)
     {
 	targetObj = obj;
+	handle = id;
     }
 
     /**
@@ -40,19 +69,87 @@
      * @param params Arguments.
      * @return Java object.
      */
-    public Object invoke(int flag, int index, Object []params)
+    public Object invoke(final int flag, final int index, final Object []params)
+        throws  Exception
+    {
+	try {
+	    //No security constraints in case of ActiveX bridge application
+	    if(isBridge)
+		return invokeImpl(flag, index, params);
+
+	    if(context == null) {
+		context = createContext();
+	    }
+
+	    // Invoke the method within the applet sand box security restricitions
+	    return AccessController.doPrivileged(
+		new PrivilegedExceptionAction() {
+		    public Object run() throws Exception{
+			return invokeImpl(flag, index, params);
+		    }
+		}, context	
+	    );
+	}catch(Exception exc) {
+	    Throwable cause = exc.getCause();
+	    if(cause == null) {
+		cause = exc;
+	    }
+
+       	    Trace.liveConnectPrintException(cause);
+	    throw new Exception(cause.toString());
+	}
+    }
+
+    public AccessControlContext createContext() {
+    	try {
+	    ProtectionDomain[] domains = new ProtectionDomain[1];
+	    //Obtain the java code origin
+	    ProtectionDomain pd = (ProtectionDomain)AccessController.doPrivileged(new PrivilegedAction() {
+		public Object run() {
+		    return targetObj.getClass().getProtectionDomain();
+		}
+	    });
+
+	    CodeSource cs = null;
+	    URL url = null;
+	    if(pd != null)
+		cs = pd.getCodeSource();
+	    if(cs != null)
+		url = cs.getLocation();
+
+	    domains[0] = getJSProtectionDomain(url, targetObj.getClass());
+	    return new AccessControlContext(domains);
+	}catch(Exception exc) {
+       	    Trace.liveConnectPrintException(exc);
+	}
+	
+	return null;    
+    }
+
+    /**
+     * Invoke a method according to the method index.
+     *
+     * @param flag Invoke flag
+     * @param index Method index
+     * @param params Arguments.
+     * @return Java object.
+     */
+    public Object invokeImpl(int flag, int index, Object []params)
         throws  Exception
     {
 	Object retObj = null;
 	Dispatcher disp = null;
 	try {
-	    convertParams(params);
+	    if(params != null)
+		convertParams(params);
 	    disp = targetClass.getDispatcher(flag, index, params);
-	    return disp.invoke(targetObj, params);
-        }
-        catch (Throwable e)
-        {
-	    //e.printStackTrace();
+	    if(disp != null) {
+		retObj = disp.invoke(targetObj, params);
+		if(retObj != null)
+		    retObj = Utils.convertReturn(disp.getReturnType(), retObj, handle);
+	    }
+	    return retObj;		
+        } catch (Throwable e) {
 	    Throwable cause = e.getCause();
 	    if(cause == null) {
 		cause = e;
@@ -82,11 +179,39 @@
 	return targetClass;
     }
 
+    public int getReturnType(int id){
+	return targetClass.getReturnType(id);
+    }
+
+    public int getIdForName(final String name) throws Exception{
+	try {
+	    //No security constraints in case of ActiveX bridge application
+	    if(isBridge)
+		return getIdForNameImpl(name);
+
+	    if(context == null) {
+		context = createContext();
+	    }
+
+	    // Invoke the method within the applet sand box security restricitions
+	    Integer retVal = (Integer)AccessController.doPrivileged(
+		new PrivilegedExceptionAction() {
+		    public Object run() throws Exception{
+			return new Integer(getIdForNameImpl(name));
+		    }
+		}, context	
+	    );
+	    return retVal.intValue();
+	}catch(PrivilegedActionException pe) {
+	}
+
+	return -1;
+    }
 
     /*
      *
      */
-    public int getIdForName(String name) throws Exception{
+    public int getIdForNameImpl(String name) throws Exception{
 	int id = -1;
 
 	if(targetClass == null && targetObj != null) {
@@ -103,27 +228,122 @@
     }
 
     /*
-     *
+     * Unwraps the wrapped java object arguments
      */
     private void convertParams(Object []params) {
 	for(int i=0;i<params.length;i++) {
 	    if(params[i] != null && params[i] instanceof DispatchImpl) {
 		params[i] = ((DispatchImpl)params[i]).getWrappedObject();
 	    } else if(params[i] != null && params[i] instanceof DispatchClient){
-		JSObject jsObj = new JSObject((DispatchClient)params[i]);
-		jsObj.setIExplorerAppletContext((IExplorerAppletContext)
+		JSObject jsObj = null;
+		if (!isBridge) {
+		    jsObj = new JSObject((DispatchClient)params[i]);
+		    jsObj.setIExplorerAppletContext((IExplorerAppletContext)
 				((Applet)targetObj).getAppletContext());
+		} else {
+		    jsObj = new JSObject((DispatchClient)params[i], handle);
+		}		    
 		params[i] = jsObj;
 	    }
 	}
     }
 
+    /**
+     * Returns a protection domain that represents the default permission
+     * for a given URL.
+     *
+     * @param urlString URL
+     * @return protection domain.
+     */
+    public static ProtectionDomain getJSProtectionDomain(URL url, Class clazz)
+	throws MalformedURLException {
+	
+	// Obtain default java applet policy
+	Policy policy = (Policy)AccessController.doPrivileged(new PrivilegedAction() {
+	    public Object run() {
+		return Policy.getPolicy();
+	    }
+	});
+
+	CodeSource cs = new CodeSource(null, (java.security.cert.Certificate[])null);
+	final PermissionCollection pc = policy.getPermissions(cs);
+	if(url != null) {
+	    Permission p;
+	    String path = null;
+	    try {
+		p = url.openConnection().getPermission();
+	    } catch (java.io.IOException ioe) {
+		p = null;
+	    }
+
+	    if (p instanceof FilePermission) {
+		path = p.getName();
+	    } else if ((p == null) && (url.getProtocol().equals("file"))) {
+		path = url.getFile().replace('/', File.separatorChar);
+		path = ParseUtil.decode(path);
+	    } else if (p instanceof SocketPermission) {
+		/* 
+		Socket permission to connect back to the host
+		*/
+		String host = url.getHost();
+		pc.add(new SocketPermission(host,  
+		    SecurityConstants.SOCKET_CONNECT_ACCEPT_ACTION));
+	    }
+
+	    if(path != null &&
+		(clazz.getClassLoader() instanceof PluginClassLoader)) {
+		//We need to add an additional permission to read recursively
+		if (path.endsWith(File.separator)) {
+		    path += "-";
+		} else {
+		    int endIndex = path.lastIndexOf(File.separatorChar);
+		    if (endIndex != -1)
+			path = path.substring(0, endIndex+1) + "-";
+		}
+
+		pc.add(new FilePermission(path, SecurityConstants.FILE_READ_ACTION));
+
+		/* 
+		Socket permission to connect back to the "localhost"
+		*/
+		pc.add(new SocketPermission("localhost", 
+		    SecurityConstants.SOCKET_CONNECT_ACCEPT_ACTION));
+		AccessController.doPrivileged(new PrivilegedAction() {
+		    public Object run() {
+			try {
+			    String host = InetAddress.getLocalHost().getHostName();
+			    pc.add(new SocketPermission(host, 
+				SecurityConstants.SOCKET_CONNECT_ACCEPT_ACTION));
+			} catch (UnknownHostException uhe) {
+			}
+			return null;
+		    }
+		});
+	    }
+	}
+
+	return new JavaScriptProtectionDomain(pc);
+    }
+
     public String toString() {
 	if(targetObj != null) {
 	    return targetObj.toString();
 	}
 	return null;
     }
+
+    public int getWindowHandle() {
+	if(wndHandle == 0) {
+	    wndHandle = getWindowHandle(handle);
+	}
+	return wndHandle;
+    }
+
+    protected void setBridge() {
+	isBridge = true;
+    }
+
+    native int getWindowHandle(int id);
 }
 
 
