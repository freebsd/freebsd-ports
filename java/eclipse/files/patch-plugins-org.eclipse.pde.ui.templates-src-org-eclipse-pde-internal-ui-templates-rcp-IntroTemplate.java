--- plugins/org.eclipse.pde.ui.templates/src/org/eclipse/pde/internal/ui/templates/rcp/IntroTemplate.java.orig	2008-08-02 21:48:19.733606277 -0400
+++ plugins/org.eclipse.pde.ui.templates/src/org/eclipse/pde/internal/ui/templates/rcp/IntroTemplate.java	2008-08-02 21:49:05.223891216 -0400
@@ -160,7 +160,7 @@
 		presentationElement.setAttribute("home-page-id", "root"); //$NON-NLS-1$ //$NON-NLS-2$
 		IPluginElement implementationElement = factory.createElement(presentationElement);
 		implementationElement.setName("implementation"); //$NON-NLS-1$
-		implementationElement.setAttribute("os", "win32,linux,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
+		implementationElement.setAttribute("os", "win32,linux,freebsd,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
 		if (getTargetVersion() == 3.0)
 			implementationElement.setAttribute("style", "content/shared.css"); //$NON-NLS-1$//$NON-NLS-2$
 
