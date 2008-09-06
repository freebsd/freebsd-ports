--- plugins/org.eclipse.core.runtime.compatibility/src-boot/org/eclipse/core/boot/BootLoader.java.orig	2008-08-02 14:57:57.000000000 -0400
+++ plugins/org.eclipse.core.runtime.compatibility/src-boot/org/eclipse/core/boot/BootLoader.java	2008-08-02 14:59:13.000000000 -0400
@@ -72,6 +72,13 @@
 	public static final String OS_LINUX = "linux";//$NON-NLS-1$
 
 	/**
+	 * Constant string (value "freebsd") indicating the platform is running on a
+	 * FreeBSD-based operating system.
+	 * @deprecated Replaced by {@link Platform#OS_FREEBSD}.
+	 */
+	public static final String OS_FREEBSD = "freebsd";//$NON-NLS-1$
+
+	/**
 	 * Constant string (value "aix") indicating the platform is running on an
 	 * AIX-based operating system.
 	 * @deprecated Replaced by {@link Platform#OS_AIX}.
