--- plugins/org.eclipse.update.core/src/org/eclipse/update/internal/core/UpdateManagerUtils.java.orig	2008-08-03 10:44:20.960250999 -0400
+++ plugins/org.eclipse.update.core/src/org/eclipse/update/internal/core/UpdateManagerUtils.java	2008-08-03 10:45:13.560574224 -0400
@@ -68,6 +68,8 @@
 					.equals(Platform.getOS())
 			|| org.eclipse.osgi.service.environment.Constants.OS_LINUX
 					.equals(Platform.getOS())
+			|| org.eclipse.osgi.service.environment.Constants.OS_FREEBSD
+					.equals(Platform.getOS())
 			|| org.eclipse.osgi.service.environment.Constants.OS_SOLARIS
 					.equals(Platform.getOS())
 			|| org.eclipse.osgi.service.environment.Constants.OS_MACOSX
