--- packages/lib/services/contextkey/contextkey.ts.orig	2023-09-06 12:25:48 UTC
+++ packages/lib/services/contextkey/contextkey.ts
@@ -3,7 +3,7 @@
 // Note: This is taken from the VScode source code, which has a nicely self-contained
 // way to parse an expression (which they call "when-clause") and return a boolean.
 //
-// Taken from: 
+// Taken from:
 // https://github.com/microsoft/vscode/blob/dfa980ebdad245a60b217de7468bc8ced953c906/src/vs/platform/contextkey/common/contextkey.ts
 //
 // With minor changes to make it work without the VSCode imports.
@@ -26,6 +26,7 @@ import shim from '../../shim';
 
 const isMacintosh = shim.isMac();
 const isLinux = shim.isLinux();
+const isFreeBSD = shim.isFreeBSD();
 const isWindows = shim.isWindows();
 const isWeb = false;
 
@@ -45,6 +46,7 @@ STATIC_VALUES.set('false', false);
 STATIC_VALUES.set('true', true);
 STATIC_VALUES.set('isMac', isMacintosh);
 STATIC_VALUES.set('isLinux', isLinux);
+STATIC_VALUES.set('isFreeBSD', isFreeBSD);
 STATIC_VALUES.set('isWindows', isWindows);
 STATIC_VALUES.set('isWeb', isWeb);
 STATIC_VALUES.set('isMacNative', isMacintosh && !isWeb);
@@ -1174,4 +1176,4 @@ export interface IContextKeyService {
 	updateParent(parentContextKeyService?: IContextKeyService): void;
 }
 
-export const SET_CONTEXT_COMMAND_ID = 'setContext';
\ No newline at end of file
+export const SET_CONTEXT_COMMAND_ID = 'setContext';
