--- hotspot/src/share/vm/interpreter/bytecodeInterpreter.cpp.orig
+++ hotspot/src/share/vm/interpreter/bytecodeInterpreter.cpp
@@ -2569,13 +2569,35 @@ run:
 
         // this could definitely be cleaned up QQQ
         Method* callee;
-        Klass* iclass = cache->f1_as_klass();
-        // InstanceKlass* interface = (InstanceKlass*) iclass;
+        Method *interface_method = cache->f2_as_interface_method();
+        InstanceKlass* iclass = interface_method->method_holder();
+
         // get receiver
         int parms = cache->parameter_size();
         oop rcvr = STACK_OBJECT(-parms);
         CHECK_NULL(rcvr);
         InstanceKlass* int2 = (InstanceKlass*) rcvr->klass();
+
+        // Receiver subtype check against resolved interface klass (REFC).
+        {
+          Klass* refc = cache->f1_as_klass();
+          itableOffsetEntry* scan;
+          for (scan = (itableOffsetEntry*) int2->start_of_itable();
+               scan->interface_klass() != NULL;
+               scan++) {
+            if (scan->interface_klass() == refc) {
+              break;
+            }
+          }
+          // Check that the entry is non-null.  A null entry means
+          // that the receiver class doesn't implement the
+          // interface, and wasn't the same as when the caller was
+          // compiled.
+          if (scan->interface_klass() == NULL) {
+            VM_JAVA_ERROR(vmSymbols::java_lang_IncompatibleClassChangeError(), "", note_no_trap);
+          }
+        }
+
         itableOffsetEntry* ki = (itableOffsetEntry*) int2->start_of_itable();
         int i;
         for ( i = 0 ; i < int2->itable_length() ; i++, ki++ ) {
@@ -2587,7 +2609,8 @@ run:
         if (i == int2->itable_length()) {
           VM_JAVA_ERROR(vmSymbols::java_lang_IncompatibleClassChangeError(), "", note_no_trap);
         }
-        int mindex = cache->f2_as_index();
+        int mindex = interface_method->itable_index();
+
         itableMethodEntry* im = ki->first_method_entry(rcvr->klass());
         callee = im[mindex].method();
         if (callee == NULL) {
