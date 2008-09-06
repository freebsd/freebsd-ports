--- plugins/org.eclipse.core.runtime/src/org/eclipse/core/runtime/Platform.java.orig	2008-08-09 09:17:56.822774634 -0400
+++ plugins/org.eclipse.core.runtime/src/org/eclipse/core/runtime/Platform.java	2008-08-09 09:17:33.922680697 -0400
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
@@ -329,7 +340,7 @@
 	 * @deprecated use <code>ARCH_X86_64</code> instead. Note the values
 	 * has been changed to be the value of the <code>ARCH_X86_64</code> constant.
 	 */
-	public static final String ARCH_AMD64 = ARCH_X86_64;
+	public static final String ARCH_AMD64 = "amd64";//$NON-NLS-1$
 
 	/**
 	 * Constant string (value "ia64") indicating the platform is running on an
