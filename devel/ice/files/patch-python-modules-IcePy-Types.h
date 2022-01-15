--- python/modules/IcePy/Types.h.orig	2019-08-12 19:54:18 UTC
+++ python/modules/IcePy/Types.h
@@ -71,6 +71,50 @@ struct PrintObjectHistory
     std::map<PyObject*, int> objects;
 };
 
+struct PrintHelper
+{
+    std::ostream& os;
+    Ice::Long indent;
+
+    PrintHelper(std::ostream& o): os(o), indent(0) {}
+    void newline()
+    {
+        os << "\n" << std::string(indent * 4, ' ');
+        os.flush();
+    }
+
+    void sb()
+    {
+        newline();
+        os << "{";
+        ++indent;
+    }
+
+    void eb()
+    {
+        --indent;
+        newline();
+        os << "}";
+    }
+};
+
+template<typename T>
+inline PrintHelper&
+operator<<(PrintHelper& ph, const T& val)
+{
+  ph.os << val;
+  return ph;
+}
+
+template<>
+inline PrintHelper&
+operator<<(PrintHelper& ph, const IceUtilInternal::NextLine&)
+{
+    ph.newline();
+    return ph;
+}
+
+
 //
 // The delayed nature of class unmarshaling in the Ice protocol requires us to
 // handle unmarshaling using a callback strategy. An instance of UnmarshalCallback
@@ -129,7 +173,7 @@ class TypeInfo : public UnmarshalCallback (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0) = 0;
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*) = 0;
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*) = 0;
 };
 typedef IceUtil::Handle<TypeInfo> TypeInfoPtr;
 
@@ -166,7 +210,7 @@ class PrimitiveInfo : public TypeInfo (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     const Kind kind;
 };
@@ -195,7 +239,7 @@ class EnumInfo : public TypeInfo (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -247,7 +291,7 @@ class StructInfo : public TypeInfo (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -288,7 +332,7 @@ class SequenceInfo : public TypeInfo (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -348,7 +392,7 @@ class CustomInfo : public TypeInfo (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     const std::string id;
     PyObject* pythonType; // Borrowed reference - the enclosing Python module owns the reference.
@@ -379,7 +423,7 @@ class DictionaryInfo : public TypeInfo (public)
                            const Ice::StringSeq* = 0);
     virtual void unmarshaled(PyObject*, PyObject*, void*);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -428,11 +472,11 @@ class ClassInfo : public TypeInfo (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
-    void printMembers(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    void printMembers(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     const std::string id;
     const Ice::Int compactId;
@@ -470,7 +514,7 @@ class ProxyInfo : public TypeInfo (public)
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     const std::string id;
     PyObject* pythonType; // Borrowed reference - the enclosing Python module owns the reference.
@@ -488,8 +532,8 @@ class ExceptionInfo : public IceUtil::Shared (public)
     void marshal(PyObject*, const Ice::OutputStreamPtr&, ObjectMap*);
     PyObject* unmarshal(const Ice::InputStreamPtr&);
 
-    void print(PyObject*, IceUtilInternal::Output&);
-    void printMembers(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    void print(PyObject*, PrintHelper&);
+    void printMembers(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     std::string id;
     bool preserve;
