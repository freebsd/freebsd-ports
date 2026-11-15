--- electron/spec/desktop-name.spec.ts.orig	2026-10-26 21:12:45 UTC
+++ electron/spec/desktop-name.spec.ts
@@ -6,7 +6,7 @@ const { defaultDesktopName } = process._linkedBinding(
 
 const { defaultDesktopName } = process._linkedBinding('electron_browser_app');
 
-ifdescribe(process.platform === 'linux')('defaultDesktopName', () => {
+ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('defaultDesktopName', () => {
   it("derives an appropriate .desktop name from the app's human readable name", () => {
     const fallback = `${path.basename(process.execPath)}.desktop`;
     const cases: Array<[string | undefined, string]> = [
