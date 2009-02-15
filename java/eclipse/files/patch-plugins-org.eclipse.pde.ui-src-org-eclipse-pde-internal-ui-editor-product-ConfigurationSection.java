--- plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ConfigurationSection.java.orig	2008-08-02 17:38:50.000000000 -0400
+++ plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ConfigurationSection.java	2008-08-02 17:39:46.000000000 -0400
@@ -50,8 +50,8 @@
 	private FormEntry fCustomEntry;
 	private boolean fBlockChanges;
 
-	private static final String[] TAB_LABELS = {"linux", "macosx", "solaris", "win32"}; //$NON-NLS-1$  //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$
-	private static final String[] TAB_OS = {Platform.OS_LINUX, Platform.OS_MACOSX, Platform.OS_SOLARIS, Platform.OS_WIN32};
+	private static final String[] TAB_LABELS = {"linux", "freebsd", "macosx", "solaris", "win32"}; //$NON-NLS-1$  //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
+	private static final String[] TAB_OS = {Platform.OS_LINUX, Platform.OS_FREEBSD, Platform.OS_MACOSX, Platform.OS_SOLARIS, Platform.OS_WIN32};
 
 	private CTabFolder fTabFolder;
 	private int fLastTab;
