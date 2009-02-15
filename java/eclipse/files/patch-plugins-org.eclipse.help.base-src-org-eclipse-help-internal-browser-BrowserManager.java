--- plugins/org.eclipse.help.base/src/org/eclipse/help/internal/browser/BrowserManager.java.orig	2008-08-02 15:35:43.000000000 -0400
+++ plugins/org.eclipse.help.base/src/org/eclipse/help/internal/browser/BrowserManager.java	2008-08-02 15:35:12.000000000 -0400
@@ -94,6 +94,7 @@
 			} else if (Constants.OS_AIX.equalsIgnoreCase(os)
 					|| (Constants.OS_HPUX.equalsIgnoreCase(os))
 					|| (Constants.OS_LINUX.equalsIgnoreCase(os))
+					|| (Constants.OS_FREEBSD.equalsIgnoreCase(os))
 					|| (Constants.OS_SOLARIS.equalsIgnoreCase(os))) {
 				setDefaultBrowserID(BROWSER_ID_MOZILLA);
 				if (defaultBrowserDesc == null) {
