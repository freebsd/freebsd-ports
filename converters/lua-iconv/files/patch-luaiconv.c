--- luaiconv.c.orig	2009-12-04 12:57:38.000000000 +0800
+++ luaiconv.c	2009-12-04 12:58:30.000000000 +0800
@@ -102,7 +102,7 @@ static int Liconv_open(lua_State *L) {
 static int Liconv(lua_State *L) {
     iconv_t cd = get_iconv_t(L, 1);
     size_t ibleft = lua_strlen(L, 2);
-    char *inbuf = (char*) luaL_checkstring(L, 2);
+    const char *inbuf = luaL_checkstring(L, 2);
     char *outbuf;
     char *outbufs;
     size_t obsize = (ibleft > 256) ? ibleft : 256; 
