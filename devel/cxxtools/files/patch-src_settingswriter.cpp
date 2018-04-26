Regressed by https://reviews.llvm.org/rL297872

In file included from settingswriter.cpp:28:
In file included from ./settingswriter.h:31:
In file included from ../include/cxxtools/char.h:32:
In file included from /usr/include/c++/v1/string:477:
/usr/include/c++/v1/string_view:211:5: error: static_assert failed due to requirement 'is_pod<value_type>::value' "Character type of basic_string_view must be a POD"
    static_assert(is_pod<value_type>::value, "Character type of basic_string_view must be a POD");
    ^             ~~~~~~~~~~~~~~~~~~~~~~~~~
settingswriter.cpp:42:21: note: in instantiation of template class 'std::__1::basic_string_view<cxxtools::Char, std::__1::char_traits<cxxtools::Char> >' requested here
            *_os << std::endl;
                    ^

--- src/settingswriter.cpp.orig	2013-12-26 09:33:48 UTC
+++ src/settingswriter.cpp
@@ -39,7 +39,7 @@ void SettingsWriter::write(const cxxtools::Serializati
             String value;
             it->getValue(value);
             this->writeEntry( it->name(), value, it->typeName() );
-            *_os << std::endl;
+            *_os << cxxtools::String(L"\n");
         }
         else if( it->category() == cxxtools::SerializationInfo::Object)
         {
@@ -49,7 +49,7 @@ void SettingsWriter::write(const cxxtools::Serializati
                 *_os << cxxtools::String::widen( it->name() ) << cxxtools::String(L" = ");
                 *_os << cxxtools::String::widen( it->typeName() ) << cxxtools::String(L"{ ");
                 this->writeParent( *it, "");
-                *_os << cxxtools::String(L" }") << std::endl;
+                *_os << cxxtools::String(L" }") << cxxtools::String(L"\n");
                 continue;
             }
 
@@ -71,14 +71,14 @@ void SettingsWriter::writeParent(const cxxtools::Seria
             String value;
             it->getValue(value);
             this->writeEntry( it->name(), value, it->typeName() );
-            *_os << std::endl;
+            *_os << cxxtools::String(L"\n");
         }
         else if( it->category() == cxxtools::SerializationInfo::Object )
         {
             *_os << cxxtools::String::widen( prefix ) << '.' << cxxtools::String::widen( it->name() ) << cxxtools::String(L" = ");
             *_os<< cxxtools::String::widen( it->typeName() ) << cxxtools::String(L"{ ");
             this->writeChild(*it);
-            *_os << cxxtools::String(L" }") << std::endl;
+            *_os << cxxtools::String(L" }") << cxxtools::String(L"\n");
         }
     }
 }
@@ -157,7 +157,7 @@ void SettingsWriter::writeEntry(const std::string& nam
 
 void SettingsWriter::writeSection(const cxxtools::String& prefix)
 {
-    *_os << cxxtools::String(L"[") << prefix << cxxtools::String(L"]") << std::endl;
+    *_os << cxxtools::String(L"[") << prefix << cxxtools::String(L"]") << cxxtools::String(L"\n");
 }
 
 }
