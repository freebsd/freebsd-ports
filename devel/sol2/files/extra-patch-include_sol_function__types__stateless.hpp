--- include/sol/function_types_stateless.hpp.orig	2021-03-06 06:03:23 UTC
+++ include/sol/function_types_stateless.hpp
@@ -320,7 +320,9 @@ namespace sol { namespace function_detail {
 		}
 
 		template <bool is_yielding, bool no_trampoline>
-		static int call(lua_State* L) noexcept(std::is_nothrow_copy_assignable_v<T>) {
+                static int call(lua_State* L)
+                // regression in clang 18 - llvm/llvm-project#91362
+                {
 			int nr;
 			if constexpr (no_trampoline) {
 				nr = real_call(L);
@@ -360,7 +362,9 @@ namespace sol { namespace function_detail {
 		}
 
 		template <bool is_yielding, bool no_trampoline>
-		static int call(lua_State* L) noexcept(std::is_nothrow_copy_assignable_v<T>) {
+		static int call(lua_State* L)
+		// regression in clang 18 - llvm/llvm-project#91362
+		{
 			int nr;
 			if constexpr (no_trampoline) {
 				nr = real_call(L);
