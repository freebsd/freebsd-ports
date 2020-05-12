--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2020-05-05 21:48:19 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1396,7 +1396,8 @@ export class ExtensionEditor extends BaseEditor {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
