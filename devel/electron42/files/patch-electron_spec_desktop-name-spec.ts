--- electron/spec/desktop-name-spec.ts.orig	2026-05-08 13:54:01 UTC
+++ electron/spec/desktop-name-spec.ts
@@ -5,7 +5,7 @@ import { ifdescribe } from './lib/spec-helpers';
 import { defaultDesktopName } from '../lib/browser/desktop-name';
 import { ifdescribe } from './lib/spec-helpers';
 
-ifdescribe(process.platform === 'linux')('defaultDesktopName', () => {
+ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('defaultDesktopName', () => {
   it("derives an appropriate .desktop name from the app's human readable name", () => {
     const fallback = `${path.basename(process.execPath)}.desktop`;
     const cases: Array<[string | undefined, string]> = [
