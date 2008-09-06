--- plugins/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/Utils.java.orig	2008-08-02 16:49:39.000000000 -0400
+++ plugins/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/Utils.java	2008-08-02 17:07:42.000000000 -0400
@@ -13,6 +13,7 @@
 import java.net.URL;
 import java.util.*;
 import org.eclipse.core.runtime.*;
+import org.eclipse.osgi.service.environment.Constants;
 import org.eclipse.osgi.service.resolver.BundleDescription;
 import org.eclipse.osgi.util.NLS;
 import org.eclipse.pde.internal.build.ant.AntScript;
@@ -433,7 +434,12 @@
 			arguments.add("-sf"); //$NON-NLS-1$
 			arguments.add(links[i]);
 			arguments.add(links[i + 1]);
-			script.printExecTask("ln", dir, arguments, "Linux"); //$NON-NLS-1$ //$NON-NLS-2$
+			String os = System.getProperty("osgi.os", ""); //$NON-NLS-1$ //$NON-NLS-2$
+			String osStr = "Linux"; //$NON-NLS-1$
+			if (os.equals(Constants.OS_FREEBSD)) {
+				osStr = "FreeBSD"; //$NON-NLS-1$
+			}
+			script.printExecTask("ln", dir, arguments, osStr); //$NON-NLS-1$
 			arguments.clear();
 		}
 	}
