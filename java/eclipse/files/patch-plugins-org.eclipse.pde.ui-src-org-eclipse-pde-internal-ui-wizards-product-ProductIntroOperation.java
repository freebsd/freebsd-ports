--- plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/wizards/product/ProductIntroOperation.java.orig	2008-08-02 21:38:59.940166888 -0400
+++ plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/wizards/product/ProductIntroOperation.java	2008-08-02 21:39:29.890351339 -0400
@@ -127,7 +127,7 @@
 		implementation.setName("implementation"); //$NON-NLS-1$
 		implementation.setAttribute("kind", "html"); //$NON-NLS-1$ //$NON-NLS-2$
 		implementation.setAttribute("style", "content/shared.css"); //$NON-NLS-1$ //$NON-NLS-2$
-		implementation.setAttribute("os", "win32,linux,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
+		implementation.setAttribute("os", "win32,freebsd,linux,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
 
 		presentation.add(implementation);
 
