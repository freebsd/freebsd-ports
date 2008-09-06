--- plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ArgumentsSection.java.orig	2008-08-02 17:36:55.000000000 -0400
+++ plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ArgumentsSection.java	2008-08-02 17:37:50.000000000 -0400
@@ -35,6 +35,7 @@
 	static {
 		TAB_LABELS[IArgumentsInfo.L_ARGS_ALL] = PDEUIMessages.ArgumentsSection_allPlatforms;
 		TAB_LABELS[IArgumentsInfo.L_ARGS_LINUX] = "linux"; //$NON-NLS-1$
+		TAB_LABELS[IArgumentsInfo.L_ARGS_FREEBSD] = "freebsd"; //$NON-NLS-1$
 		TAB_LABELS[IArgumentsInfo.L_ARGS_MACOS] = "macosx"; //$NON-NLS-1$
 		TAB_LABELS[IArgumentsInfo.L_ARGS_SOLAR] = "solaris"; //$NON-NLS-1$
 		TAB_LABELS[IArgumentsInfo.L_ARGS_WIN32] = "win32"; //$NON-NLS-1$
