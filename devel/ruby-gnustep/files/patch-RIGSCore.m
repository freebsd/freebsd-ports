--- Source/RIGSCore.m.orig	Sat May 31 18:23:50 2003
+++ Source/RIGSCore.m	Sun Jun  1 16:57:00 2003
@@ -988,7 +988,7 @@
 (see below)
 */
 #ifdef GNUSTEP
-static MethodList_t class_nextMethodList( Class class, void ** iterator_ptr) 
+static MethodList_t rb_class_nextMethodList( Class class, void ** iterator_ptr) 
 {
   MethodList_t mlist;
   
@@ -1015,7 +1015,11 @@
 
   while(class) {
 
+#ifdef GNUSTEP
+    while( (mlist = rb_class_nextMethodList(class, &iterator)) != NULL) {
+#else
     while( (mlist = class_nextMethodList(class, &iterator)) != NULL) {
+#endif
       
           for(i = 0; i < mlist->method_count; i++) {
               SEL sel = mlist->method_list[i].method_name;
