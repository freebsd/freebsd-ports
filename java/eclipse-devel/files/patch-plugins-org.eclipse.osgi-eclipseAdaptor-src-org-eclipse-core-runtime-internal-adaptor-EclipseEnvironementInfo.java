--- ./plugins/org.eclipse.osgi/eclipseAdaptor/src/org/eclipse/core/runtime/internal/adaptor/EclipseEnvironmentInfo.java.orig	2008-08-08 23:54:36.137941647 -0400
+++ ./plugins/org.eclipse.osgi/eclipseAdaptor/src/org/eclipse/core/runtime/internal/adaptor/EclipseEnvironmentInfo.java	2008-08-08 23:52:33.527433817 -0400
@@ -33,6 +33,7 @@
 	// this internally to be Solaris.
 	private static final String INTERNAL_OS_SUNOS = "SunOS"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_LINUX = "Linux"; //$NON-NLS-1$
+	private static final String INTERNAL_OS_FREEBSD = "FreeBSD"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_MACOSX = "Mac OS"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_AIX = "AIX"; //$NON-NLS-1$
 	private static final String INTERNAL_OS_HPUX = "HP-UX"; //$NON-NLS-1$
@@ -41,9 +42,6 @@
 	// While we recognize the i386 architecture, we change
 	// this internally to be x86.
 	private static final String INTERNAL_ARCH_I386 = "i386"; //$NON-NLS-1$
-	// While we recognize the amd64 architecture, we change
-	// this internally to be x86_64.
-	private static final String INTERNAL_AMD64 = "amd64"; //$NON-NLS-1$
 
 	private EclipseEnvironmentInfo() {
 		super();
@@ -159,9 +157,6 @@
 			// Map i386 architecture to x86
 			if (name.equalsIgnoreCase(INTERNAL_ARCH_I386))
 				arch = Constants.ARCH_X86;
-			// Map amd64 architecture to x86_64
-			else if (name.equalsIgnoreCase(INTERNAL_AMD64))
-				arch = Constants.ARCH_X86_64;
 			else
 				arch = name;
 			FrameworkProperties.setProperty("osgi.arch", arch); //$NON-NLS-1$			
@@ -189,6 +184,8 @@
 			return Constants.WS_WIN32;
 		if (os.equals(Constants.OS_LINUX))
 			return Constants.WS_GTK;
+		if (os.equals(Constants.OS_FREEBSD))
+			return Constants.WS_GTK;
 		if (os.equals(Constants.OS_MACOSX))
 			return Constants.WS_CARBON;
 		if (os.equals(Constants.OS_HPUX))
@@ -212,6 +209,8 @@
 			return Constants.OS_SOLARIS;
 		if (osName.equalsIgnoreCase(INTERNAL_OS_LINUX))
 			return Constants.OS_LINUX;
+		if (osName.equalsIgnoreCase(INTERNAL_OS_FREEBSD))
+			return Constants.OS_FREEBSD;
 		if (osName.equalsIgnoreCase(INTERNAL_OS_QNX))
 			return Constants.OS_QNX;
 		if (osName.equalsIgnoreCase(INTERNAL_OS_AIX))
