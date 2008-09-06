--- plugins/org.eclipse.help.base/src/org/eclipse/help/internal/base/HelpBasePreferenceInitializer.java.orig	2008-08-02 15:30:15.000000000 -0400
+++ plugins/org.eclipse.help.base/src/org/eclipse/help/internal/base/HelpBasePreferenceInitializer.java	2008-08-02 15:31:53.000000000 -0400
@@ -37,6 +37,9 @@
 		} else if (os.indexOf("linux") != -1) { //$NON-NLS-1$
 			prefs.setDefault("custom_browser_path", //$NON-NLS-1$
 					"konqueror %1"); //$NON-NLS-1$
+		} else if (os.indexOf("freebsd") != -1) { //$NON-NLS-1$
+			prefs.setDefault("custom_browser_path", //$NON-NLS-1$
+					"firefox %1"); //$NON-NLS-1$
 		} else {
 			prefs.setDefault("custom_browser_path", "mozilla %1"); //$NON-NLS-1$ //$NON-NLS-2$
 		}
