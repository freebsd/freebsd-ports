--- py/modules/IcePy/Types.cpp.orig	2013-03-11 15:19:47.000000000 +0000
+++ py/modules/IcePy/Types.cpp	2014-09-08 14:21:13.335195726 +0000
@@ -1232,11 +1232,15 @@ IcePy::StructInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, ObjectMa
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
@@ -1266,7 +1270,9 @@ IcePy::StructInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, ObjectMa
 
     if(optional && _variableLength)
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
@@ -1402,11 +1408,15 @@ IcePy::SequenceInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, Object
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
@@ -1490,7 +1500,9 @@ IcePy::SequenceInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, Object
 
     if(optional && elementType->variableLength())
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
@@ -2480,11 +2492,15 @@ IcePy::DictionaryInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, Obje
 
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
@@ -2523,7 +2539,9 @@ IcePy::DictionaryInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, Obje
 
     if(optional && _variableLength)
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
@@ -2958,9 +2976,13 @@ IcePy::ProxyInfo::optionalFormat() const
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
@@ -2978,7 +3000,9 @@ IcePy::ProxyInfo::marshal(PyObject* p, const Ice::OutputStreamPtr& os, ObjectMap
 
     if(optional)
     {
-        os->endSize();
+        assert(sizePos != -1);
+        //os->endSize();
+        os->rewrite(os->pos() - sizePos - 4, sizePos);
     }
 }
 
