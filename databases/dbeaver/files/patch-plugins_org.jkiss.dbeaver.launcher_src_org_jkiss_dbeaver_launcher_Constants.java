--- plugins/org.jkiss.dbeaver.launcher/src/org/jkiss/dbeaver/launcher/Constants.java.orig	2025-07-18 15:47:12 UTC
+++ plugins/org.jkiss.dbeaver.launcher/src/org/jkiss/dbeaver/launcher/Constants.java
@@ -30,6 +30,7 @@ public class Constants {
     public static final String INTERNAL_OS_OS400 = "OS/400"; //$NON-NLS-1$
     public static final String INTERNAL_OS_OS390 = "OS/390"; //$NON-NLS-1$
     public static final String INTERNAL_OS_ZOS = "z/OS"; //$NON-NLS-1$
+    public static final String INTERNAL_OS_FREEBSD = "FreeBSD"; //$NON-NLS-1$
 
     public static final String ARCH_X86 = "x86";//$NON-NLS-1$
     public static final String ARCH_X86_64 = "x86_64";//$NON-NLS-1$
@@ -45,6 +46,12 @@ public class Constants {
      * Linux-based operating system.
      */
     public static final String OS_LINUX = "linux";//$NON-NLS-1$
+
+    /**
+     * Constant string (value "freebsd") indicating the platform is running on a
+     * FreeBSD-based operating system.
+     */
+    public static final String OS_FREEBSD = "freebsd";//$NON-NLS-1$
 
     /**
      * Constant string (value "aix") indicating the platform is running on an
