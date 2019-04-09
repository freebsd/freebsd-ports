--- src/gx_head/gui/machine.cpp.orig	2019-04-07 05:17:18 UTC
+++ src/gx_head/gui/machine.cpp
@@ -46,7 +46,7 @@ void set_memory_allocation() {}
 #endif
 
 void lock_rt_memory() {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
     extern char __rt_text__start[], __rt_text__end[];
     extern char __rt_data__start[], __rt_data__end[];
     struct {
