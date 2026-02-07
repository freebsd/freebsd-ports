--- src/core/OCIOYaml.cpp.orig	2019-03-28 05:12:57 UTC
+++ src/core/OCIOYaml.cpp
@@ -30,7 +30,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
 
 #include <OpenColorIO/OpenColorIO.h>
 
-#ifndef WIN32
+#ifdef OLDYAML
 
 // fwd declare yaml-cpp visibility
 #pragma GCC visibility push(hidden)
@@ -1442,7 +1442,7 @@ OCIO_NAMESPACE_ENTER
 #ifdef OLDYAML
             if(node.FindValue("ocio_profile_version") == NULL)
 #else
-            if(node["ocio_profile_version"] == NULL)
+            if(!node["ocio_profile_version"].IsDefined())
 #endif
             {
                 std::ostringstream os;
