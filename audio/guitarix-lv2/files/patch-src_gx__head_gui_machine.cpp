--- src/gx_head/gui/machine.cpp.orig	2018-07-22 05:47:48 UTC
+++ src/gx_head/gui/machine.cpp
@@ -18,7 +18,7 @@
 
 #include "guitarix.h"
 #include <sys/mman.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "jsonrpc_methods.h"
 #include <netinet/in.h>
 #include <netinet/tcp.h>
@@ -31,7 +31,7 @@
 #endif
 
 void lock_rt_memory() {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
     extern char __rt_text__start[], __rt_text__end[];
     extern char __rt_data__start[], __rt_data__end[];
     struct {
