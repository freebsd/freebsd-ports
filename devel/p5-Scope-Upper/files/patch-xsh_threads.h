--- xsh/threads.h.orig	2016-06-04 20:01:09 UTC
+++ xsh/threads.h
@@ -0,0 +1,501 @@
+#ifndef XSH_THREADS_H
+#define XSH_THREADS_H 1
+
+#include "caps.h" /* XSH_HAS_PERL(), XSH_THREADSAFE */
+#include "util.h" /* XSH_PACKAGE, dNOOP, NOOP */
+
+#ifndef XSH_THREADS_COMPILE_TIME_PROTECTION
+# define XSH_THREADS_COMPILE_TIME_PROTECTION 0
+#endif
+
+#ifndef XSH_THREADS_USER_CONTEXT
+# define XSH_THREADS_USER_CONTEXT 1
+#endif
+
+#ifndef XSH_THREADS_USER_GLOBAL_SETUP
+# define XSH_THREADS_USER_GLOBAL_SETUP 1
+#endif
+
+#ifndef XSH_THREADS_USER_LOCAL_SETUP
+# define XSH_THREADS_USER_LOCAL_SETUP 1
+#endif
+
+#ifndef XSH_THREADS_USER_LOCAL_TEARDOWN
+# define XSH_THREADS_USER_LOCAL_TEARDOWN 1
+#endif
+
+#ifndef XSH_THREADS_USER_GLOBAL_TEARDOWN
+# define XSH_THREADS_USER_GLOBAL_TEARDOWN 1
+#endif
+
+#ifndef XSH_THREADS_PEEP_CONTEXT
+# define XSH_THREADS_PEEP_CONTEXT 0
+#endif
+
+#ifndef XSH_THREADS_HINTS_CONTEXT
+# define XSH_THREADS_HINTS_CONTEXT 0
+#endif
+
+#ifndef XSH_THREADS_USER_CLONE_NEEDS_DUP
+# define XSH_THREADS_USER_CLONE_NEEDS_DUP 0
+#endif
+
+#if XSH_THREADSAFE && (XSH_THREADS_HINTS_CONTEXT || XSH_THREADS_USER_CLONE_NEEDS_DUP)
+# define XSH_THREADS_CLONE_NEEDS_DUP 1
+#else
+# define XSH_THREADS_CLONE_NEEDS_DUP 0
+#endif
+
+#if defined(XSH_OPS_H) && (!XSH_THREADS_GLOBAL_SETUP || !XSH_THREADS_GLOBAL_TEARDOWN)
+# error settting up hook check functions require global setup/teardown
+#endif
+
+#ifndef XSH_THREADS_NEED_TEARDOWN_LATE
+# define XSH_THREADS_NEED_TEARDOWN_LATE 0
+#endif
+
+#if XSH_THREADS_NEED_TEARDOWN_LATE && (!XSH_THREADS_USER_LOCAL_TEARDOWN || !XSH_THREADS_USER_GLOBAL_TEARDOWN)
+# error you need to declare local or global teardown handlers to use the late teardown feature
+#endif
+
+#if XSH_THREADSAFE
+# ifndef MY_CXT_CLONE
+#  define MY_CXT_CLONE \
+    dMY_CXT_SV;                                                      \
+    my_cxt_t *my_cxtp = (my_cxt_t*)SvPVX(newSV(sizeof(my_cxt_t)-1)); \
+    Copy(INT2PTR(my_cxt_t*, SvUV(my_cxt_sv)), my_cxtp, 1, my_cxt_t); \
+    sv_setuv(my_cxt_sv, PTR2UV(my_cxtp))
+# endif
+#else
+# undef  dMY_CXT
+# define dMY_CXT      dNOOP
+# undef  MY_CXT
+# define MY_CXT       xsh_globaldata
+# undef  START_MY_CXT
+# define START_MY_CXT static my_cxt_t MY_CXT;
+# undef  MY_CXT_INIT
+# define MY_CXT_INIT  NOOP
+# undef  MY_CXT_CLONE
+# define MY_CXT_CLONE NOOP
+#endif
+
+#if XSH_THREADSAFE
+/* We must use preexistent global mutexes or we will never be able to destroy
+ * them. */
+# if XSH_HAS_PERL(5, 9, 3)
+#  define XSH_LOADED_LOCK   MUTEX_LOCK(&PL_my_ctx_mutex)
+#  define XSH_LOADED_UNLOCK MUTEX_UNLOCK(&PL_my_ctx_mutex)
+# else
+#  define XSH_LOADED_LOCK   OP_REFCNT_LOCK
+#  define XSH_LOADED_UNLOCK OP_REFCNT_UNLOCK
+# endif
+#else
+# define XSH_LOADED_LOCK   NOOP
+# define XSH_LOADED_UNLOCK NOOP
+#endif
+
+static I32 xsh_loaded = 0;
+
+#if XSH_THREADSAFE && XSH_THREADS_COMPILE_TIME_PROTECTION
+
+#define PTABLE_USE_DEFAULT 1
+
+#include "ptable.h"
+
+#define ptable_loaded_store(T, K, V) ptable_default_store(aPTBL_ (T), (K), (V))
+#define ptable_loaded_delete(T, K)   ptable_default_delete(aPTBL_ (T), (K))
+#define ptable_loaded_free(T)        ptable_default_free(aPTBL_ (T))
+
+static ptable *xsh_loaded_cxts = NULL;
+
+static int xsh_is_loaded(pTHX_ void *cxt) {
+#define xsh_is_loaded(C) xsh_is_loaded(aTHX_ (C))
+ int res = 0;
+
+ XSH_LOADED_LOCK;
+ if (xsh_loaded_cxts && ptable_fetch(xsh_loaded_cxts, cxt))
+  res = 1;
+ XSH_LOADED_UNLOCK;
+
+ return res;
+}
+
+static int xsh_set_loaded_locked(pTHX_ void *cxt) {
+#define xsh_set_loaded_locked(C) xsh_set_loaded_locked(aTHX_ (C))
+ int global_setup = 0;
+
+ if (xsh_loaded <= 0) {
+  XSH_ASSERT(xsh_loaded == 0);
+  XSH_ASSERT(!xsh_loaded_cxts);
+  xsh_loaded_cxts = ptable_new(4);
+  global_setup   = 1;
+ }
+ ++xsh_loaded;
+ XSH_ASSERT(xsh_loaded_cxts);
+ ptable_loaded_store(xsh_loaded_cxts, cxt, cxt);
+
+ return global_setup;
+}
+
+static int xsh_clear_loaded_locked(pTHX_ void *cxt) {
+#define xsh_clear_loaded_locked(C) xsh_clear_loaded_locked(aTHX_ (C))
+ int global_teardown = 0;
+
+ if (xsh_loaded > 1) {
+  XSH_ASSERT(xsh_loaded_cxts);
+  ptable_loaded_delete(xsh_loaded_cxts, cxt);
+  --xsh_loaded;
+ } else if (xsh_loaded_cxts) {
+  XSH_ASSERT(xsh_loaded == 1);
+  ptable_loaded_free(xsh_loaded_cxts);
+  xsh_loaded_cxts = NULL;
+  xsh_loaded      = 0;
+  global_teardown = 1;
+ }
+
+ return global_teardown;
+}
+
+#else  /*  XSH_THREADS_COMPILE_TIME_PROTECTION */
+
+#define xsh_is_loaded_locked(C)    (xsh_loaded > 0)
+#define xsh_set_loaded_locked(C)   ((xsh_loaded++ <= 0) ? 1 : 0)
+#define xsh_clear_loaded_locked(C) ((--xsh_loaded <= 0) ? 1 : 0)
+
+#if XSH_THREADSAFE
+
+static int xsh_is_loaded(pTHX_ void *cxt) {
+#define xsh_is_loaded(C) xsh_is_loaded(aTHX_ (C))
+ int res = 0;
+
+ XSH_LOADED_LOCK;
+ res = xsh_is_loaded_locked(cxt);
+ XSH_LOADED_UNLOCK;
+
+ return res;
+}
+
+#else
+
+#define xsh_is_loaded(C) xsh_is_loaded_locked(C)
+
+#endif
+
+#endif /* !XSH_THREADS_COMPILE_TIME_PROTECTION */
+
+#define MY_CXT_KEY XSH_PACKAGE "::_guts" XS_VERSION
+
+typedef struct {
+#if XSH_THREADS_USER_CONTEXT
+ xsh_user_cxt_t  cxt_user;
+#endif
+#if XSH_THREADS_PEEP_CONTEXT
+ xsh_peep_cxt_t  cxt_peep;
+#endif
+#if XSH_THREADS_HINTS_CONTEXT
+ xsh_hints_cxt_t cxt_hints;
+#endif
+#if XSH_THREADS_CLONE_NEEDS_DUP
+ tTHX            owner;
+#endif
+#if !(XSH_THREADS_USER_CONTEXT || XSH_THREADS_PEEP_CONTEXT || XSH_THREADS_HINTS_CONTEXT || XSH_THREADS_CLONE_NEEDS_DUP)
+ int             dummy;
+#endif
+} my_cxt_t;
+
+START_MY_CXT
+
+#if XSH_THREADS_USER_CONTEXT
+# define dXSH_CXT dMY_CXT
+# define XSH_CXT  (MY_CXT.cxt_user)
+#endif
+
+#if XSH_THREADS_USER_GLOBAL_SETUP
+static void xsh_user_global_setup(pTHX);
+#endif
+
+#if XSH_THREADS_USER_LOCAL_SETUP
+# if XSH_THREADS_USER_CONTEXT
+static void xsh_user_local_setup(pTHX_ xsh_user_cxt_t *cxt);
+# else
+static void xsh_user_local_setup(pTHX);
+# endif
+#endif
+
+#if XSH_THREADS_USER_LOCAL_TEARDOWN
+# if XSH_THREADS_USER_CONTEXT
+static void xsh_user_local_teardown(pTHX_ xsh_user_cxt_t *cxt);
+# else
+static void xsh_user_local_teardown(pTHX);
+# endif
+#endif
+
+#if XSH_THREADS_USER_GLOBAL_TEARDOWN
+static void xsh_user_global_teardown(pTHX);
+#endif
+
+#if XSH_THREADSAFE && XSH_THREADS_USER_CONTEXT
+# if XSH_THREADS_USER_CLONE_NEEDS_DUP
+static void xsh_user_clone(pTHX_ const xsh_user_cxt_t *old_cxt, xsh_user_cxt_t *new_cxt, CLONE_PARAMS *params);
+# else
+static void xsh_user_clone(pTHX_ const xsh_user_cxt_t *old_cxt, xsh_user_cxt_t *new_cxt);
+# endif
+#endif
+
+#if XSH_THREADS_PEEP_CONTEXT
+static xsh_peep_cxt_t *xsh_peep_get_cxt(pTHX) {
+ dMY_CXT;
+ XSH_ASSERT(xsh_is_loaded(&MY_CXT));
+ return &MY_CXT.cxt_peep;
+}
+#endif
+
+#if XSH_THREADS_HINTS_CONTEXT
+static xsh_hints_cxt_t *xsh_hints_get_cxt(pTHX) {
+ dMY_CXT;
+ XSH_ASSERT(xsh_is_loaded(&MY_CXT));
+ return &MY_CXT.cxt_hints;
+}
+#endif
+
+#if XSH_THREADS_NEED_TEARDOWN_LATE
+
+typedef void (*xsh_teardown_late_cb)(pTHX_ void *ud);
+
+static int xsh_teardown_late_simple_free(pTHX_ SV *sv, MAGIC *mg) {
+ xsh_teardown_late_cb cb;
+
+ cb = DPTR2FPTR(xsh_teardown_late_cb, mg->mg_ptr);
+
+ XSH_LOADED_LOCK;
+ if (xsh_loaded == 0)
+  cb(aTHX_ NULL);
+ XSH_LOADED_UNLOCK;
+
+ return 0;
+}
+
+static MGVTBL xsh_teardown_late_simple_vtbl = {
+ 0,
+ 0,
+ 0,
+ 0,
+ xsh_teardown_late_simple_free
+#if MGf_COPY
+ , 0
+#endif
+#if MGf_DUP
+ , 0
+#endif
+#if MGf_LOCAL
+ , 0
+#endif
+};
+
+typedef struct {
+ xsh_teardown_late_cb  cb;
+ void                 *ud;
+} xsh_teardown_late_token;
+
+static int xsh_teardown_late_arg_free(pTHX_ SV *sv, MAGIC *mg) {
+ xsh_teardown_late_token *tok;
+
+ tok = (xsh_teardown_late_token *) mg->mg_ptr;
+
+ XSH_LOADED_LOCK;
+ if (xsh_loaded == 0)
+  tok->cb(aTHX_ tok->ud);
+ XSH_LOADED_UNLOCK;
+
+ PerlMemShared_free(tok);
+
+ return 0;
+}
+
+static MGVTBL xsh_teardown_late_arg_vtbl = {
+ 0,
+ 0,
+ 0,
+ 0,
+ xsh_teardown_late_arg_free
+#if MGf_COPY
+ , 0
+#endif
+#if MGf_DUP
+ , 0
+#endif
+#if MGf_LOCAL
+ , 0
+#endif
+};
+
+static void xsh_teardown_late_register(pTHX_ xsh_teardown_late_cb cb, void *ud){
+#define xsh_teardown_late_register(CB, UD) xsh_teardown_late_register(aTHX_ (CB), (UD))
+ void *ptr;
+
+ if (!ud) {
+  ptr = FPTR2DPTR(void *, cb);
+ } else {
+  xsh_teardown_late_token *tok;
+
+  tok     = PerlMemShared_malloc(sizeof *tok);
+  tok->cb = cb;
+  tok->ud = ud;
+
+  ptr = tok;
+ }
+
+ if (!PL_strtab)
+  PL_strtab = newHV();
+
+ sv_magicext((SV *) PL_strtab, NULL, PERL_MAGIC_ext,
+             ud ? &xsh_teardown_late_arg_vtbl : &xsh_teardown_late_simple_vtbl,
+             ptr, 0);
+
+ return;
+}
+
+#endif /* XSH_THREADS_NEED_TEARDOWN_LATE */
+
+static void xsh_teardown(pTHX_ void *root) {
+ dMY_CXT;
+
+#if XSH_THREADS_USER_LOCAL_TEARDOWN
+# if XSH_THREADS_USER_CONTEXT
+ xsh_user_local_teardown(aTHX_ &XSH_CXT);
+# else
+ xsh_user_local_teardown(aTHX);
+# endif
+#endif
+
+#if XSH_THREADS_PEEP_CONTEXT
+ xsh_peep_local_teardown(aTHX_ &MY_CXT.cxt_peep);
+#endif
+
+#if XSH_THREADS_HINTS_CONTEXT
+ xsh_hints_local_teardown(aTHX_ &MY_CXT.cxt_hints);
+#endif
+
+ XSH_LOADED_LOCK;
+
+ if (xsh_clear_loaded_locked(&MY_CXT)) {
+#if XSH_THREADS_USER_GLOBAL_TEARDOWN
+  xsh_user_global_teardown(aTHX);
+#endif
+
+#if XSH_THREADS_HINTS_CONTEXT
+  xsh_hints_global_teardown(aTHX);
+#endif
+ }
+
+ XSH_LOADED_UNLOCK;
+
+ return;
+}
+
+static void xsh_setup(pTHX) {
+#define xsh_setup() xsh_setup(aTHX)
+ MY_CXT_INIT; /* Takes/release PL_my_ctx_mutex */
+
+ XSH_LOADED_LOCK;
+
+ if (xsh_set_loaded_locked(&MY_CXT)) {
+#if XSH_THREADS_HINTS_CONTEXT
+  xsh_hints_global_setup(aTHX);
+#endif
+
+#if XSH_THREADS_USER_GLOBAL_SETUP
+  xsh_user_global_setup(aTHX);
+#endif
+ }
+
+ XSH_LOADED_UNLOCK;
+
+#if XSH_THREADS_CLONE_NEEDS_DUP
+ MY_CXT.owner = aTHX;
+#endif
+
+#if XSH_THREADS_HINTS_CONTEXT
+ xsh_hints_local_setup(aTHX_ &MY_CXT.cxt_hints);
+#endif
+
+#if XSH_THREADS_PEEP_CONTEXT
+ xsh_peep_local_setup(aTHX_ &MY_CXT.cxt_peep);
+#endif
+
+#if XSH_THREADS_USER_LOCAL_SETUP
+# if XSH_THREADS_USER_CONTEXT
+ xsh_user_local_setup(aTHX_ &XSH_CXT);
+# else
+ xsh_user_local_setup(aTHX);
+# endif
+#endif
+
+ call_atexit(xsh_teardown, NULL);
+
+ return;
+}
+
+#if XSH_THREADSAFE
+
+static void xsh_clone(pTHX) {
+#define xsh_clone() xsh_clone(aTHX)
+ const my_cxt_t *old_cxt;
+ my_cxt_t       *new_cxt;
+
+ {
+  dMY_CXT;
+  old_cxt = &MY_CXT;
+ }
+
+ {
+  int global_setup;
+
+  MY_CXT_CLONE;
+  new_cxt = &MY_CXT;
+
+  XSH_LOADED_LOCK;
+  global_setup = xsh_set_loaded_locked(new_cxt);
+  XSH_ASSERT(!global_setup);
+  XSH_LOADED_UNLOCK;
+
+#if XSH_THREADS_CLONE_NEEDS_DUP
+  new_cxt->owner = aTHX;
+#endif
+ }
+
+ {
+#if XSH_THREADS_CLONE_NEEDS_DUP
+  XSH_DUP_PARAMS_TYPE params;
+  xsh_dup_params_init(params, old_cxt->owner);
+#endif
+
+#if XSH_THREADS_PEEP_CONTEXT
+  xsh_peep_clone(aTHX_ &old_cxt->cxt_peep, &new_cxt->cxt_peep);
+#endif
+
+#if XSH_THREADS_HINTS_CONTEXT
+  xsh_hints_clone(aTHX_ &old_cxt->cxt_hints, &new_cxt->cxt_hints,
+                        xsh_dup_params_ptr(params));
+#endif
+
+#if XSH_THREADS_USER_CONTEXT
+# if XSH_THREADS_USER_CLONE_NEEDS_DUP
+  xsh_user_clone(aTHX_ &old_cxt->cxt_user, &new_cxt->cxt_user,
+                       xsh_dup_params_ptr(params));
+# else
+  xsh_user_clone(aTHX_ &old_cxt->cxt_user, &new_cxt->cxt_user);
+# endif
+#endif
+
+#if XSH_THREADS_CLONE_NEEDS_DUP
+  xsh_dup_params_deinit(params);
+#endif
+ }
+
+ return;
+}
+
+#endif /* XSH_THREADSAFE */
+
+#endif /* XSH_THREADS_H */
