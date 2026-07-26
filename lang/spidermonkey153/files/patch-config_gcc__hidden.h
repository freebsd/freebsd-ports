Toggle symbol visibility, otherwise certain symbols are marked as local
which are actually supposed to be used (e.g. by gjs):

void js::UnsafeTraceManuallyBarrieredEdge<jsid>(JSTracer*, jsid*, char const*)
void JS::TraceEdge<JSObject*>(JSTracer*, JS::Heap<JSObject*>*, char const*)
void js::UnsafeTraceManuallyBarrieredEdge<JSObject*>(JSTracer*, JSObject**, char const*)
void js::UnsafeTraceManuallyBarrieredEdge<JS::Value>(JSTracer*, JS::Value*, char const*)

Index: config/gcc_hidden.h
--- config/gcc_hidden.h.orig	2022-03-30 19:25:29 UTC
+++ config/gcc_hidden.h
@@ -3,4 +3,4 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 /* Begin all files as hidden visibility */
-#pragma GCC visibility push(hidden)
+#pragma GCC visibility push(default)
