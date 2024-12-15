--- include/sol/optional_implementation.hpp.orig	2024-12-13 07:59:32 UTC
+++ include/sol/optional_implementation.hpp
@@ -2191,7 +2191,8 @@ namespace sol {
 			static_assert(std::is_constructible<T, Args&&...>::value, "T must be constructible with Args");
 
 			*this = nullopt;
-			this->construct(std::forward<Args>(args)...);
+			new (static_cast<void*>(this)) optional(std::in_place, std::forward<Args>(args)...);
+			return **this;
 		}
 
 		/// Swaps this optional with the other.
