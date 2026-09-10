--- packages/lib/models/settings/builtInMetadata.ts.orig	2026-09-05 19:41:51 UTC
+++ packages/lib/models/settings/builtInMetadata.ts
@@ -2335,7 +2335,7 @@ const builtInMetadata = (Setting: typeof SettingType) 
 			appTypes: [AppType.Desktop],
 			label: () => 'Enable keychain support',
 			description: () => 'This is an experimental setting to enable keychain support on Linux',
-			show: () => shim.isLinux(),
+			show: () => shim.isLinux() || shim.isFreeBSD(),
 			section: 'general',
 			isGlobal: true,
 			advanced: true,
