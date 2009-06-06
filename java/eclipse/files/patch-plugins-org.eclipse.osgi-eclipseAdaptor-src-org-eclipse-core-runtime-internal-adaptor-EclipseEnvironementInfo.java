--- plugins/org.eclipse.osgi/eclipseAdaptor/src/org/eclipse/core/runtime/internal/adaptor/EclipseEnvironmentInfo.java.orig	2009-02-15 19:25:53.501501141 -0500
+++ plugins/org.eclipse.osgi/eclipseAdaptor/src/org/eclipse/core/runtime/internal/adaptor/EclipseEnvironmentInfo.java	2009-02-15 20:52:03.177887665 -0500
@@ -33,6 +33,7 @@
 	// this internally to be Solaris.
 	private static final String INTERNAL_OS_SUNOS = "SunOS"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_LINUX = "Linux"; //$NON-NLS-1$
+	private static final String INTERNAL_OS_FREEBSD = "FreeBSD"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_MACOSX = "Mac OS"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_AIX = "AIX"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_HPUX = "HP-UX"; //$NON-NLS-1$
@@ -189,6 +190,8 @@
 			return Constants.WS_WIN32;
 		if (os.equals(Constants.OS_LINUX))
 			return Constants.WS_GTK;
+		if (os.equals(Constants.OS_FREEBSD))
+			return Constants.WS_GTK;
 		if (os.equals(Constants.OS_MACOSX))
 			return Constants.WS_CARBON;
 		if (os.equals(Constants.OS_HPUX))
@@ -212,6 +215,8 @@
 			return Constants.OS_SOLARIS;
 		if (osName.equalsIgnoreCase(INTERNAL_OS_LINUX))
 			return Constants.OS_LINUX;
+		if (osName.equalsIgnoreCase(INTERNAL_OS_FREEBSD))
+			return Constants.OS_FREEBSD;
 		if (osName.equalsIgnoreCase(INTERNAL_OS_QNX))
 			return Constants.OS_QNX;
 		if (osName.equalsIgnoreCase(INTERNAL_OS_AIX))
