--- plugins/org.eclipse.osgi/core/adaptor/org/eclipse/osgi/util/TextProcessor.java.orig	2008-08-02 13:18:14.000000000 -0400
+++ plugins/org.eclipse.osgi/core/adaptor/org/eclipse/osgi/util/TextProcessor.java	2008-08-02 13:20:06.000000000 -0400
@@ -77,7 +77,7 @@
 
 		if ("iw".equals(lang) || "he".equals(lang) || "ar".equals(lang) || "fa".equals(lang) || "ur".equals(lang)) { //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
 			String osName = System.getProperty("os.name").toLowerCase(); //$NON-NLS-1$
-			if (osName.startsWith("windows") || osName.startsWith("linux")) { //$NON-NLS-1$	//$NON-NLS-2$
+			if (osName.startsWith("windows") || osName.startsWith("linux") || osName.startsWith("freebsd")) { //$NON-NLS-1$	//$NON-NLS-2$ //$NON-NLS-3$
 				IS_PROCESSING_NEEDED = true;
 			}
 		}
