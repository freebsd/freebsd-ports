--- packages/lib/models/settings/builtInMetadata.ts.orig	2026-11-19 16:09:35 UTC
+++ packages/lib/models/settings/builtInMetadata.ts
@@ -2394,7 +2394,7 @@ const builtInMetadata = (Setting: typeof SettingType) 
 			appTypes: [AppType.Desktop],
 			label: () => 'Enable keychain support',
 			description: () => 'This is an experimental setting to enable keychain support on Linux',
-			show: () => shim.isLinux(),
+			show: () => shim.isLinux() || shim.isFreeBSD(),
 			section: 'general',
 			isGlobal: true,
 			advanced: true,
