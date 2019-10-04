--- src/Mod/Raytracing/App/AppRaytracingPy.cpp.orig	2019-10-04 10:44:17 UTC
+++ src/Mod/Raytracing/App/AppRaytracingPy.cpp
@@ -105,13 +105,13 @@ class Module : public Py::ExtensionModule<Module> (pri
 
         PovTools::writeShape(out,PartName,aShape,(float)0.1);
         // This must not be done in PovTools::writeShape!
-        out << "// instance to render" << endl
-            << "object {" << PartName << endl
-            << "  texture {" << endl
-            << "      pigment {color rgb <"<<r<<","<<g<<","<<b<<">}" << endl
-            << "      finish {StdFinish } //definition on top of the project" << endl
-            << "  }" << endl
-            << "}" << endl   ;
+        out << "// instance to render" << std::endl
+            << "object {" << PartName << std::endl
+            << "  texture {" << std::endl
+            << "      pigment {color rgb <"<<r<<","<<g<<","<<b<<">}" << std::endl
+            << "      finish {StdFinish } //definition on top of the project" << std::endl
+            << "  }" << std::endl
+            << "}" << std::endl   ;
         return Py::String(out.str());
     }
     Py::Object getPartAsLux(const Py::Tuple& args)
@@ -128,10 +128,10 @@ class Module : public Py::ExtensionModule<Module> (pri
 
         // write a material entry
         // This must not be done in PovTools::writeShape!
-        out << "MakeNamedMaterial \"FreeCADMaterial_" << PartName << "\"" << endl;
-        out << "    \"color Kd\" [" << r << " " << g << " " << b << "]" << endl;
-        out << "    \"float sigma\" [0.000000000000000]" << endl;
-        out << "    \"string type\" [\"matte\"]" << endl << endl;
+        out << "MakeNamedMaterial \"FreeCADMaterial_" << PartName << "\"" << std::endl;
+        out << "    \"color Kd\" [" << r << " " << g << " " << b << "]" << std::endl;
+        out << "    \"float sigma\" [0.000000000000000]" << std::endl;
+        out << "    \"string type\" [\"matte\"]" << std::endl << std::endl;
 
         LuxTools::writeShape(out,PartName,aShape,(float)0.1);
         return Py::String(out.str());
