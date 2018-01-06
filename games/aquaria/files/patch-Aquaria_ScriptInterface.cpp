Aquaria/ScriptInterface.cpp:10412:59: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
#define MK_ALIAS(prefix, suffix, alias) {MK_STR(prefix)"_"MK_STR(alias), l_##prefix##_##suffix},
                                                          ^

--- Aquaria/ScriptInterface.cpp.orig	2016-06-19 23:56:27 UTC
+++ Aquaria/ScriptInterface.cpp
@@ -10409,7 +10409,7 @@ static const struct {
 #undef MK_ALIAS
 #define MK_FUNC(base, getter, prefix, suffix) luaRegister(prefix##_##suffix),
 #define MK_STR(s) #s
-#define MK_ALIAS(prefix, suffix, alias) {MK_STR(prefix)"_"MK_STR(alias), l_##prefix##_##suffix},
+#define MK_ALIAS(prefix, suffix, alias) {MK_STR(prefix) "_" MK_STR(alias), l_##prefix##_##suffix},
 
 	EXPAND_FUNC_PROTOTYPES
 
