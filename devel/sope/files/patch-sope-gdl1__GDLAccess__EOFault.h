--- sope-gdl1/GDLAccess/EOFault.h.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EOFault.h
@@ -9,6 +9,9 @@
 
 @class EOFaultHandler;
 
+#ifdef __clang__
+__attribute__((objc_root_class))
+#endif
 @interface EOFault
 {
   Class          isa;
