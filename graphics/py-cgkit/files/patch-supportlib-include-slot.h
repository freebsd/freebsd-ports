--- supportlib/include/slot.h.orig	2011-01-20 12:26:58.000000000 +0100
+++ supportlib/include/slot.h	2011-01-20 12:29:40.000000000 +0100
@@ -729,7 +729,7 @@
 template<class T>
 void Slot<T>::setController(ISlot* ctrl)
 {
-  DEBUGINFO1(this, "Slot<T>::setController(0x%x)", (unsigned int)(ctrl));
+  DEBUGINFO1(this, "Slot<T>::setController(0x%x)", (uintptr_t)(ctrl));
   // Check if this slot can take input connections (but allow setting 0
   // as this can happen during destruction)
   if ((flags & NO_INPUT_CONNECTIONS) && ctrl!=0)
@@ -738,7 +738,7 @@
   // If the new and old controller are the same, then there's nothing to do
   if (controller==ctrl)
   {
-    DEBUGINFO1(this, "Slot<T>::setController(0x%x) --- end  (new==old)", (unsigned int)(ctrl));
+    DEBUGINFO1(this, "Slot<T>::setController(0x%x) --- end  (new==old)", (uintptr_t)(ctrl));
     return;
   }
 
@@ -774,13 +774,13 @@
     ctrl->addDependent(this);
     notifyDependents();
   }
-  DEBUGINFO1(this, "Slot<T>::setController(0x%x) --- end", (unsigned int)(ctrl));
+  DEBUGINFO1(this, "Slot<T>::setController(0x%x) --- end", (uintptr_t)(ctrl));
 }
 
 template<class T>
 void Slot<T>::addDependent(Dependent* d)
 {
-  DEBUGINFO1(this, "Slot<T>::addDependent(0x%x)", (int)d);
+  DEBUGINFO1(this, "Slot<T>::addDependent(0x%x)", (intptr_t)d);
 
   // Do nothing if the dependent was already added before
   if (std::find(dependents.begin(), dependents.end(), d)!=dependents.end())
@@ -793,7 +793,7 @@
 template<class T>
 void Slot<T>::removeDependent(Dependent* d)
 {
-  DEBUGINFO1(this, "Slot<T>::removeDependent(0x%x)", (int)d);
+  DEBUGINFO1(this, "Slot<T>::removeDependent(0x%x)", (intptr_t)d);
 
   // Remove the element (it is moved to the back)
   std::vector<Dependent*>::iterator res = std::remove(dependents.begin(), dependents.end(), d);
