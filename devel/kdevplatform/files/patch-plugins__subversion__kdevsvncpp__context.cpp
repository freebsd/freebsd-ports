commit cc7f0798d314cdac14b90e427abe22e99c6bd591
Author: Milian Wolff <mail@milianw.de>
Date:   Fri Nov 18 16:23:36 2011 +0100

    properly initialize client context for compatibility with subversion API
    
    this should hopefully fix the crash with svn 1.7 in kdevelop, please test
    
    BUG: 284061

diff --git a/plugins/subversion/kdevsvncpp/context.cpp b/plugins/subversion/kdevsvncpp/context.cpp
index d277591..ddbb657 100644
--- ./plugins/subversion/kdevsvncpp/context.cpp
+++ ./plugins/subversion/kdevsvncpp/context.cpp
@@ -65,7 +65,7 @@ public:
     bool logIsSet;
     int promptCounter;
     Pool pool;
-    svn_client_ctx_t ctx;
+    svn_client_ctx_t * ctx;
     std::string username;
     std::string password;
     std::string logMessage;
@@ -205,26 +205,26 @@ public:
       svn_auth_open(&ab, providers, pool);
 
       // initialize ctx structure
-      memset(&ctx, 0, sizeof(ctx));
+      svn_client_create_context(&ctx, pool);
 
       // get the config based on the configDir passed in
-      svn_config_get_config(&ctx.config, c_configDir, pool);
+      svn_config_get_config(&ctx->config, c_configDir, pool);
 
       // tell the auth functions where the config is
       svn_auth_set_parameter(ab, SVN_AUTH_PARAM_CONFIG_DIR,
                              c_configDir);
 
-      ctx.auth_baton = ab;
-      ctx.log_msg_func = onLogMsg;
-      ctx.log_msg_baton = this;
-      ctx.notify_func = onNotify;
-      ctx.notify_baton = this;
-      ctx.cancel_func = onCancel;
-      ctx.cancel_baton = this;
+      ctx->auth_baton = ab;
+      ctx->log_msg_func = onLogMsg;
+      ctx->log_msg_baton = this;
+      ctx->notify_func = onNotify;
+      ctx->notify_baton = this;
+      ctx->cancel_func = onCancel;
+      ctx->cancel_baton = this;
 
 #if (SVN_VER_MAJOR >= 1) && (SVN_VER_MINOR >= 2)
-      ctx.notify_func2 = onNotify2;
-      ctx.notify_baton2 = this;
+      ctx->notify_func2 = onNotify2;
+      ctx->notify_baton2 = this;
 #endif
     }
 
@@ -234,7 +234,7 @@ public:
       if (!value)
         param = (void *)"1";
 
-      svn_auth_set_parameter(ctx.auth_baton,
+      svn_auth_set_parameter(ctx->auth_baton,
                              SVN_AUTH_PARAM_NO_AUTH_CACHE,
                              param);
     }
@@ -245,7 +245,7 @@ public:
       username = usr;
       password = pwd;
 
-      svn_auth_baton_t * ab = ctx.auth_baton;
+      svn_auth_baton_t * ab = ctx->auth_baton;
       svn_auth_set_parameter(ab, SVN_AUTH_PARAM_DEFAULT_USERNAME,
                              username.c_str());
       svn_auth_set_parameter(ab, SVN_AUTH_PARAM_DEFAULT_PASSWORD,
@@ -654,13 +654,13 @@ public:
 
   Context::operator svn_client_ctx_t * ()
   {
-    return &(m->ctx);
+    return m->ctx;
   }
 
   svn_client_ctx_t *
   Context::ctx()
   {
-    return &(m->ctx);
+    return m->ctx;
   }
 
   void
