--- plugins/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/builder/ModelBuildScriptGenerator.java.orig	2008-08-02 16:30:36.000000000 -0400
+++ plugins/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/builder/ModelBuildScriptGenerator.java	2008-08-02 16:45:09.000000000 -0400
@@ -12,6 +12,7 @@
 import java.io.*;
 import java.util.*;
 import org.eclipse.core.runtime.*;
+import org.eclipse.osgi.service.environment.Constants;
 import org.eclipse.osgi.service.resolver.BundleDescription;
 import org.eclipse.osgi.util.NLS;
 import org.eclipse.pde.internal.build.*;
@@ -621,7 +622,12 @@
 		for (int i = 0; i < links.length; i += 2) {
 			arguments.add(links[i]);
 			arguments.add(links[i + 1]);
-			script.printExecTask("ln -s", dir, arguments, "Linux"); //$NON-NLS-1$ //$NON-NLS-2$
+			String os = System.getProperty("osgi.os", ""); //$NON-NLS-1$ //$NON-NLS-2$
+			String osStr = "Linux"; //$NON-NLS-1$
+			if (os.equals(Constants.OS_FREEBSD)) {
+				osStr = "FreeBSD"; //$NON-NLS-1$
+			}
+			script.printExecTask("ln -s", dir, arguments, osStr); //$NON-NLS-1$
 			arguments.clear();
 		}
 	}
