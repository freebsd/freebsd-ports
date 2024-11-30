--- electron/spec/visibility-state-spec.ts.orig	2024-11-27 18:42:14 UTC
+++ electron/spec/visibility-state-spec.ts
@@ -12,7 +12,7 @@ import { closeWindow } from './lib/window-helpers';
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('document.visibilityState', () => {
   let w: BaseWindow & {webContents: WebContents};
 
   afterEach(async () => {
