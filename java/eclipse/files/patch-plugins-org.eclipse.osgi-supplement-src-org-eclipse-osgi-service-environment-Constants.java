--- plugins/org.eclipse.osgi/supplement/src/org/eclipse/osgi/service/environment/Constants.java.orig	2008-08-09 09:16:08.932328502 -0400
+++ plugins/org.eclipse.osgi/supplement/src/org/eclipse/osgi/service/environment/Constants.java	2008-08-09 09:15:29.572165618 -0400
@@ -34,6 +34,12 @@
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
@@ -115,7 +121,7 @@
 	 * @deprecated use <code>ARCH_X86_64</code> instead. Note the values
 	 * has been changed to be the value of the <code>ARCH_X86_64</code> constant.
 	 */
-	public static final String ARCH_AMD64 = ARCH_X86_64;
+	public static final String ARCH_AMD64 = "amd64";//$NON-NLS-1$
 
 	/**
 	 * Constant string (value "ia64") indicating the platform is running on an
