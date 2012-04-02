X-Git-Url: http://repo.or.cz/w/luajit-2.0.git/blobdiff_plain/339142c2aaa82fd6e3c71fdbbb12296899e8cdd2..018792452ecdcaeff9362e4238004420665b450b:/src/lj_err.c

diff --git a/src/lj_err.c b/src/lj_err.c
index a4c7478..b46a6dc 100644
--- src/lj_err.c
+++ src/lj_err.c
@@ -187,24 +187,48 @@ static void *err_unwind(lua_State *L, void *stopcf, int errcode)
 
 #if defined(__GNUC__) && !defined(LUAJIT_NO_UNWIND)
 
-#ifdef __clang__
-/* http://llvm.org/bugs/show_bug.cgi?id=8703 */
-#define __unwind_word__ word
-#endif
+/*
+** We have to use our own definitions instead of the mandatory (!) unwind.h,
+** since various OS, distros and compilers mess up the header installation.
+*/
+
+typedef struct _Unwind_Exception
+{
+  uint64_t exclass;
+  void (*excleanup)(int, struct _Unwind_Exception);
+  uintptr_t p1, p2;
+} __attribute__((__aligned__)) _Unwind_Exception;
+
+typedef struct _Unwind_Context _Unwind_Context;
 
-#include <unwind.h>
+#define _URC_OK			0
+#define _URC_FATAL_PHASE1_ERROR	3
+#define _URC_HANDLER_FOUND	6
+#define _URC_INSTALL_CONTEXT	7
+#define _URC_CONTINUE_UNWIND	8
+#define _URC_FAILURE		9
 
 #if !LJ_TARGET_ARM
 
+extern uintptr_t _Unwind_GetCFA(_Unwind_Context *);
+extern void _Unwind_SetGR(_Unwind_Context *, int, uintptr_t);
+extern void _Unwind_SetIP(_Unwind_Context *, uintptr_t);
+extern void _Unwind_DeleteException(_Unwind_Exception *);
+extern int _Unwind_RaiseException(_Unwind_Exception *);
+
+#define _UA_SEARCH_PHASE	1
+#define _UA_CLEANUP_PHASE	2
+#define _UA_HANDLER_FRAME	4
+#define _UA_FORCE_UNWIND	8
+
 #define LJ_UEXCLASS		0x4c55414a49543200ULL	/* LUAJIT2\0 */
 #define LJ_UEXCLASS_MAKE(c)	(LJ_UEXCLASS | (uint64_t)(c))
 #define LJ_UEXCLASS_CHECK(cl)	(((cl) ^ LJ_UEXCLASS) <= 0xff)
 #define LJ_UEXCLASS_ERRCODE(cl)	((int)((cl) & 0xff))
 
 /* DWARF2 personality handler referenced from interpreter .eh_frame. */
-LJ_FUNCA int lj_err_unwind_dwarf(int version, _Unwind_Action actions,
-  uint64_t uexclass, struct _Unwind_Exception *uex,
-  struct _Unwind_Context *ctx)
+LJ_FUNCA int lj_err_unwind_dwarf(int version, int actions,
+  uint64_t uexclass, _Unwind_Exception *uex, _Unwind_Context *ctx)
 {
   void *cf;
   lua_State *L;
@@ -255,7 +279,7 @@ LJ_FUNCA int lj_err_unwind_dwarf(int version, _Unwind_Action actions,
 #endif
 #else
     /* This is not the proper way to escape from the unwinder. We get away with
-    ** it on x86/PPC because the interpreter restores all callee-saved regs.
+    ** it on non-x64 because the interpreter restores all callee-saved regs.
     */
     lj_err_throw(L, errcode);
 #endif
@@ -266,26 +290,46 @@ LJ_FUNCA int lj_err_unwind_dwarf(int version, _Unwind_Action actions,
 #if LJ_UNWIND_EXT
 #if LJ_TARGET_OSX || defined(__OpenBSD__)
 /* Sorry, no thread safety for OSX. Complain to Apple, not me. */
-static struct _Unwind_Exception static_uex;
+static _Unwind_Exception static_uex;
 #else
-static __thread struct _Unwind_Exception static_uex;
+static __thread _Unwind_Exception static_uex;
 #endif
 
 /* Raise DWARF2 exception. */
 static void err_raise_ext(int errcode)
 {
-  static_uex.exception_class = LJ_UEXCLASS_MAKE(errcode);
-  static_uex.exception_cleanup = NULL;
+  static_uex.exclass = LJ_UEXCLASS_MAKE(errcode);
+  static_uex.excleanup = NULL;
   _Unwind_RaiseException(&static_uex);
 }
 #endif
 
 #else
 
+extern void _Unwind_DeleteException(void *);
+extern int __gnu_unwind_frame (void *, _Unwind_Context *);
+extern int _Unwind_VRS_Set(_Unwind_Context *, int, uint32_t, int, void *);
+extern int _Unwind_VRS_Get(_Unwind_Context *, int, uint32_t, int, void *);
+
+static inline uint32_t _Unwind_GetGR(_Unwind_Context *ctx, int r)
+{
+  uint32_t v;
+  _Unwind_VRS_Get(ctx, 0, r, 0, &v);
+  return v;
+}
+
+static inline void _Unwind_SetGR(_Unwind_Context *ctx, int r, uint32_t v)
+{
+  _Unwind_VRS_Set(ctx, 0, r, 0, &v);
+}
+
+#define _US_VIRTUAL_UNWIND_FRAME	0
+#define _US_UNWIND_FRAME_STARTING	1
+#define _US_ACTION_MASK			3
+#define _US_FORCE_UNWIND		8
+
 /* ARM unwinder personality handler referenced from interpreter .ARM.extab. */
-LJ_FUNCA _Unwind_Reason_Code lj_err_unwind_arm(_Unwind_State state,
-					       _Unwind_Control_Block *ucb,
-					       _Unwind_Context *ctx)
+LJ_FUNCA int lj_err_unwind_arm(int state, void *ucb, _Unwind_Context *ctx)
 {
   void *cf = (void *)_Unwind_GetGR(ctx, 13);
   lua_State *L = cframe_L(cf);
@@ -295,9 +339,9 @@ LJ_FUNCA _Unwind_Reason_Code lj_err_unwind_arm(_Unwind_State state,
   }
   if ((state&(_US_ACTION_MASK|_US_FORCE_UNWIND)) == _US_UNWIND_FRAME_STARTING) {
     _Unwind_DeleteException(ucb);
-    _Unwind_SetGR(ctx, 15, (_Unwind_Word)(void *)lj_err_throw);
-    _Unwind_SetGR(ctx, 0, (_Unwind_Word)L);
-    _Unwind_SetGR(ctx, 1, (_Unwind_Word)LUA_ERRRUN);
+    _Unwind_SetGR(ctx, 15, (uint32_t)(void *)lj_err_throw);
+    _Unwind_SetGR(ctx, 0, (uint32_t)L);
+    _Unwind_SetGR(ctx, 1, (uint32_t)LUA_ERRRUN);
     return _URC_INSTALL_CONTEXT;
   }
   if (__gnu_unwind_frame(ucb, ctx) != _URC_OK)
