--- lib/pdf/xpdf/gmem.c.orig	Wed Oct 11 02:54:28 2006
+++ lib/pdf/xpdf/gmem.c	Mon Jan 22 13:06:47 2007
@@ -47,9 +47,9 @@
 
 #endif /* DEBUG_MEM */
 
-void *gmalloc(int size) {
+void *gmalloc(size_t size) {
 #ifdef DEBUG_MEM
-  int size1;
+  size_t size1;
   char *mem;
   GMemHdr *hdr;
   void *data;
@@ -98,11 +98,11 @@
 #endif
 }
 
-void *grealloc(void *p, int size) {
+void *grealloc(void *p, size_t size) {
 #ifdef DEBUG_MEM
   GMemHdr *hdr;
   void *q;
-  int oldSize;
+  size_t oldSize;
 
   if (size <= 0) {
     if (p) {
@@ -142,8 +142,8 @@
 #endif
 }
 
-void *gmallocn(int nObjs, int objSize) {
-  int n;
+void *gmallocn(int nObjs, size_t objSize) {
+  size_t n;
 
   if (nObjs == 0) {
     return NULL;
@@ -156,8 +156,8 @@
   return gmalloc(n);
 }
 
-void *greallocn(void *p, int nObjs, int objSize) {
-  int n;
+void *greallocn(void *p, int nObjs, size_t objSize) {
+  size_t n;
 
   if (nObjs == 0) {
     if (p) {
