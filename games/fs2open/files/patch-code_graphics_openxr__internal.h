--- code/graphics/openxr_internal.h.orig	2025-11-04 13:00:12 UTC
+++ code/graphics/openxr_internal.h
@@ -7,7 +7,7 @@
 #include <type_traits>
 #include <tl/optional.hpp>
 
-#ifndef __APPLE_CC__
+#if !defined(__APPLE_CC__) && !defined(__FreeBSD__)
 
 #include <openxr/openxr.h>
 #include <openxr/openxr_platform.h>
@@ -51,4 +51,4 @@ tl::optional<typename std::result_of<openxr_fnc(arg_t.
 	return func(std::forward<arg_t>(args)...);
 }
 
-#endif
\ No newline at end of file
+#endif
