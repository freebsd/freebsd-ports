--- engine/luaxx/state.cpp.orig	2008-06-08 09:02:39 UTC
+++ engine/luaxx/state.cpp
@@ -59,7 +59,11 @@ static const char * chunk_reader(lua_State *L, void *d
 void State::load(const std::string &fname, const mrt::Chunk &data) {
 	//throw_ex(("implement me[%s]", fname.c_str()));
 	reader_state x(data);
-	int err = lua_load(state, chunk_reader, &x, fname.c_str());
+	int err = lua_load(state, chunk_reader, &x, fname.c_str()
+#if LUA_VERSION_NUM > 501
+	, NULL
+#endif
+	);
 	check_error(state, err);
 }
 
@@ -81,7 +85,7 @@ void State::init() {
 	assert(state == NULL);
 
 	//state = lua_newstate(l_alloc, this);
-	state = lua_open();
+	state = luaL_newstate();
 	if (state == NULL)
 		throw_ex(("cannot create lua interpreter"));
 
