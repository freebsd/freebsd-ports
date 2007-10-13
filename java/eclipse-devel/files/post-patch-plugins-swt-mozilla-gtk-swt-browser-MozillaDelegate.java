--- plugins/org.eclipse.swt/Eclipse SWT Mozilla/gtk/org/eclipse/swt/browser/MozillaDelegate.java.orig	2007-06-26 04:57:02.000000000 +0900
+++ plugins/org.eclipse.swt/Eclipse SWT Mozilla/gtk/org/eclipse/swt/browser/MozillaDelegate.java	2007-09-12 13:17:45.000000000 +0900
@@ -26,14 +26,17 @@
 	static final int STOP_PROPOGATE = 1;
 
 	static boolean IsLinux;
+	static boolean IsFreeBSD;
 	static {
 		String osName = System.getProperty ("os.name").toLowerCase (); //$NON-NLS-1$
 		IsLinux = osName.startsWith ("linux"); //$NON-NLS-1$
+		IsFreeBSD = osName.startsWith ("freebsd"); //$NON-NLS-1$
+		
 	}
 
 MozillaDelegate (Browser browser) {
 	super ();
-	if (!IsLinux) {
+	if (!IsLinux && !IsFreeBSD) {
 		browser.dispose ();
 		SWT.error (SWT.ERROR_NO_HANDLES, null, " [Unsupported platform]"); //$NON-NLS-1$
 	}
