--- gtk/org/eclipse/swt/browser/MozillaDelegate.java.orig	2008-08-02 21:58:22.782311909 -0400
+++ gtk/org/eclipse/swt/browser/MozillaDelegate.java	2008-08-02 22:00:13.312988015 -0400
@@ -26,14 +26,16 @@
 	static final int STOP_PROPOGATE = 1;
 
 	static boolean IsLinux;
+	static boolean IsFreeBSD;
 	static {
 		String osName = System.getProperty ("os.name").toLowerCase (); //$NON-NLS-1$
 		IsLinux = osName.startsWith ("linux"); //$NON-NLS-1$
+		IsFreeBSD = osName.startsWith ("freebsd"); //$NON-NLS-1$
 	}
 
 MozillaDelegate (Browser browser) {
 	super ();
-	if (!IsLinux) {
+	if (!IsLinux && !IsFreeBSD) {
 		browser.dispose ();
 		SWT.error (SWT.ERROR_NO_HANDLES, null, " [Unsupported platform]"); //$NON-NLS-1$
 	}
