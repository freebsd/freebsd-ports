--- test/smoke/src/areas/terminal/terminal.test.ts.orig	2025-07-09 22:00:36 UTC
+++ test/smoke/src/areas/terminal/terminal.test.ts
@@ -39,15 +39,15 @@ export function setup(logger: Logger) {
 		// https://github.com/microsoft/vscode/issues/216564
 		// The pty host can crash on Linux in smoke tests for an unknown reason. We need more user
 		// reports to investigate
-		setupTerminalEditorsTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalInputTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalPersistenceTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalProfileTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalTabsTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalShellIntegrationTests({ skipSuite: process.platform === 'linux' });
+		setupTerminalEditorsTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd') });
+		setupTerminalInputTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd') });
+		setupTerminalPersistenceTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd') });
+		setupTerminalProfileTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd') });
+		setupTerminalTabsTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd') });
+		setupTerminalShellIntegrationTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd') });
 		setupTerminalStickyScrollTests({ skipSuite: true });
 		// https://github.com/microsoft/vscode/pull/141974
 		// Windows is skipped here as well as it was never enabled from the start
-		setupTerminalSplitCwdTests({ skipSuite: process.platform === 'linux' || process.platform === 'win32' });
+		setupTerminalSplitCwdTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'win32') });
 	});
 }
