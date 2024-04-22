--- electron/spec/visibility-state-spec.ts.orig	2023-05-31 14:28:29 UTC
+++ electron/spec/visibility-state-spec.ts
@@ -10,7 +10,7 @@ import { setTimeout } from 'timers/promises';
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('document.visibilityState', () => {
   let w: BrowserWindow;
 
   afterEach(() => {
