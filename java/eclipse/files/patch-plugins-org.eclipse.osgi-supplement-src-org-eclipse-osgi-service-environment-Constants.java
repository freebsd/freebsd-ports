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
