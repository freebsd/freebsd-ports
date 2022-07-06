--- lib/external/pattern_language/lib/include/pl/patterns/pattern_array_static.hpp.orig	2022-07-05 14:38:01 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_array_static.hpp
@@ -48,7 +48,7 @@ namespace pl {
             return result;
         }
 
-        virtual void setMemoryLocationType(PatternMemoryType type) {
+        void setMemoryLocationType(PatternMemoryType type) override {
             if (this->m_template != nullptr)
                 this->m_template->setMemoryLocationType(type);
 
