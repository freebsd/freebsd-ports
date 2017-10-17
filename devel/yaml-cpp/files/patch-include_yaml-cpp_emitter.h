--- include/yaml-cpp/emitter.h.orig	2016-01-10 18:11:40 UTC
+++ include/yaml-cpp/emitter.h
@@ -122,7 +122,7 @@ class YAML_CPP_API Emitter : private non
   bool CanEmitNewline() const;
 
  private:
-  std::auto_ptr<EmitterState> m_pState;
+  std::unique_ptr<EmitterState> m_pState;
   ostream_wrapper m_stream;
 };
 
