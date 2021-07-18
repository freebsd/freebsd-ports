--- electron/spec-main/visibility-state-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/visibility-state-spec.ts
@@ -9,7 +9,7 @@ import { ifdescribe, delay } from './spec-helpers';
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('document.visibilityState', () => {
   let w: BrowserWindow;
 
   afterEach(() => {
