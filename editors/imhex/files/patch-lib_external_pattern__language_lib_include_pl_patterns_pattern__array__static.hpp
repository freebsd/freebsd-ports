--- lib/external/pattern_language/lib/include/pl/patterns/pattern_array_static.hpp.orig	2022-07-17 13:30:19 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_array_static.hpp
@@ -51,7 +51,7 @@ namespace pl {
             return result;
         }
 
-        virtual void setMemoryLocationType(PatternMemoryType type) {
+        void setMemoryLocationType(PatternMemoryType type) override {
             if (this->m_template != nullptr)
                 this->m_template->setMemoryLocationType(type);
 
