--- electron/spec/visibility-state-spec.ts.orig	2024-04-16 14:29:17 UTC
+++ electron/spec/visibility-state-spec.ts
@@ -10,7 +10,7 @@ import { setTimeout } from 'node:timers/promises';
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('document.visibilityState', () => {
   let w: BaseWindow & {webContents: WebContents};
 
   afterEach(() => {
