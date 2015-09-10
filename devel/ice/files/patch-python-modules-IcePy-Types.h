--- python/modules/IcePy/Types.h.orig	2015-01-18 15:25:04.917707935 +0100
+++ python/modules/IcePy/Types.h	2015-01-18 15:24:54.689631935 +0100
@@ -69,6 +69,50 @@
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
@@ -127,7 +171,7 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0) = 0;
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*) = 0;
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*) = 0;
 };
 typedef IceUtil::Handle<TypeInfo> TypeInfoPtr;
 
@@ -164,7 +208,7 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     const Kind kind;
 };
@@ -193,7 +237,7 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     const std::string id;
     const PyObjectHandle pythonType;
@@ -240,7 +284,7 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -278,7 +322,7 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -338,7 +382,7 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -371,7 +415,7 @@
                            const Ice::StringSeq* = 0);
     virtual void unmarshaled(PyObject*, PyObject*, void*);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -420,11 +464,11 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
-    void printMembers(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    void printMembers(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     const std::string id;
     const Ice::Int compactId;
@@ -462,7 +506,7 @@
     virtual void unmarshal(const Ice::InputStreamPtr&, const UnmarshalCallbackPtr&, PyObject*, void*, bool,
                            const Ice::StringSeq* = 0);
 
-    virtual void print(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    virtual void print(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     virtual void destroy();
 
@@ -482,8 +526,8 @@
     void marshal(PyObject*, const Ice::OutputStreamPtr&, ObjectMap*);
     PyObject* unmarshal(const Ice::InputStreamPtr&);
 
-    void print(PyObject*, IceUtilInternal::Output&);
-    void printMembers(PyObject*, IceUtilInternal::Output&, PrintObjectHistory*);
+    void print(PyObject*, PrintHelper&);
+    void printMembers(PyObject*, PrintHelper&, PrintObjectHistory*);
 
     std::string id;
     bool preserve;
