--- plugins/org.eclipse.ui.browser/src/org/eclipse/ui/internal/browser/ExternalBrowserInstance.java.orig	Sun Apr  3 15:44:23 2005
+++ plugins/org.eclipse.ui.browser/src/org/eclipse/ui/internal/browser/ExternalBrowserInstance.java	Sun Apr  3 15:44:47 2005

@@ -74,7 +74,7 @@
 			public void run() {
 				try {
 					process.waitFor();
-					DefaultBrowserSupport.getInstance().removeBrowser(getId());
+					DefaultBrowserSupport.getInstance().removeBrowser(ExternalBrowserInstance.this.getId());
 				} catch (Exception e) {
 					// ignore
 				}

