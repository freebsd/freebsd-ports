--- electron/spec/api-screen.spec.ts.orig	2026-10-15 23:46:52 UTC
+++ electron/spec/api-screen.spec.ts
@@ -97,7 +97,7 @@ describe('screen module', { tags: ['serial'] }, () => 
 
       const { size } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         expect(size).toHaveProperty('width', expect.any(Number));
         expect(size).toHaveProperty('height', expect.any(Number));
       } else {
@@ -113,7 +113,7 @@ describe('screen module', { tags: ['serial'] }, () => 
 
       const { workAreaSize } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         expect(workAreaSize).toHaveProperty('width', expect.any(Number));
         expect(workAreaSize).toHaveProperty('height', expect.any(Number));
       } else {
@@ -131,7 +131,7 @@ describe('screen module', { tags: ['serial'] }, () => 
       expect(bounds).toHaveProperty('x', expect.any(Number));
       expect(bounds).toHaveProperty('y', expect.any(Number));
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         expect(bounds).toHaveProperty('width', expect.any(Number));
         expect(bounds).toHaveProperty('height', expect.any(Number));
       } else {
