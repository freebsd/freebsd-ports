--- electron/spec/visibility-state-spec.ts.orig	2024-10-22 02:29:46 UTC
+++ electron/spec/visibility-state-spec.ts
@@ -11,7 +11,7 @@ import { closeAllWindows } from './lib/window-helpers'
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('document.visibilityState', () => {
   let w: BaseWindow & {webContents: WebContents};
 
   before(() => {
