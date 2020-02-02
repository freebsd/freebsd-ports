--- Bootstrap.mak.orig	2019-10-20 12:14:52 UTC
+++ Bootstrap.mak
@@ -90,7 +90,7 @@ bsd: $(SRC)
 	mkdir -p build/bootstrap
 	$(CC) -o build/bootstrap/premake_bootstrap -DPREMAKE_NO_BUILTIN_SCRIPTS -DLUA_USE_POSIX -DLUA_USE_DLOPEN -I"$(LUA_DIR)" -I"$(LUASHIM_DIR)" $? -lm
 	./build/bootstrap/premake_bootstrap embed
-	./build/bootstrap/premake_bootstrap --to=build/bootstrap gmake2
+	./build/bootstrap/premake_bootstrap --to=build/bootstrap gmake
 	$(MAKE) -C build/bootstrap -j`getconf NPROCESSORS_ONLN` config=$(CONFIG)
 
 solaris: $(SRC)
