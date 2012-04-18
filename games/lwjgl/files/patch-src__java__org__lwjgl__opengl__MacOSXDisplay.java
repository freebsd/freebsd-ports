Obtained from http://foo.poildetroll.net/minecraft/lwjgl-2.7.1-freebsd.diff


--- ./src/java/org/lwjgl/opengl/MacOSXDisplay.java.orig	2011-02-06 19:23:26.000000000 +0000
+++ ./src/java/org/lwjgl/opengl/MacOSXDisplay.java	2012-03-26 18:14:03.153375501 +0000
@@ -54,9 +54,9 @@
 import org.lwjgl.LWJGLException;
 import org.lwjgl.LWJGLUtil;
 
-import com.apple.eawt.Application;
-import com.apple.eawt.ApplicationAdapter;
-import com.apple.eawt.ApplicationEvent;
+// import com.apple.eawt.Application;
+// import com.apple.eawt.ApplicationAdapter;
+// import com.apple.eawt.ApplicationEvent;
 
 import static org.lwjgl.opengl.GL11.*;
 
@@ -79,11 +79,11 @@
 		try {
 			AccessController.doPrivileged(new PrivilegedExceptionAction<Object>() {
 				public Object run() throws Exception {
-					Application.getApplication().addApplicationListener(new ApplicationAdapter() {
+/*					Application.getApplication().addApplicationListener(new ApplicationAdapter() {
 						public void handleQuit(ApplicationEvent event) {
 							doHandleQuit();
 						}
-					});
+					}); */
 					return null;
 				}
 			});
