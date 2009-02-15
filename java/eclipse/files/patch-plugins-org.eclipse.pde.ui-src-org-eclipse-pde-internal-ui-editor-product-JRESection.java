--- plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/JRESection.java.orig	2008-08-02 21:34:49.378631553 -0400
+++ plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/JRESection.java	2008-08-02 21:36:12.049135765 -0400
@@ -77,8 +77,8 @@
 	private ComboViewerPart fEEsCombo;
 	private boolean fBlockChanges;
 
-	private static final String[] TAB_LABELS = {"linux", "macosx", "solaris", "win32"}; //$NON-NLS-1$  //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$
-	private static final String[] TAB_OS = {Platform.OS_LINUX, Platform.OS_MACOSX, Platform.OS_SOLARIS, Platform.OS_WIN32};
+	private static final String[] TAB_LABELS = {"linux", "freebsd", "macosx", "solaris", "win32"}; //$NON-NLS-1$  //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$
+	private static final String[] TAB_OS = {Platform.OS_LINUX, Platform.OS_FREEBSD, Platform.OS_MACOSX, Platform.OS_SOLARIS, Platform.OS_WIN32};
 
 	private CTabFolder fTabFolder;
 	private int fLastTab;
