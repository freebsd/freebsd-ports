--- extern/sol3/sol/optional_implementation.hpp.orig	2023-08-08 09:23:20 UTC
+++ extern/sol3/sol/optional_implementation.hpp
@@ -2191,7 +2191,8 @@ namespace sol {
 			static_assert(std::is_constructible<T, Args&&...>::value, "T must be constructible with Args");
 
 			*this = nullopt;
-			this->construct(std::forward<Args>(args)...);
+			new (static_cast<void*>(this)) optional(std::in_place, std::forward<Args>(args)...);
+			return **this;
 		}
 
 		/// Swaps this optional with the other.
