--- dselect/cxx-support.cc.orig	2016-11-13 10:53:33 UTC
+++ dselect/cxx-support.cc
@@ -79,7 +79,7 @@ operator delete[](void *a, size_t size) 
 {
 	free(a);
 }
-
+/*
 #ifdef HAVE___CXA_PURE_VIRTUAL
 extern "C" void
 abi::__cxa_pure_virtual()
@@ -87,3 +87,4 @@ abi::__cxa_pure_virtual()
 	internerr("pure virtual function called");
 }
 #endif
+*/
