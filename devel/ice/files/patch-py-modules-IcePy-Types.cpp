--- py/modules/IcePy/Types.cpp.orig	2015-01-18 15:25:00.277654935 +0100
+++ py/modules/IcePy/Types.cpp	2015-01-18 15:24:52.737609935 +0100
@@ -915,7 +915,7 @@
 }
 
 void
-IcePy::PrimitiveInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory*)
+IcePy::PrimitiveInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory*)
 {
     if(!validate(value))
     {
@@ -1050,7 +1050,7 @@
 }
 
 void
-IcePy::EnumInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory*)
+IcePy::EnumInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory*)
 {
     if(!validate(value))
     {
@@ -1232,11 +1232,15 @@
 {
     assert(PyObject_IsInstance(p, pythonType.get()) == 1); // validate() should have caught this.
 
+    int sizePos = -1;
     if(optional)
     {
         if(_variableLength)
         {
-            os->startSize();
+            // BUGFIX: #5481 startSize/endSize can't be nested
+            //os->startSize();
+            sizePos = os->pos();
+            os->write(Ice::Int(0));
         }
         else
         {
@@ -1266,7 +1270,9 @@
 
     if(optional && _variableLength)
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
@@ -1305,7 +1311,7 @@
 }
 
 void
-IcePy::StructInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::StructInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -1402,11 +1408,15 @@
 {
     PrimitiveInfoPtr pi = PrimitiveInfoPtr::dynamicCast(elementType);
 
+    int sizePos = -1;
     if(optional)
     {
         if(elementType->variableLength())
         {
-            os->startSize();
+            // BUGFIX: #5481 startSize/endSize can't be nested
+            //os->startSize();
+            sizePos = os->pos();
+            os->write(Ice::Int(0));
         }
         else if(elementType->wireSize() > 1)
         {
@@ -1490,7 +1500,9 @@
 
     if(optional && elementType->variableLength())
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
@@ -1559,7 +1571,7 @@
 }
 
 void
-IcePy::SequenceInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::SequenceInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2397,7 +2409,7 @@
 }
 
 void
-IcePy::CustomInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::CustomInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2480,11 +2492,15 @@
 
     const Ice::Int sz = p == Py_None ? 0 : static_cast<Ice::Int>(PyDict_Size(p));
 
+    int sizePos = -1;
     if(optional)
     {
         if(_variableLength)
         {
-            os->startSize();
+            // BUGFIX: #5481 startSize/endSize can't be nested
+            //os->startSize();
+            sizePos = os->pos();
+            os->write(Ice::Int(0));
         }
         else
         {
@@ -2523,7 +2539,9 @@
 
     if(optional && _variableLength)
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
@@ -2597,7 +2615,7 @@
 }
 
 void
-IcePy::DictionaryInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::DictionaryInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2798,7 +2816,7 @@
 }
 
 void
-IcePy::ClassInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::ClassInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2863,7 +2881,7 @@
 }
 
 void
-IcePy::ClassInfo::printMembers(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::ClassInfo::printMembers(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(base)
     {
@@ -2958,9 +2976,13 @@
 void
 IcePy::ProxyInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, ObjectMap*, bool optional, const Ice::StringSeq*)
 {
+    int sizePos = -1;
     if(optional)
     {
-        os->startSize();
+        // BUGFIX: #5481 startSize/endSize can't be nested
+        //os->startSize();
+        sizePos = os->pos();
+        os->write(Ice::Int(0));
     }
 
     if(p == Py_None)
@@ -2978,7 +3000,9 @@
 
     if(optional)
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
@@ -3011,7 +3035,7 @@
 }
 
 void
-IcePy::ProxyInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory*)
+IcePy::ProxyInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory*)
 {
     if(!validate(value))
     {
@@ -3463,7 +3487,7 @@
 }
 
 void
-IcePy::ExceptionInfo::print(PyObject* value, IceUtilInternal::Output& out)
+IcePy::ExceptionInfo::print(PyObject* value, PrintHelper& out)
 {
     if(!PyObject_IsInstance(value, pythonType.get()))
     {
@@ -3481,7 +3505,7 @@
 }
 
 void
-IcePy::ExceptionInfo::printMembers(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::ExceptionInfo::printMembers(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(base)
     {
@@ -4209,7 +4233,7 @@
     assert(info);
 
     ostringstream ostr;
-    IceUtilInternal::Output out(ostr);
+    PrintHelper out(ostr);
     PrintObjectHistory history;
     history.index = 0;
     info->print(value, out, &history);
@@ -4234,7 +4258,7 @@
     assert(info);
 
     ostringstream ostr;
-    IceUtilInternal::Output out(ostr);
+    PrintHelper out(ostr);
     info->print(value, out);
 
     string str = ostr.str();
