--- ext/luawrapper/include/LuaContext.hpp.orig	2018-03-29 15:25:58 UTC
+++ ext/luawrapper/include/LuaContext.hpp
@@ -2635,11 +2635,21 @@ struct LuaContext::Reader<std::string>
     static auto read(lua_State* state, int index)
         -> boost::optional<std::string>
     {
+        std::string result;
+
+        // lua_tolstring might convert the variable that would confuse lua_next, so we
+        //   make a copy of the variable.
+        lua_pushvalue(state, index);
+
         size_t len;
-        const auto val = lua_tolstring(state, index, &len);
-        if (val == 0)
-            return boost::none;
-        return std::string(val, len);
+        const auto val = lua_tolstring(state, -1, &len);
+
+        if (val != 0)
+          result.assign(val, len);
+
+        lua_pop(state, 1);
+
+        return val != 0 ? boost::optional<std::string>{ std::move(result) } : boost::none;
     }
 };
 
