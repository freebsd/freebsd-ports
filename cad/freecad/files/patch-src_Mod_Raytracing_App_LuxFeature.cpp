--- src/Mod/Raytracing/App/LuxFeature.cpp.orig	2019-10-04 10:45:53 UTC
+++ src/Mod/Raytracing/App/LuxFeature.cpp
@@ -88,23 +88,23 @@ App::DocumentObjectExecReturn *LuxFeature::execute(voi
     const App::Color& c = Color.getValue();
     long t = Transparency.getValue();
     if (t == 0) {
-        result << "MakeNamedMaterial \"FreeCADMaterial_" << Name << "\"" << endl
-               << "    \"color Kd\" [" << c.r << " " << c.g << " " << c.b << "]" << endl
-               << "    \"float sigma\" [0.000000000000000]" << endl
-               << "    \"string type\" [\"matte\"]" << endl << endl;
+        result << "MakeNamedMaterial \"FreeCADMaterial_" << Name << "\"" << std::endl
+               << "    \"color Kd\" [" << c.r << " " << c.g << " " << c.b << "]" << std::endl
+               << "    \"float sigma\" [0.000000000000000]" << std::endl
+               << "    \"string type\" [\"matte\"]" << std::endl << std::endl;
     } else {
         float trans = t/100.0f;
-        result << "MakeNamedMaterial \"FreeCADMaterial_Base_" << Name << "\"" << endl
-               << "    \"color Kd\" [" << c.r << " " << c.g << " " << c.b << "]" << endl
-               << "    \"float sigma\" [0.000000000000000]" << endl
-               << "    \"string type\" [\"matte\"]" << endl << endl
-               << "MakeNamedMaterial \"FreeCADMaterial_Null_" << Name << "\"" << endl
-               << "    \"string type\" [\"null\"]" << endl << endl
-               << "MakeNamedMaterial \"FreeCADMaterial_" << Name << "\"" << endl
-               << "    \"string namedmaterial1\" [\"FreeCADMaterial_Null_" << Name << "\"]" << endl
-               << "    \"string namedmaterial2\" [\"FreeCADMaterial_Base_" << Name << "\"]" << endl
-               << "    \"float amount\" [" << trans << "]" << endl
-               << "    \"string type\" [\"mix\"]" << endl << endl;
+        result << "MakeNamedMaterial \"FreeCADMaterial_Base_" << Name << "\"" << std::endl
+               << "    \"color Kd\" [" << c.r << " " << c.g << " " << c.b << "]" << std::endl
+               << "    \"float sigma\" [0.000000000000000]" << std::endl
+               << "    \"string type\" [\"matte\"]" << std::endl << std::endl
+               << "MakeNamedMaterial \"FreeCADMaterial_Null_" << Name << "\"" << std::endl
+               << "    \"string type\" [\"null\"]" << std::endl << std::endl
+               << "MakeNamedMaterial \"FreeCADMaterial_" << Name << "\"" << std::endl
+               << "    \"string namedmaterial1\" [\"FreeCADMaterial_Null_" << Name << "\"]" << std::endl
+               << "    \"string namedmaterial2\" [\"FreeCADMaterial_Base_" << Name << "\"]" << std::endl
+               << "    \"float amount\" [" << trans << "]" << std::endl
+               << "    \"string type\" [\"mix\"]" << std::endl << std::endl;
     }
     
     LuxTools::writeShape(result,Name.c_str(),shape);
