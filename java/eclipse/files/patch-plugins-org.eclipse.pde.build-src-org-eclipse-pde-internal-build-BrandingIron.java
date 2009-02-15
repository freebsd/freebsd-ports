--- plugins/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/BrandingIron.java.orig	2008-08-02 16:46:29.000000000 -0400
+++ plugins/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/BrandingIron.java	2008-08-02 16:48:54.000000000 -0400
@@ -70,6 +70,8 @@
 			brandWindows();
 		if ("linux".equals(os)) //$NON-NLS-1$
 			brandLinux();
+		if ("freebsd".equals(os)) //$NON-NLS-1$
+			brandFreeBSD();
 		if ("solaris".equals(os)) //$NON-NLS-1$
 			brandSolaris();
 		if ("macosx".equals(os)) //$NON-NLS-1$
@@ -94,6 +96,12 @@
 			copy(new File(icons[0]), new File(root, "icon.xpm")); //$NON-NLS-1$
 	}
 
+	private void brandFreeBSD() throws Exception {
+		renameLauncher();
+		if (brandIcons)
+			copy(new File(icons[0]), new File(root, "icon.xpm")); //$NON-NLS-1$
+	}
+
 	private void brandSolaris() throws Exception {
 		renameLauncher();
 		if (brandIcons == false)
