--- packages/app-desktop/bridge.ts.orig	2026-09-07 07:29:33 UTC
+++ packages/app-desktop/bridge.ts
@@ -77,7 +77,7 @@ export class Bridge {
 			case 'darwin':
 				// macOS: Use ~/Library/Logs/DiagnosticReports
 				return join(homedir(), 'Library', 'Logs', 'DiagnosticReports');
-			case 'linux':
+			case 'linux': case 'freebsd':
 				// Linux: Use XDG_STATE_HOME (for logs) or fallback to ~/.local/state
 				return join(process.env.XDG_STATE_HOME || join(homedir(), '.local', 'state'), 'joplin');
 			default:
