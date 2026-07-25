--- electron/spec/visibility-state-spec.ts.orig	2026-07-21 15:33:01 UTC
+++ electron/spec/visibility-state-spec.ts
@@ -19,7 +19,7 @@ import { closeAllWindows } from './lib/window-helpers'
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('document.visibilityState', () => {
   let w: BaseWindow & { webContents: WebContents };
 
   before(() => {
