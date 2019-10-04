--- src/Mod/Raytracing/App/RayFeature.cpp.orig	2019-10-04 10:45:11 UTC
+++ src/Mod/Raytracing/App/RayFeature.cpp
@@ -81,19 +81,19 @@ App::DocumentObjectExecReturn *RayFeature::execute(voi
     // This must not be done in PovTools::writeShape!
     long t = Transparency.getValue();
     const App::Color& c = Color.getValue();
-    result << "// instance to render" << endl
-           << "object {" << Name << endl
-           << " texture {" << endl;
+    result << "// instance to render" << std::endl
+           << "object {" << Name << std::endl
+           << " texture {" << std::endl;
     if (t == 0) {
-        result << "      pigment {color rgb <"<<c.r<<","<<c.g<<","<<c.b<<">}" << endl;
+        result << "      pigment {color rgb <"<<c.r<<","<<c.g<<","<<c.b<<">}" << std::endl;
     }
     else {
         float trans = t/100.0f;
-        result << "      pigment {color rgb <"<<c.r<<","<<c.g<<","<<c.b<<"> transmit "<<trans<<"}" << endl;
+        result << "      pigment {color rgb <"<<c.r<<","<<c.g<<","<<c.b<<"> transmit "<<trans<<"}" << std::endl;
     }
-    result << "      finish {StdFinish } //definition on top of the project" << endl
-           << "  }" << endl
-           << "}" << endl   ;
+    result << "      finish {StdFinish } //definition on top of the project" << std::endl
+           << "  }" << std::endl
+           << "}" << std::endl   ;
 
     // Apply the resulting fragment
     Result.setValue(result.str().c_str());
