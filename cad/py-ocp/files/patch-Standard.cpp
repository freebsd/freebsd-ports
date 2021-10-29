--- Standard.cpp.orig	2020-05-29 13:26:32 UTC
+++ Standard.cpp
@@ -902,10 +902,10 @@ py::module m = static_cast<py::module>(main_module.att
           R"#(None)#"  , py::arg("theOne"),  py::arg("theTwo")
           );
 // ./opencascade/Standard_Time.hxx
-    m.def("IsEqual",
-          (Standard_Boolean (*)( const Standard_Time ,  const Standard_Time  ))  static_cast<Standard_Boolean (*)( const Standard_Time ,  const Standard_Time  )>(&IsEqual),
-          R"#(None)#"  , py::arg("theOne"),  py::arg("theTwo")
-          );
+//    m.def("IsEqual",
+//          (Standard_Boolean (*)( const Standard_Time ,  const Standard_Time  ))  static_cast<Standard_Boolean (*)( const Standard_Time ,  const Standard_Time  )>(&IsEqual),
+//          R"#(None)#"  , py::arg("theOne"),  py::arg("theTwo")
+//          );
 // ./opencascade/Standard_NullValue.hxx
 // ./opencascade/Standard_DefineHandle.hxx
 // ./opencascade/Standard_Mutex.hxx
