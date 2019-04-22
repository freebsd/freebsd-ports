--- state.cpp.orig	2019-04-22 05:13:10 UTC
+++ state.cpp
@@ -492,7 +492,7 @@ lutok::state::is_userdata(const int inde
 void
 lutok::state::load_file(const std::string& file)
 {
-    if (!::access(file.c_str(), R_OK) == 0)
+    if (::access(file.c_str(), R_OK) == -1)
         throw lutok::file_not_found_error(file);
     if (luaL_loadfile(_pimpl->lua_state, file.c_str()) != 0)
         throw lutok::api_error::from_stack(*this, "luaL_loadfile");
