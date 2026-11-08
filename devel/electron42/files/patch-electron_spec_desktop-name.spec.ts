--- electron/spec/desktop-name.spec.ts.orig	2026-09-30 08:48:04 UTC
+++ electron/spec/desktop-name.spec.ts
@@ -10,7 +10,7 @@ const { defaultDesktopName }: typeof import('../lib/br
   '../lib/browser/desktop-name.ts'
 );
 
-ifdescribe(process.platform === 'linux')('defaultDesktopName', () => {
+ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('defaultDesktopName', () => {
   it("derives an appropriate .desktop name from the app's human readable name", () => {
     const fallback = `${path.basename(process.execPath)}.desktop`;
     const cases: Array<[string | undefined, string]> = [
