--- src/py/partio.i.orig	2025-01-28 22:44:08 UTC
+++ src/py/partio.i
@@ -638,7 +638,9 @@ ParticlesDataMutable* cloneSchema(const ParticlesData&
 
 %feature("autodoc");
 %feature("docstring","Clone a particle set");
-ParticlesDataMutable* clone(const ParticlesData& other, bool particles, const std::map<std::string, std::string>* attrNameMap=nullptr);
+ParticlesDataMutable* clone(const ParticlesData& other, bool particles=true, const std::map<std::string, std::string>* attrNameMap=nullptr);
+
+%typedef std::map<std::string, std::string> _dummy; /* https://github.com/wdas/partio/issues/114 */
 
 %feature("autodoc");
 %feature("docstring","Return string name of given attribute type");
