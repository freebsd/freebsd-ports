--- plugins/org.eclipse.core.runtime/src/org/eclipse/core/internal/runtime/InternalPlatform.java.orig	2008-08-02 14:56:13.000000000 -0400
+++ plugins/org.eclipse.core.runtime/src/org/eclipse/core/internal/runtime/InternalPlatform.java	2008-08-02 14:56:49.000000000 -0400
@@ -61,7 +61,7 @@
 	//XXX This is not synchronized
 	private static Map logs = new HashMap(5);
 
-	private static final String[] OS_LIST = {Platform.OS_AIX, Platform.OS_HPUX, Platform.OS_LINUX, Platform.OS_MACOSX, Platform.OS_QNX, Platform.OS_SOLARIS, Platform.OS_WIN32};
+	private static final String[] OS_LIST = {Platform.OS_AIX, Platform.OS_HPUX, Platform.OS_LINUX, Platform.OS_FREEBSD, Platform.OS_MACOSX, Platform.OS_QNX, Platform.OS_SOLARIS, Platform.OS_WIN32};
 	private static String password = ""; //$NON-NLS-1$
 	private static final String PASSWORD = "-password"; //$NON-NLS-1$
 	private static PlatformLogWriter platformLog = null;
