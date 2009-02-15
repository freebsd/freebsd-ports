--- plugins/org.eclipse.equinox.frameworkadmin.equinox/src/org/eclipse/equinox/internal/frameworkadmin/equinox/EquinoxBundlesState.java.orig	2008-08-09 14:32:49.360935838 -0400
+++ plugins/org.eclipse.equinox.frameworkadmin.equinox/src/org/eclipse/equinox/internal/frameworkadmin/equinox/EquinoxBundlesState.java	2008-08-09 14:32:30.730855758 -0400
@@ -209,9 +209,6 @@
 		// Map i386 architecture to x86
 		if (name.equalsIgnoreCase(INTERNAL_ARCH_I386))
 			arch = org.eclipse.osgi.service.environment.Constants.ARCH_X86;
-		// Map amd64 architecture to x86_64
-		else if (name.equalsIgnoreCase(INTERNAL_AMD64))
-			arch = org.eclipse.osgi.service.environment.Constants.ARCH_X86_64;
 		else
 			arch = name;
 		platformProperties.setProperty("osgi.arch", arch); //$NON-NLS-1$			
