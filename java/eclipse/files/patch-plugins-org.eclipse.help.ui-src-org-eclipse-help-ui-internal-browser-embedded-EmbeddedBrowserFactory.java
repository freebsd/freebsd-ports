--- plugins/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/browser/embedded/EmbeddedBrowserFactory.java.orig	2008-08-02 15:38:33.000000000 -0400
+++ plugins/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/browser/embedded/EmbeddedBrowserFactory.java	2008-08-02 15:40:18.000000000 -0400
@@ -61,7 +61,8 @@
 	 */
 	private boolean test() {
 		if (!Constants.OS_WIN32.equalsIgnoreCase(Platform.getOS())
-				&& !Constants.OS_LINUX.equalsIgnoreCase(Platform.getOS())) {
+				&& !Constants.OS_LINUX.equalsIgnoreCase(Platform.getOS())
+				&& !Constants.OS_FREEBSD.equalsIgnoreCase(Platform.getOS())) {
 			return false;
 		}
 		if (!tested) {
