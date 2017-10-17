--- include/yaml-cpp/parser.h.orig	2016-01-10 18:11:40 UTC
+++ include/yaml-cpp/parser.h
@@ -40,8 +40,8 @@ class YAML_CPP_API Parser : private nonc
   void HandleTagDirective(const Token& token);
 
  private:
-  std::auto_ptr<Scanner> m_pScanner;
-  std::auto_ptr<Directives> m_pDirectives;
+  std::unique_ptr<Scanner> m_pScanner;
+  std::unique_ptr<Directives> m_pDirectives;
 };
 }
 
