--- plugins/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/util/RuntimeErrorDialog.java.orig	Thu Mar  6 12:23:58 2003
+++ plugins/org.eclipse.help.ui/src/org/eclipse/help/ui/internal/util/RuntimeErrorDialog.java	Thu Mar  6 12:25:26 2003
@@ -68,8 +68,10 @@
 			data.widthHint = getMinimumMessageWidth();
 			// set the default height on linux. 
 			// Note: on Windows, the default height is fine.
-			if (System.getProperty("os.name").startsWith("Linux"))
+			if (System.getProperty("os.name").startsWith("Linux") ||
+			    System.getProperty("os.name").startsWith("FreeBSD"))
 				data.heightHint = convertVerticalDLUsToPixels(100);
+			else
 			text.setLayoutData(data);
 			text.setFont(parent.getFont());
 			text.setBackground(composite.getDisplay().getSystemColor(SWT.COLOR_WHITE));
@@ -88,4 +90,4 @@
 		dialog.open();
 		return;
 	}
-}
\ No newline at end of file
+}
