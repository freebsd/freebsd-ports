--- vcl/inc/unx/gtk/gtkinst.hxx.orig	2016-10-28 14:50:26 UTC
+++ vcl/inc/unx/gtk/gtkinst.hxx
@@ -46,7 +46,7 @@ class GtkPrintWrapper;
 class GenPspGraphics;
 class GtkYieldMutex : public SalYieldMutex
 {
-    thread_local static std::stack<sal_uIntPtr> yieldCounts;
+    std::list<sal_uLong> aYieldStack;
 
 public:
          GtkYieldMutex() {}
