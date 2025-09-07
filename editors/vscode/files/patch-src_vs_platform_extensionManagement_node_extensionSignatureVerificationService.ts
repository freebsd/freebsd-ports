https://github.com/eclipse/openvsx/issues/543
https://github.com/termux/termux-packages/issues/24739
https://github.com/termux/termux-packages/pull/24757

--- src/vs/platform/extensionManagement/node/extensionSignatureVerificationService.ts.orig	2025-08-20 15:13:53 UTC
+++ src/vs/platform/extensionManagement/node/extensionSignatureVerificationService.ts
@@ -35,7 +35,7 @@ declare module vsceSign {
 }
 
 declare module vsceSign {
-	export function verify(vsixFilePath: string, signatureArchiveFilePath: string, verbose: boolean): Promise<ExtensionSignatureVerificationResult>;
+	export function verify(vsixFilePath: string, signatureArchiveFilePath: string, verbose: boolean): Promise<boolean>;
 }
 
 /**
@@ -67,7 +67,7 @@ export class ExtensionSignatureVerificationService imp
 	}
 
 	private async resolveVsceSign(): Promise<typeof vsceSign> {
-		const mod = '@vscode/vsce-sign';
+		const mod = 'node-ovsx-sign';
 		return import(mod);
 	}
 
@@ -87,7 +87,21 @@ export class ExtensionSignatureVerificationService imp
 
 		try {
 			this.logService.trace(`Verifying extension signature for ${extensionId}...`);
-			result = await module.verify(vsixFilePath, signatureArchiveFilePath, this.logService.getLevel() === LogLevel.Trace);
+			let isSignatureValid =
+				await module.verify(vsixFilePath, signatureArchiveFilePath, this.logService.getLevel() === LogLevel.Trace);
+			if (isSignatureValid) {
+				result = {
+					code: ExtensionSignatureVerificationCode.Success,
+					didExecute: true,
+					output: "The extension signature is valid."
+				};
+			} else {
+				result = {
+					code: ExtensionSignatureVerificationCode.SignatureIsNotValid,
+					didExecute: true,
+					output: "The extension signature is invalid."
+				};
+			}
 		} catch (e) {
 			result = {
 				code: ExtensionSignatureVerificationCode.UnknownError,
