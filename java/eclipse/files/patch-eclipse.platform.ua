diff -ru eclipse.platform.ua/org.eclipse.help.base/plugin.xml eclipse.platform.ua/org.eclipse.help.base/plugin.xml
--- eclipse.platform.ua/org.eclipse.help.base/plugin.xml	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.platform.ua/org.eclipse.help.base/plugin.xml	0000-00-00 00:00:00.000000000 +0000
@@ -131,7 +131,7 @@
             </parameter>
             <parameter
                   name="os"
-                  value="Linux,AIX,HP,SunOS">
+                  value="FreeBSD,Linux,AIX,HP,SunOS">
             </parameter>
          </factoryclass>
       </browser>
@@ -150,7 +150,7 @@
             </parameter>
             <parameter
                   name="os"
-                  value="Linux,AIX,HP,SunOS">
+                  value="FreeBSD,Linux,AIX,HP,SunOS">
             </parameter>
          </factoryclass>
       </browser>
@@ -169,7 +169,7 @@
             </parameter>
             <parameter
                   name="os"
-                  value="Linux,AIX,HP,SunOS">
+                  value="FreeBSD,Linux,AIX,HP,SunOS">
             </parameter>
          </factoryclass>
       </browser>
diff -ru eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/base/HelpBasePreferenceInitializer.java eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/base/HelpBasePreferenceInitializer.java
--- eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/base/HelpBasePreferenceInitializer.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/base/HelpBasePreferenceInitializer.java	0000-00-00 00:00:00.000000000 +0000
@@ -35,7 +35,7 @@
 			prefs
 					.put("custom_browser_path", //$NON-NLS-1$
 							"\"C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE\" %1"); //$NON-NLS-1$
-		} else if (os.contains("linux")) { //$NON-NLS-1$
+		} else if (os.contains("linux") || os.contains("freebsd")) { //$NON-NLS-1$
 			prefs.put("custom_browser_path", //$NON-NLS-1$
 					"konqueror %1"); //$NON-NLS-1$
 		} else {
diff -ru eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/browser/BrowserManager.java eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/browser/BrowserManager.java
--- eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/browser/BrowserManager.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.platform.ua/org.eclipse.help.base/src/org/eclipse/help/internal/browser/BrowserManager.java	0000-00-00 00:00:00.000000000 +0000
@@ -102,6 +102,7 @@
 				setDefaultBrowserID(BROWSER_ID_SYSTEM);
 			} else if (Constants.OS_AIX.equalsIgnoreCase(os)
 					|| (Constants.OS_HPUX.equalsIgnoreCase(os))
+					|| (Constants.OS_FREEBSD.equalsIgnoreCase(os))
 					|| (Constants.OS_LINUX.equalsIgnoreCase(os))
 					|| (Constants.OS_SOLARIS.equalsIgnoreCase(os))) {
 				setDefaultBrowserID(BROWSER_ID_MOZILLA);
diff -ru eclipse.platform.ua/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/browser/embedded/EmbeddedBrowserFactory.java eclipse.platform.ua/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/browser/embedded/EmbeddedBrowserFactory.java
--- eclipse.platform.ua/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/browser/embedded/EmbeddedBrowserFactory.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.platform.ua/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/browser/embedded/EmbeddedBrowserFactory.java	0000-00-00 00:00:00.000000000 +0000
@@ -67,6 +67,7 @@
 	 */
 	private boolean test() {
 		if (!Constants.OS_WIN32.equalsIgnoreCase(Platform.getOS())
+				&& !Constants.OS_FREEBSD.equalsIgnoreCase(Platform.getOS())
 				&& !Constants.OS_LINUX.equalsIgnoreCase(Platform.getOS())) {
 			return false;
 		}
