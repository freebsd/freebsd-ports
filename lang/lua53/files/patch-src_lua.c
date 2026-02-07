--- src/lua.c.orig	2017-04-19 17:29:57 UTC
+++ src/lua.c
@@ -77,16 +77,66 @@
 */
 #if !defined(lua_readline)	/* { */
 
-#if defined(LUA_USE_READLINE)	/* { */
+#if defined(LUA_USE_READLINE_DL)/* { */
+
+#include <dlfcn.h>
+
+#ifndef LUA_READLINE_LIBPATH
+#define LUA_READLINE_LIBPATH "/usr/local/lib/libedit.so"
+#endif
+
+typedef char *readline_functype(const char *);
+typedef int add_history_functype(const char *);
+
+static readline_functype *lua_readline_p = NULL;
+static add_history_functype *lua_saveline_p = NULL;
+
+static void lua_initreadline(lua_State *L)
+{
+  void *editlib = NULL;
+  union dl_func_hack {
+    void *ptr;
+    readline_functype *rlfunc;
+    add_history_functype *ahfunc;
+    char **rlnamevar;
+    int *icompvar;
+  } u;
+  (void) L;
+  if ((editlib = dlopen(LUA_READLINE_LIBPATH, RTLD_LAZY | RTLD_LOCAL))) {
+    u.ptr = dlsym(editlib, "readline");
+    lua_readline_p = u.rlfunc;
+    u.ptr = dlsym(editlib, "add_history");
+    lua_saveline_p = u.ahfunc;
+    if ((u.ptr = dlsym(editlib, "rl_readline_name")))
+      *u.rlnamevar = "lua";
+    if ((u.ptr = dlsym(editlib, "rl_inhibit_completion")))
+      *u.icompvar = 1;
+  }
+}
+
+#define lua_readline(L,b,p) \
+  ((void)L,                                                          \
+   (lua_readline_p)                                                  \
+   ? (((b)=lua_readline_p(p)) != NULL)                               \
+   : (fputs(p, stdout), fflush(stdout), fgets(b, LUA_MAXINPUT, stdin) != NULL))
+#define lua_saveline(L,line)	\
+  do { (void)L; if (lua_saveline_p) lua_saveline_p(line); } while(0)
+#define lua_freeline(L,b)	\
+  do { (void)L; if (lua_readline_p) free(b); } while(0)
+
+#elif defined(LUA_USE_READLINE)	/* { */
 
 #include <readline/readline.h>
 #include <readline/history.h>
+#define lua_initreadline(L)  \
+	((void)L, rl_readline_name="lua", rl_inhibit_completion=1)
 #define lua_readline(L,b,p)	((void)L, ((b)=readline(p)) != NULL)
 #define lua_saveline(L,line)	((void)L, add_history(line))
 #define lua_freeline(L,b)	((void)L, free(b))
 
 #else				/* }{ */
 
+#define lua_initreadline(L)	((void) L)
 #define lua_readline(L,b,p) \
         ((void)L, fputs(p, stdout), fflush(stdout),  /* show prompt */ \
         fgets(b, LUA_MAXINPUT, stdin) != NULL)  /* get line */
@@ -406,6 +456,7 @@ static void doREPL (lua_State *L) {
   int status;
   const char *oldprogname = progname;
   progname = NULL;  /* no 'progname' on errors in interactive mode */
+  lua_initreadline(L);
   while ((status = loadline(L)) != -1) {
     if (status == LUA_OK)
       status = docall(L, 0, LUA_MULTRET);
