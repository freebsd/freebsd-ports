--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2020-08-25 09:40:01 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1397,7 +1397,8 @@ export class ExtensionEditor extends BaseEditor {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
