--- dnsdist-lua.cc.orig	2025-07-21 09:54:44 UTC
+++ dnsdist-lua.cc
@@ -2260,6 +2260,7 @@ static void setupLuaConfig(LuaContext& luaCtx, bool cl
 
       bool ignoreTLSConfigurationErrors = false;
       if (getOptionalValue<bool>(vars, "ignoreTLSConfigurationErrors", ignoreTLSConfigurationErrors) > 0 && ignoreTLSConfigurationErrors) {
+#if defined(HAVE_LIBSSL)
         // we are asked to try to load the certificates so we can return a potential error
         // and properly ignore the frontend before actually launching it
         try {
@@ -2269,6 +2270,7 @@ static void setupLuaConfig(LuaContext& luaCtx, bool cl
           errlog("Ignoring DoH frontend: '%s'", e.what());
           return;
         }
+#endif /* HAVE_LIBSSL */
       }
 
       checkAllParametersConsumed("addDOHLocal", vars);
@@ -2357,6 +2359,7 @@ static void setupLuaConfig(LuaContext& luaCtx, bool cl
 
       bool ignoreTLSConfigurationErrors = false;
       if (getOptionalValue<bool>(vars, "ignoreTLSConfigurationErrors", ignoreTLSConfigurationErrors) > 0 && ignoreTLSConfigurationErrors) {
+#if defined(HAVE_LIBSSL)
         // we are asked to try to load the certificates so we can return a potential error
         // and properly ignore the frontend before actually launching it
         try {
@@ -2366,6 +2369,7 @@ static void setupLuaConfig(LuaContext& luaCtx, bool cl
           errlog("Ignoring DoH3 frontend: '%s'", e.what());
           return;
         }
+#endif /* HAVE_LIBSSL */
       }
 
       checkAllParametersConsumed("addDOH3Local", vars);
@@ -2433,6 +2437,7 @@ static void setupLuaConfig(LuaContext& luaCtx, bool cl
 
       bool ignoreTLSConfigurationErrors = false;
       if (getOptionalValue<bool>(vars, "ignoreTLSConfigurationErrors", ignoreTLSConfigurationErrors) > 0 && ignoreTLSConfigurationErrors) {
+#if defined(HAVE_LIBSSL)
         // we are asked to try to load the certificates so we can return a potential error
         // and properly ignore the frontend before actually launching it
         try {
@@ -2442,6 +2447,7 @@ static void setupLuaConfig(LuaContext& luaCtx, bool cl
           errlog("Ignoring DoQ frontend: '%s'", e.what());
           return;
         }
+#endif /* HAVE_LIBSSL */
       }
 
       checkAllParametersConsumed("addDOQLocal", vars);
