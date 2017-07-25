--- simgear/scene/material/Effect.cxx.orig	2017-04-04 09:24:44.000000000 +0200
+++ simgear/scene/material/Effect.cxx	2017-07-16 21:55:10.888904000 +0200
@@ -32,7 +32,7 @@
 #include <map>
 #include <queue>
 #include <utility>
-#include <boost/tr1/unordered_map.hpp>
+#include <unordered_map>
 
 #include <boost/bind.hpp>
 #include <boost/foreach.hpp>
@@ -832,13 +832,13 @@
 
 // XXX Should these be protected by a mutex? Probably
 
-typedef tr1::unordered_map<ProgramKey, ref_ptr<Program>,
+typedef std::unordered_map<ProgramKey, ref_ptr<Program>,
                            boost::hash<ProgramKey>, ProgramKey::EqualTo>
 ProgramMap;
 ProgramMap programMap;
 ProgramMap resolvedProgramMap;  // map with resolved shader file names
 
-typedef tr1::unordered_map<ShaderKey, ref_ptr<Shader>, boost::hash<ShaderKey> >
+typedef std::unordered_map<ShaderKey, ref_ptr<Shader>, boost::hash<ShaderKey> >
 ShaderMap;
 ShaderMap shaderMap;
 
