--- plugins/org.eclipse.core.boot/src/org/eclipse/core/boot/BootLoader.java.orig	Thu Mar  6 12:13:43 2003
+++ plugins/org.eclipse.core.boot/src/org/eclipse/core/boot/BootLoader.java	Thu Mar  6 12:15:17 2003
@@ -51,6 +51,12 @@
 	public static final String OS_LINUX = "linux";//$NON-NLS-1$
 
 	/**
+	 * Constant string (value "freebsd") indicating the platform is running on a
+	 * FreeBSD operating system.
+	 */
+	public static final String OS_FREEBSD = "freebsd";//$NON-NLS-1$
+
+	/**
 	 * Constant string (value "aix") indicating the platform is running on an
 	 * AIX-based operating system.
 	 */
@@ -164,6 +170,7 @@
 		OS_AIX,
 		OS_HPUX,
 		OS_LINUX,
+		OS_FREEBSD,
 		OS_MACOSX,
 		OS_QNX,
 		OS_SOLARIS,
