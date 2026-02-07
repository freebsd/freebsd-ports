--- python/modules/IcePy/Types.cpp.orig	2019-08-12 19:54:18 UTC
+++ python/modules/IcePy/Types.cpp
@@ -994,7 +994,7 @@ IcePy::PrimitiveInfo::unmarshal(const Ice::InputStream
 }
 
 void
-IcePy::PrimitiveInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory*)
+IcePy::PrimitiveInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory*)
 {
     if(!validate(value))
     {
@@ -1108,7 +1108,7 @@ IcePy::EnumInfo::unmarshal(const Ice::InputStreamPtr& 
 }
 
 void
-IcePy::EnumInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory*)
+IcePy::EnumInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory*)
 {
     if(!validate(value))
     {
@@ -1421,7 +1421,7 @@ IcePy::StructInfo::unmarshal(const Ice::InputStreamPtr
 }
 
 void
-IcePy::StructInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::StructInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -1689,7 +1689,7 @@ IcePy::SequenceInfo::unmarshal(const Ice::InputStreamP
 }
 
 void
-IcePy::SequenceInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::SequenceInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2523,7 +2523,7 @@ IcePy::CustomInfo::unmarshal(const Ice::InputStreamPtr
 }
 
 void
-IcePy::CustomInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::CustomInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2719,7 +2719,7 @@ IcePy::DictionaryInfo::unmarshaled(PyObject* val, PyOb
 }
 
 void
-IcePy::DictionaryInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::DictionaryInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2911,7 +2911,7 @@ IcePy::ClassInfo::unmarshal(const Ice::InputStreamPtr&
 }
 
 void
-IcePy::ClassInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::ClassInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(!validate(value))
     {
@@ -2967,7 +2967,7 @@ IcePy::ClassInfo::destroy()
 }
 
 void
-IcePy::ClassInfo::printMembers(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::ClassInfo::printMembers(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(base)
     {
@@ -3115,7 +3115,7 @@ IcePy::ProxyInfo::unmarshal(const Ice::InputStreamPtr&
 }
 
 void
-IcePy::ProxyInfo::print(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory*)
+IcePy::ProxyInfo::print(PyObject* value, PrintHelper& out, PrintObjectHistory*)
 {
     if(!validate(value))
     {
@@ -3540,7 +3540,7 @@ IcePy::ExceptionInfo::unmarshal(const Ice::InputStream
 }
 
 void
-IcePy::ExceptionInfo::print(PyObject* value, IceUtilInternal::Output& out)
+IcePy::ExceptionInfo::print(PyObject* value, PrintHelper& out)
 {
     if(!PyObject_IsInstance(value, pythonType))
     {
@@ -3558,7 +3558,7 @@ IcePy::ExceptionInfo::print(PyObject* value, IceUtilIn
 }
 
 void
-IcePy::ExceptionInfo::printMembers(PyObject* value, IceUtilInternal::Output& out, PrintObjectHistory* history)
+IcePy::ExceptionInfo::printMembers(PyObject* value, PrintHelper& out, PrintObjectHistory* history)
 {
     if(base)
     {
@@ -4372,7 +4372,7 @@ IcePy_stringify(PyObject*, PyObject* args)
     assert(info);
 
     ostringstream ostr;
-    IceUtilInternal::Output out(ostr);
+    PrintHelper out(ostr);
     PrintObjectHistory history;
     history.index = 0;
     info->print(value, out, &history);
@@ -4397,7 +4397,7 @@ IcePy_stringifyException(PyObject*, PyObject* args)
     assert(info);
 
     ostringstream ostr;
-    IceUtilInternal::Output out(ostr);
+    PrintHelper out(ostr);
     info->print(value, out);
 
     string str = ostr.str();
