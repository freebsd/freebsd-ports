--- electron/spec/api-system-preferences.spec.ts.orig	2026-09-30 08:47:42 UTC
+++ electron/spec/api-system-preferences.spec.ts
@@ -5,8 +5,8 @@ describe('systemPreferences module', () => {
 import { ifdescribe, ifit } from './lib/spec-helpers.ts';
 
 describe('systemPreferences module', () => {
-  ifdescribe(['win32', 'linux'].includes(process.platform))('systemPreferences.getAccentColor', () => {
-    ifit(process.platform === 'linux')('should return a string', () => {
+  ifdescribe(['win32', 'linux', 'freebsd'].includes(process.platform))('systemPreferences.getAccentColor', () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should return a string', () => {
       // Testing this properly (i.e. non-empty string) requires
       // some tricky D-Bus mock setup.
       const accentColor = systemPreferences.getAccentColor();
