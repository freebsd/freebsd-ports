--- plugins/org.eclipse.pde.build/src_ant/org/eclipse/pde/internal/build/tasks/JNLPGenerator.java.orig	2008-08-02 16:28:25.000000000 -0400
+++ plugins/org.eclipse.pde.build/src_ant/org/eclipse/pde/internal/build/tasks/JNLPGenerator.java	2008-08-02 16:29:14.000000000 -0400
@@ -307,6 +307,8 @@
 			return "Mac"; //$NON-NLS-1$
 		if ("linux".equalsIgnoreCase(os)) //$NON-NLS-1$
 			return "Linux"; //$NON-NLS-1$
+		if ("freebsd".equalsIgnoreCase(os)) //$NON-NLS-1$
+			return "FreeBSD"; //$NON-NLS-1$
 		if ("solaris".equalsIgnoreCase(os)) //$NON-NLS-1$
 			return "Solaris"; //$NON-NLS-1$
 		if ("hpux".equalsIgnoreCase(os)) //$NON-NLS-1$
