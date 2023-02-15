--- lib/external/pattern_language/lib/include/pl/patterns/pattern.hpp.orig	2023-02-15 14:19:06 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern.hpp
@@ -317,7 +317,7 @@ namespace pl::ptrn {
                         auto startOffset = child->getOffset();
 
                         child->setOffset(offset);
-                        PL_ON_SCOPE_EXIT { child->setOffset(startOffset); };
+                        [[maybe_unused]] auto PL_ANONYMOUS_VARIABLE(SCOPE_EXIT_) = ::pl::scope_guard::ScopeGuardOnExit() + [&, child=child]() { child->setOffset(startOffset); };
 
                         auto bytes = child->getBytes();
                         std::copy(bytes.begin(), bytes.end(), std::back_inserter(result));
