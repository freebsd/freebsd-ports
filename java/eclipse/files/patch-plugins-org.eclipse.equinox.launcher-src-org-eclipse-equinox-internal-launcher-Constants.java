--- plugins/org.eclipse.equinox.launcher/src/org/eclipse/equinox/internal/launcher/Constants.java.orig	2008-08-02 12:22:09.000000000 -0400
+++ plugins/org.eclipse.equinox.launcher/src/org/eclipse/equinox/internal/launcher/Constants.java	2008-08-02 12:24:21.000000000 -0400
@@ -19,6 +19,7 @@
 	public static final String INTERNAL_AMD64 = "amd64"; //$NON-NLS-1$
 	public static final String INTERNAL_OS_SUNOS = "SunOS"; //$NON-NLS-1$
 	public static final String INTERNAL_OS_LINUX = "Linux"; //$NON-NLS-1$
+	public static final String INTERNAL_OS_FREEBSD = "FreeBSD"; //$NON-NLS-1$
 	public static final String INTERNAL_OS_MACOSX = "Mac OS"; //$NON-NLS-1$
 	public static final String INTERNAL_OS_AIX = "AIX"; //$NON-NLS-1$
 	public static final String INTERNAL_OS_HPUX = "HP-UX"; //$NON-NLS-1$
@@ -40,6 +41,12 @@
 	public static final String OS_LINUX = "linux";//$NON-NLS-1$
 
 	/**
+	 * Constant string (value "freebsd") indicating the platform is running on a
+	 * FreeBSD-based operating system.
+	 */
+	public static final String OS_FREEBSD = "freebsd";//$NON-NLS-1$
+
+	/**
 	 * Constant string (value "aix") indicating the platform is running on an
 	 * AIX-based operating system.
 	 */
