--- source/tools/data_entry.hh.orig	Fri Sep 17 16:43:13 2004
+++ source/tools/data_entry.hh	Fri Sep 17 16:45:30 2004
@@ -94,19 +94,19 @@
       DataSet(_funS), DataCompare(_funC) { ; }
 
   bool Print(std::ostream & fp) const {
-    if (target == NULL) return false;
-    fp << (target->*DataRetrieval)();
+    if (this->target == NULL) return false;
+    fp << (this->target->*DataRetrieval)();
     return true;
   }
 
   //int Compare(T * other) const { return (target->*DataCompare)(other); }
   int Compare(T * other) const {
-    return (DataCompare)?((target->*DataCompare)(other)):(0);
+    return (DataCompare)?((this->target->*DataCompare)(other)):(0);
   }
   bool Set(const cString & value) {
     OUT new_value(0);
     if (DataSet == 0) return false;
-    (target->*DataSet)( cStringUtil::Convert(value, new_value) );
+    (this->target->*DataSet)( cStringUtil::Convert(value, new_value) );
     return true;
   }
 };
@@ -128,14 +128,14 @@
       DataRetrieval(_funR), DataCompare(_funC), arg(_arg) { ; }
 
   bool Print(std::ostream & fp) const {
-    if (target == NULL) return false;
-    fp << (target->*DataRetrieval)(arg);
+    if (this->target == NULL) return false;
+    fp << (this->target->*DataRetrieval)(arg);
     return true;
   }
 
   //int Compare(T * other) const { return (target->*DataCompare)(other, arg); }
   int Compare(T * other) const {
-    return (DataCompare)?((target->*DataCompare)(other, arg)):(0);
+    return (DataCompare)?((this->target->*DataCompare)(other, arg)):(0);
   }
 };
 
