--- lib/external/pattern_language/lib/include/pl/patterns/pattern.hpp.orig	2023-04-08 16:10:41 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern.hpp
@@ -336,7 +336,7 @@ namespace pl::ptrn {
                         auto startOffset = child->getOffset();
 
                         child->setOffset(offset);
-                        ON_SCOPE_EXIT { child->setOffset(startOffset); };
+                        [[maybe_unused]] auto WOLV_ANONYMOUS_VARIABLE(SCOPE_EXIT_) = ::wolv::util::scope_guard::ScopeGuardOnExit() + [&, child=child]() { child->setOffset(startOffset); };
 
                         auto bytes = child->getBytes();
                         std::copy(bytes.begin(), bytes.end(), std::back_inserter(result));
