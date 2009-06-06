--- plugins/org.eclipse.core.runtime/src/org/eclipse/core/runtime/Platform.java.orig	2009-02-15 19:26:27.391641089 -0500
+++ plugins/org.eclipse.core.runtime/src/org/eclipse/core/runtime/Platform.java	2009-02-15 20:39:45.324834833 -0500
@@ -204,6 +204,17 @@
 	public static final String OS_LINUX = "linux";//$NON-NLS-1$
 
 	/**
+	 * Constant string (value "freebsd") indicating the platform is running on a
+	 * FreeBSD-based operating system.
+	 * <p>
+	 * Note this constant has been moved from the deprecated
+	 * org.eclipse.core.boot.BootLoader class and its value has not changed.
+	 * </p>
+	 * @since 3.0
+	 */
+	public static final String OS_FREEBSD = "freebsd";//$NON-NLS-1$
+
+	/**
 	 * Constant string (value "aix") indicating the platform is running on an
 	 * AIX-based operating system.
 	 * <p>
