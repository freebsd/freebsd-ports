--- Upper.xs.orig	2015-08-18 13:52:04 UTC
+++ Upper.xs
@@ -6,21 +6,21 @@
 #include "perl.h"
 #include "XSUB.h"
 
-#define __PACKAGE__ "Scope::Upper"
+/* --- XS helpers ---------------------------------------------------------- */
 
-#ifndef SU_DEBUG
-# define SU_DEBUG 0
-#endif
+#define XSH_PACKAGE "Scope::Upper"
+
+#include "xsh/caps.h"
+#include "xsh/util.h"
+#include "xsh/debug.h"
 
 /* --- Compatibility ------------------------------------------------------- */
 
-#ifndef NOOP
-# define NOOP
+/* perl 5.23.8 onwards has a revamped context system */
+#if XSH_HAS_PERL(5, 23, 8)
+# define SU_HAS_NEW_CXT
 #endif
 
-#ifndef dNOOP
-# define dNOOP
-#endif
 
 #ifndef dVAR
 # define dVAR dNOOP
@@ -42,31 +42,6 @@
 # define PERL_UNUSED_VAR(V)
 #endif
 
-#ifndef STMT_START
-# define STMT_START do
-#endif
-
-#ifndef STMT_END
-# define STMT_END while (0)
-#endif
-
-#if SU_DEBUG
-# define SU_D(X) STMT_START X STMT_END
-static void su_debug_log(const char *fmt, ...) {
- va_list va;
- SV *sv;
- dTHX;
- va_start(va, fmt);
- sv = get_sv(__PACKAGE__ "::DEBUG", 0);
- if (sv && SvTRUE(sv))
-  PerlIO_vprintf(Perl_debug_log, fmt, va);
- va_end(va);
- return;
-}
-#else
-# define SU_D(X)
-#endif
-
 #ifndef Newx
 # define Newx(v, n, c) New(0, v, n, c)
 #endif
@@ -228,45 +203,6 @@ static U8 su_op_gimme_reverse(U8 gimme) 
 # define NEGATIVE_INDICES_VAR "NEGATIVE_INDICES"
 #endif
 
-#define SU_HAS_PERL(R, V, S) (PERL_REVISION > (R) || (PERL_REVISION == (R) && (PERL_VERSION > (V) || (PERL_VERSION == (V) && (PERL_SUBVERSION >= (S))))))
-#define SU_HAS_PERL_EXACT(R, V, S) ((PERL_REVISION == (R)) && (PERL_VERSION == (V)) && (PERL_SUBVERSION == (S)))
-
-/* --- Threads and multiplicity -------------------------------------------- */
-
-#ifndef SU_MULTIPLICITY
-# if defined(MULTIPLICITY) || defined(PERL_IMPLICIT_CONTEXT)
-#  define SU_MULTIPLICITY 1
-# else
-#  define SU_MULTIPLICITY 0
-# endif
-#endif
-#if SU_MULTIPLICITY && !defined(tTHX)
-# define tTHX PerlInterpreter*
-#endif
-
-#if SU_MULTIPLICITY && defined(USE_ITHREADS) && defined(dMY_CXT) && defined(MY_CXT) && defined(START_MY_CXT) && defined(MY_CXT_INIT) && (defined(MY_CXT_CLONE) || defined(dMY_CXT_SV))
-# define SU_THREADSAFE 1
-# ifndef MY_CXT_CLONE
-#  define MY_CXT_CLONE \
-    dMY_CXT_SV;                                                      \
-    my_cxt_t *my_cxtp = (my_cxt_t*)SvPVX(newSV(sizeof(my_cxt_t)-1)); \
-    Copy(INT2PTR(my_cxt_t*, SvUV(my_cxt_sv)), my_cxtp, 1, my_cxt_t); \
-    sv_setuv(my_cxt_sv, PTR2UV(my_cxtp))
-# endif
-#else
-# define SU_THREADSAFE 0
-# undef  dMY_CXT
-# define dMY_CXT      dNOOP
-# undef  MY_CXT
-# define MY_CXT       su_globaldata
-# undef  START_MY_CXT
-# define START_MY_CXT static my_cxt_t MY_CXT;
-# undef  MY_CXT_INIT
-# define MY_CXT_INIT  NOOP
-# undef  MY_CXT_CLONE
-# define MY_CXT_CLONE NOOP
-#endif
-
 /* --- Error messages ------------------------------------------------------ */
 
 static const char su_stack_smash[]    = "Cannot target a scope outside of the current stack";
@@ -287,22 +223,14 @@ static su_uv_array su_uid_seq_counter;
 
 static perl_mutex su_uid_seq_counter_mutex;
 
-#define SU_LOCK(M)   MUTEX_LOCK(M)
-#define SU_UNLOCK(M) MUTEX_UNLOCK(M)
-
-#else /* USE_ITHREADS */
-
-#define SU_LOCK(M)
-#define SU_UNLOCK(M)
-
-#endif /* !USE_ITHREADS */
+#endif /* USE_ITHREADS */
 
 static UV su_uid_seq_next(pTHX_ UV depth) {
 #define su_uid_seq_next(D) su_uid_seq_next(aTHX_ (D))
  UV seq;
  UV *seqs;
 
- SU_LOCK(&su_uid_seq_counter_mutex);
+ XSH_LOCK(&su_uid_seq_counter_mutex);
 
  seqs = su_uid_seq_counter.seqs;
 
@@ -319,7 +247,7 @@ static UV su_uid_seq_next(pTHX_ UV depth
 
  seq = ++seqs[depth];
 
- SU_UNLOCK(&su_uid_seq_counter_mutex);
+ XSH_UNLOCK(&su_uid_seq_counter_mutex);
 
  return seq;
 }
@@ -415,7 +343,7 @@ typedef struct {
 
 /* --- uplevel() data tokens and global storage ---------------------------- */
 
-#define SU_UPLEVEL_HIJACKS_RUNOPS SU_HAS_PERL(5, 8, 0)
+#define SU_UPLEVEL_HIJACKS_RUNOPS XSH_HAS_PERL(5, 8, 0)
 
 typedef struct {
  void          *next;
@@ -425,27 +353,39 @@ typedef struct {
 
  I32            cxix;
 
- I32            target_depth;
- CV            *target;
-
  CV            *callback;
  CV            *renamed;
 
+#ifdef SU_HAS_NEW_CXT
+ U8            *cxtypes; /* array of saved context types */
+ I32           gap;      /* how many contexts have temporarily CXt_NULLed out */
+ AV*           argarray; /* the PL_curpad[0] of the uplevel sub */
+#else
+ I32            target_depth;
+ CV            *target;
  PERL_SI       *si;
  PERL_SI       *old_curstackinfo;
  AV            *old_mainstack;
+ OP            *old_op;
+ bool           old_catch;
+ bool           died;
+#endif
 
  COP           *old_curcop;
 
- OP            *old_op;
 #if SU_UPLEVEL_HIJACKS_RUNOPS
  runops_proc_t  old_runops;
 #endif
- bool           old_catch;
-
- bool           died;
 } su_uplevel_ud;
 
+#ifdef SU_HAS_NEW_CXT
+/* used to flag a context stack entry whose type has been temporarily
+ * set to CXt_NULL. It relies on perl not using this value for real
+ * CXt_NULL entries.
+ */
+# define CXp_SU_UPLEVEL_NULLED 0x20
+#endif
+
 static su_uplevel_ud *su_uplevel_ud_new(pTHX) {
 #define su_uplevel_ud_new() su_uplevel_ud_new(aTHX)
  su_uplevel_ud *sud;
@@ -458,24 +398,29 @@ static su_uplevel_ud *su_uplevel_ud_new(
  sud->tmp_uid_storage.used  = 0;
  sud->tmp_uid_storage.alloc = 0;
 
+ #ifndef SU_HAS_NEW_CXT
  Newx(si, 1, PERL_SI);
  si->si_stack   = newAV();
  AvREAL_off(si->si_stack);
  si->si_cxstack = NULL;
- si->si_cxmax   = 0;
+ si->si_cxmax   = -1;
 
  sud->si = si;
+#endif
 
  return sud;
 }
 
 static void su_uplevel_ud_delete(pTHX_ su_uplevel_ud *sud) {
 #define su_uplevel_ud_delete(S) su_uplevel_ud_delete(aTHX_ (S))
+
+#ifndef SU_HAS_NEW_CXT
  PERL_SI *si = sud->si;
 
  Safefree(si->si_cxstack);
  SvREFCNT_dec(si->si_stack);
  Safefree(si);
+#endif
 
  Safefree(sud->tmp_uid_storage.map);
 
@@ -496,60 +441,97 @@ typedef struct {
 
 /* --- Global data --------------------------------------------------------- */
 
-#define MY_CXT_KEY __PACKAGE__ "::_guts" XS_VERSION
-
 typedef struct {
- char               *stack_placeholder;
  su_unwind_storage   unwind_storage;
  su_yield_storage    yield_storage;
  su_uplevel_storage  uplevel_storage;
  su_uid_storage      uid_storage;
-} my_cxt_t;
+} xsh_user_cxt_t;
 
-START_MY_CXT
+#define XSH_THREADS_USER_CONTEXT            1
+#define XSH_THREADS_USER_CLONE_NEEDS_DUP    0
+#define XSH_THREADS_COMPILE_TIME_PROTECTION 0
+
+#if XSH_THREADSAFE
+
+static void xsh_user_clone(pTHX_ const xsh_user_cxt_t *old_cxt, xsh_user_cxt_t *new_cxt) {
+ new_cxt->uplevel_storage.top   = NULL;
+ new_cxt->uplevel_storage.root  = NULL;
+ new_cxt->uplevel_storage.count = 0;
+ new_cxt->uid_storage.map   = NULL;
+ new_cxt->uid_storage.used  = 0;
+ new_cxt->uid_storage.alloc = 0;
+
+ su_uid_storage_dup(&new_cxt->uid_storage, &old_cxt->uid_storage,
+                    old_cxt->uid_storage.used);
+
+ return;
+}
+
+#endif /* XSH_THREADSAFE */
+
+#include "xsh/threads.h"
 
 /* --- Stack manipulations ------------------------------------------------- */
 
-#define SU_SAVE_PLACEHOLDER() save_pptr(&MY_CXT.stack_placeholder)
+/* how many slots on the save stack various save types take up */
 
-#define SU_SAVE_DESTRUCTOR_SIZE  3
-#define SU_SAVE_PLACEHOLDER_SIZE 3
+#define SU_SAVE_DESTRUCTOR_SIZE 3 /* SAVEt_DESTRUCTOR_X */
+#define SU_SAVE_SCALAR_SIZE     3 /* SAVEt_SV */
+#define SU_SAVE_ARY_SIZE        3 /* SAVEt_AV */
+#define SU_SAVE_AELEM_SIZE      4 /* SAVEt_AELEM */
+#define SU_SAVE_HASH_SIZE       3 /* SAVEt_HV */
+#define SU_SAVE_HELEM_SIZE      4 /* SAVEt_HELEM */
+#define SU_SAVE_HDELETE_SIZE    4 /* SAVEt_DELETE */
 
-#define SU_SAVE_SCALAR_SIZE 3
+#define SU_SAVE_GVCV_SIZE       SU_SAVE_DESTRUCTOR_SIZE
+
+/* the overhead of save_alloc() but not including any elements,
+ * of which there must be at least 1 */
+#if XSH_HAS_PERL(5, 14, 0)
+# define SU_SAVE_ALLOC_SIZE      1 /* SAVEt_ALLOC */
+#else
+# define SU_SAVE_ALLOC_SIZE      2 /* SAVEt_ALLOC */
+#endif
 
-#define SU_SAVE_ARY_SIZE      3
-#define SU_SAVE_AELEM_SIZE    4
 #ifdef SAVEADELETE
-# define SU_SAVE_ADELETE_SIZE 3
+# define SU_SAVE_ADELETE_SIZE   3 /* SAVEt_ADELETE */
 #else
-# define SU_SAVE_ADELETE_SIZE SU_SAVE_DESTRUCTOR_SIZE
+# define SU_SAVE_ADELETE_SIZE   SU_SAVE_DESTRUCTOR_SIZE
+#endif
+
+/* (NB: it was 4 between 5.13.1 and 5.13.7) */
+#if XSH_HAS_PERL(5, 8, 9)
+# define SU_SAVE_GP_SIZE        3 /* SAVEt_GP */
+# else
+# define SU_SAVE_GP_SIZE        6 /* SAVEt_GP */
 #endif
+
+/* sometimes we don't know in advance whether we're saving or deleting
+ * an array/hash element. So include enough room for a variable-sized
+ * save_alloc() to pad it to a fixed size.
+ */
+
 #if SU_SAVE_AELEM_SIZE < SU_SAVE_ADELETE_SIZE
-# define SU_SAVE_AELEM_OR_ADELETE_SIZE SU_SAVE_ADELETE_SIZE
+# define SU_SAVE_AELEM_OR_ADELETE_SIZE \
+    (SU_SAVE_ADELETE_SIZE + SU_SAVE_ALLOC_SIZE + 1)
+#elif SU_SAVE_AELEM_SIZE > SU_SAVE_ADELETE_SIZE
+# define SU_SAVE_AELEM_OR_ADELETE_SIZE \
+    (SU_SAVE_AELEM_SIZE + SU_SAVE_ALLOC_SIZE + 1)
 #else
 # define SU_SAVE_AELEM_OR_ADELETE_SIZE SU_SAVE_AELEM_SIZE
 #endif
 
-#define SU_SAVE_HASH_SIZE    3
-#define SU_SAVE_HELEM_SIZE   4
-#define SU_SAVE_HDELETE_SIZE 4
 #if SU_SAVE_HELEM_SIZE < SU_SAVE_HDELETE_SIZE
-# define SU_SAVE_HELEM_OR_HDELETE_SIZE SU_SAVE_HDELETE_SIZE
+# define SU_SAVE_HELEM_OR_HDELETE_SIZE \
+    (SU_SAVE_HDELETE_SIZE + SU_SAVE_ALLOC_SIZE + 1)
+#elif SU_SAVE_HELEM_SIZE > SU_SAVE_HDELETE_SIZE
+# define SU_SAVE_HELEM_OR_HDELETE_SIZE \
+    (SU_SAVE_HELEM_SIZE + SU_SAVE_ALLOC_SIZE + 1)
 #else
 # define SU_SAVE_HELEM_OR_HDELETE_SIZE SU_SAVE_HELEM_SIZE
 #endif
 
-#define SU_SAVE_GVCV_SIZE SU_SAVE_DESTRUCTOR_SIZE
-
-#if !SU_HAS_PERL(5, 8, 9)
-# define SU_SAVE_GP_SIZE 6
-#elif !SU_HAS_PERL(5, 13, 0) || (SU_RELEASE && SU_HAS_PERL_EXACT(5, 13, 0))
-# define SU_SAVE_GP_SIZE 3
-#elif !SU_HAS_PERL(5, 13, 8)
-# define SU_SAVE_GP_SIZE 4
-#else
-# define SU_SAVE_GP_SIZE 3
-#endif
 
 #ifndef SvCANEXISTDELETE
 # define SvCANEXISTDELETE(sv) \
@@ -572,7 +554,7 @@ static I32 su_av_key2idx(pTHX_ AV *av, I
   return key;
 
 /* Added by MJD in perl-5.8.1 with 6f12eb6d2a1dfaf441504d869b27d2e40ef4966a */
-#if SU_HAS_PERL(5, 8, 1)
+#if XSH_HAS_PERL(5, 8, 1)
  if (SvRMAGICAL(av)) {
   const MAGIC * const tied_magic = mg_find((SV *) av, PERL_MAGIC_tied);
   if (tied_magic) {
@@ -693,7 +675,7 @@ static void su_save_helem(pTHX_ HV *hv, 
 
 /* ... Saving code slots from a glob ....................................... */
 
-#if !SU_HAS_PERL(5, 10, 0) && !defined(mro_method_changed_in)
+#if !XSH_HAS_PERL(5, 10, 0) && !defined(mro_method_changed_in)
 # define mro_method_changed_in(G) PL_sub_generation++
 #endif
 
@@ -731,17 +713,21 @@ static void su_save_gvcv(pTHX_ GV *gv) {
 /* --- Actions ------------------------------------------------------------- */
 
 typedef struct {
+ I32  orig_ix; /* original savestack_ix */
+ I32  offset;  /* how much we bumped this savestack index */
+} su_ud_origin_elem;
+
+typedef struct {
  U8   type;
  U8   private;
- U8   pad;
  /* spare */
  I32  depth;
- I32 *origin;
+ su_ud_origin_elem *origin;
 } su_ud_common;
 
+
 #define SU_UD_TYPE(U)    (((su_ud_common *) (U))->type)
 #define SU_UD_PRIVATE(U) (((su_ud_common *) (U))->private)
-#define SU_UD_PAD(U)     (((su_ud_common *) (U))->pad)
 #define SU_UD_DEPTH(U)   (((su_ud_common *) (U))->depth)
 #define SU_UD_ORIGIN(U)  (((su_ud_common *) (U))->origin)
 
@@ -756,7 +742,7 @@ typedef struct {
 
 /* ... Reap ................................................................ */
 
-#define SU_SAVE_LAST_CX (!SU_HAS_PERL(5, 8, 4) || (SU_HAS_PERL(5, 9, 5) && !SU_HAS_PERL(5, 14, 0)) || SU_HAS_PERL(5, 15, 0))
+#define SU_SAVE_LAST_CX (!XSH_HAS_PERL(5, 8, 4) || (XSH_HAS_PERL(5, 9, 5) && !XSH_HAS_PERL(5, 14, 0)) || XSH_HAS_PERL(5, 15, 0))
 
 typedef struct {
  su_ud_common ci;
@@ -773,8 +759,8 @@ static void su_call(pTHX_ SV *cb) {
 
  dSP;
 
- SU_D(su_debug_log("@@@ call scope_ix=%2d save_ix=%2d\n",
-                         PL_scopestack_ix, PL_savestack_ix));
+ XSH_D(su_debug_log("@@@ call scope_ix=%2d save_ix=%2d\n",
+                          PL_scopestack_ix, PL_savestack_ix));
 
  ENTER;
  SAVETMPS;
@@ -919,6 +905,15 @@ static void su_localize(pTHX_ void *ud_)
  if (SvTYPE(sv) >= SVt_PVGV) {
   gv = (GV *) sv;
  } else {
+
+/* new perl context implementation frees savestack *before* restoring
+ * PL_curcop. Temporarily restore it prematurely to make gv_fetch*
+ * looks up unqualified var names in the caller's package */
+#ifdef SU_HAS_NEW_CXT
+  COP *old_cop = PL_curcop;
+  PL_curcop = CX_CUR()->blk_oldcop;
+#endif
+
 #ifdef gv_fetchsv
   gv = gv_fetchsv(sv, GV_ADDMULTI, t);
 #else
@@ -926,13 +921,16 @@ static void su_localize(pTHX_ void *ud_)
   const char *name = SvPV_const(sv, len);
   gv = gv_fetchpvn_flags(name, len, GV_ADDMULTI, t);
 #endif
+#ifdef SU_HAS_NEW_CXT
+  CX_CUR()->blk_oldcop = PL_curcop;
+#endif
  }
 
- SU_D({
+ XSH_D({
   SV *z = newSV(0);
   SvUPGRADE(z, t);
-  su_debug_log("%p: === localize a %s\n",ud, sv_reftype(z, 0));
-  su_debug_log("%p: depth=%2d scope_ix=%2d save_ix=%2d\n",
+  su_debug_log("%p:     === localize a %s\n",ud, sv_reftype(z, 0));
+  su_debug_log("%p:         depth=%2d scope_ix=%2d save_ix=%2d\n",
                 ud, SU_UD_DEPTH(ud), PL_scopestack_ix, PL_savestack_ix);
   SvREFCNT_dec(z);
  });
@@ -972,7 +970,7 @@ static void su_localize(pTHX_ void *ud_)
 
 /* ... Unique context ID ................................................... */
 
-/* We must pass the index because MY_CXT.uid_storage might be reallocated
+/* We must pass the index because XSH_CXT.uid_storage might be reallocated
  * between the UID fetch and the invalidation at the end of scope. */
 
 typedef struct {
@@ -982,9 +980,9 @@ typedef struct {
 
 static void su_uid_drop(pTHX_ void *ud_) {
  su_ud_uid *ud = ud_;
- dMY_CXT;
+ dXSH_CXT;
 
- MY_CXT.uid_storage.map[ud->idx].flags &= ~SU_UID_ACTIVE;
+ XSH_CXT.uid_storage.map[ud->idx].flags &= ~SU_UID_ACTIVE;
 
  SU_UD_FREE(ud);
 
@@ -994,37 +992,50 @@ static void su_uid_drop(pTHX_ void *ud_)
 /* --- Pop a context back -------------------------------------------------- */
 
 #ifdef DEBUGGING
-# define SU_CXNAME(C) PL_block_type[CxTYPE(C)]
+# define SU_CX_TYPENAME(T) PL_block_type[(T)]
 #else
-# if SU_HAS_PERL(5, 11, 0)
+# if XSH_HAS_PERL(5, 23, 8)
 static const char *su_block_type[] = {
  "NULL",
  "WHEN",
  "BLOCK",
  "GIVEN",
- "LOOP_FOR",
- "LOOP_PLAIN",
+ "LOOP_ARY",
  "LOOP_LAZYSV",
  "LOOP_LAZYIV",
+ "LOOP_LIST",
+ "LOOP_PLAIN",
  "SUB",
  "FORMAT",
  "EVAL",
  "SUBST"
 };
-# elif SU_HAS_PERL(5, 9, 3)
+# elif XSH_HAS_PERL(5, 11, 0)
 static const char *su_block_type[] = {
  "NULL",
- "SUB",
- "EVAL",
  "WHEN",
- "SUBST",
  "BLOCK",
- "FORMAT",
  "GIVEN",
  "LOOP_FOR",
  "LOOP_PLAIN",
  "LOOP_LAZYSV",
- "LOOP_LAZYIV"
+ "LOOP_LAZYIV",
+ "SUB",
+ "FORMAT",
+ "EVAL",
+ "SUBST"
+};
+# elif XSH_HAS_PERL(5, 10, 0)
+static const char *su_block_type[] = {
+ "NULL",
+ "SUB",
+ "EVAL",
+ "LOOP",
+ "SUBST",
+ "BLOCK",
+ "FORMAT"
+ "WHEN",
+ "GIVEN"
 };
 # else
 static const char *su_block_type[] = {
@@ -1033,78 +1044,107 @@ static const char *su_block_type[] = {
  "EVAL",
  "LOOP",
  "SUBST",
- "BLOCK"
+ "BLOCK",
+ "FORMAT"
 };
 # endif
-# define SU_CXNAME(C) su_block_type[CxTYPE(C)]
+# define SU_CX_TYPENAME(T) su_block_type[(T)]
 #endif
 
+#define SU_CXNAME(C) SU_CX_TYPENAME(CxTYPE(C))
+
+/* for debugging. These indicate how many ENTERs each context type
+ * does before the PUSHBLOCK */
+
+static const int su_cxt_enter_count[] = {
+# if XSH_HAS_PERL(5, 23, 8)
+  0 /* context pushes no longer do ENTERs */
+# elif XSH_HAS_PERL(5, 11, 0)
+ /* NULL WHEN BLOCK GIVEN LOOP_FOR LOOP_PLAIN LOOP_LAZYSV
+  * LOOP_LAZYIV SUB FORMAT EVAL SUBST */
+ 0, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 0
+# elif XSH_HAS_PERL(5, 10, 0)
+ /* NULL SUB EVAL LOOP SUBST BLOCK FORMAT WHEN GIVEN */
+ 0, 1, 1, 2, 0, 1, 1, 1, 1
+# else
+ /* NULL SUB EVAL LOOP SUBST BLOCK FORMAT */
+ 0, 1, 1, 2, 0, 1, 1
+# endif
+};
+
+
+
+/* push at least 'size' slots worth of padding onto the savestack */
+
+static void su_ss_push_padding(pTHX_ void *ud, I32 size) {
+ if (size <= 0)
+  return;
+ if (size < SU_SAVE_ALLOC_SIZE + 1) /* minimum possible SAVEt_ALLOC */
+  size = SU_SAVE_ALLOC_SIZE + 1;
+ XSH_D(su_debug_log(
+        "%p:     push %2d padding at save_ix=%d\n",
+         ud, size, PL_savestack_ix));
+ save_alloc((size - SU_SAVE_ALLOC_SIZE)*sizeof(*PL_savestack), 0);
+}
+
+
+static void su_pop(pTHX_ void *ud);
+
+
+
+/* push an su_pop destructor onto the savestack with suitable padding.
+ * first indicates that this is the first push of a destructor */
+
+static void su_ss_push_destructor(pTHX_ void *ud, I32 depth, bool first) {
+ su_ud_origin_elem *origin = SU_UD_ORIGIN(ud);
+ I32 pad;
+
+ assert(first || origin[depth+1].orig_ix == PL_savestack_ix);
+ su_ss_push_padding(aTHX_ ud,
+    (origin[depth].orig_ix + origin[depth].offset) - PL_savestack_ix);
+ XSH_D(su_debug_log(
+        "%p:     push destructor at save_ix=%d depth=%d scope_ix=%d\n",
+         ud, PL_savestack_ix, depth, PL_scopestack_ix));
+ SAVEDESTRUCTOR_X(su_pop, ud);
+ assert(first ||
+        PL_savestack_ix <= origin[depth+1].orig_ix +  origin[depth+1].offset);
+}
+
+
+/* this is called during each leave_scope() via SAVEDESTRUCTOR_X */
+
 static void su_pop(pTHX_ void *ud) {
 #define su_pop(U) su_pop(aTHX_ (U))
- I32 depth, base, mark, *origin;
- depth = SU_UD_DEPTH(ud);
-
- SU_D(su_debug_log(
-  "%p: --- pop a %s\n"
-  "%p: leave scope     at depth=%2d scope_ix=%2d cur_top=%2d cur_base=%2d\n",
-   ud, SU_CXNAME(cxstack + cxstack_ix),
-   ud, depth, PL_scopestack_ix,PL_savestack_ix,PL_scopestack[PL_scopestack_ix]
- ));
+ I32 depth, base, mark;
+ su_ud_origin_elem *origin;
 
+ depth  = SU_UD_DEPTH(ud);
  origin = SU_UD_ORIGIN(ud);
- mark   = origin[depth];
- base   = origin[depth - 1];
 
- SU_D(su_debug_log("%p: original scope was %*c top=%2d     base=%2d\n",
-                    ud,                24, ' ',    mark,        base));
-
- if (base < mark) {
-#if SU_HAS_PERL(5, 19, 4)
-  I32 save = -1;
-  PERL_CONTEXT *cx;
-#endif
+ XSH_D(su_debug_log( "%p: ### su_pop: depth=%d\n", ud, depth));
 
-  SU_D(su_debug_log("%p: clear leftovers\n", ud));
+ depth--;
+ mark = PL_savestack_ix;
+ base = origin[depth].orig_ix;
 
-#if SU_HAS_PERL(5, 19, 4)
-  cx = cxstack + cxstack_ix;
-  if (CxTYPE(cx) == CXt_SUB || CxTYPE(cx) == CXt_FORMAT)
-   save = PL_scopestack[cx->blk_oldscopesp - 1];
-#endif
+ XSH_D(su_debug_log("%p:     residual savestack frame is %d(+%d)..%d\n",
+                     ud, base, origin[depth].offset, mark));
 
-  PL_savestack_ix = mark;
+ if (base < mark) {
+  XSH_D(su_debug_log("%p:     clear leftovers at %d..%d\n", ud, base, mark));
   leave_scope(base);
-
-#if SU_HAS_PERL(5, 19, 4)
-  if (CxTYPE(cx) == CXt_SUB || CxTYPE(cx) == CXt_FORMAT)
-   PL_scopestack[cx->blk_oldscopesp - 1] = save;
-#endif
  }
- PL_savestack_ix = base;
+ assert(PL_savestack_ix == base);
 
- SU_UD_DEPTH(ud) = --depth;
+ SU_UD_DEPTH(ud) = depth;
 
  if (depth > 0) {
-  U8 pad;
-
-  if ((pad = SU_UD_PAD(ud)) > 0) {
-   dMY_CXT;
-   do {
-    SU_D(su_debug_log(
-          "%p: push a pad slot at depth=%2d scope_ix=%2d save_ix=%2d\n",
-           ud,                       depth, PL_scopestack_ix, PL_savestack_ix));
-    SU_SAVE_PLACEHOLDER();
-   } while (--pad);
-  }
-
-  SU_D(su_debug_log(
-         "%p: push destructor at depth=%2d scope_ix=%2d save_ix=%2d\n",
-          ud,                        depth, PL_scopestack_ix, PL_savestack_ix));
-  SAVEDESTRUCTOR_X(su_pop, ud);
+  su_ss_push_destructor(aTHX_ ud, depth-1, 0);
  } else {
+  I32 offset = origin[0].offset; /* grab value before origin is freed */
   switch (SU_UD_TYPE(ud)) {
    case SU_UD_TYPE_REAP: {
-    SU_D(su_debug_log("%p: === reap\n%p: depth=%2d scope_ix=%2d save_ix=%2d\n",
+    XSH_D(su_debug_log("%p:     === reap\n%p: depth=%d scope_ix=%d save_ix=%d\n",
                    ud, ud, SU_UD_DEPTH(ud), PL_scopestack_ix, PL_savestack_ix));
     SAVEDESTRUCTOR_X(su_call, SU_UD_REAP_CB(ud));
     SU_UD_FREE(ud);
@@ -1118,112 +1158,193 @@ static void su_pop(pTHX_ void *ud) {
     SAVEDESTRUCTOR_X(su_uid_drop, ud);
     break;
   }
+  /* perl 5.23.8 onwards is very fussy about the return from leave_scope()
+   * leaving PL_savestack_ix where it expects it to be */
+  if (PL_savestack_ix < base + offset) {
+   I32 gap = (base + offset) - PL_savestack_ix;
+   assert(gap >= SU_SAVE_ALLOC_SIZE + 1);
+   su_ss_push_padding(aTHX_ ud, gap);
+  }
+  assert(PL_savestack_ix == base + offset);
  }
 
- SU_D(su_debug_log("%p: --- end pop: cur_top=%2d == cur_base=%2d\n",
-                    ud, PL_savestack_ix, PL_scopestack[PL_scopestack_ix]));
+ XSH_D(su_debug_log("%p:     end pop: ss_ix=%d\n", ud, PL_savestack_ix));
 }
 
+
 /* --- Initialize the stack and the action userdata ------------------------ */
 
-static I32 su_init(pTHX_ void *ud, I32 cxix, I32 size) {
+static void su_init(pTHX_ void *ud, I32 cxix, I32 size) {
 #define su_init(U, C, S) su_init(aTHX_ (U), (C), (S))
- I32 i, depth, offset, base, *origin;
- U8 pad;
+ I32 i, depth, base;
+ su_ud_origin_elem *origin;
+ I32 cur_cx_ix;
+ I32 cur_scope_ix;
 
- SU_D(su_debug_log("%p: ### init for cx %d\n", ud, cxix));
+ XSH_D(su_debug_log("%p: ### su_init(cxix=%d, size=%d)\n", ud, cxix, size));
 
- /* su_pop() is going to be called from leave_scope(), so before pushing the
-  * next callback, we'll want to flush the current scope stack slice first.
-  * However, if we want the next callback not to be processed immediately by
-  * the current leave_scope(), we'll need to hide it by artificially
-  * incrementing the scope stack marker before. For the intermediate bumps,
-  * we will only need a bump of SU_SAVE_DESTRUCTOR_SIZE items, but for the
-  * last one we will need a bump of size items. However, in order to preserve
-  * the natural ordering between scope stack markers, we cannot bump lower
-  * markers more than higher ones. This is why we bump the intermediate markers
-  * by the smallest multiple of SU_SAVE_PLACEHOLDER_SIZE greater or equal to
-  * max(SU_SAVE_DESTRUCTOR_SIZE, size). */
+ depth = PL_scopestack_ix - cxstack[cxix].blk_oldscopesp;
+#ifdef SU_HAS_NEW_CXT
+ depth += (cxstack_ix - cxix); /* each context frame holds 1 scope */
+#endif
+ XSH_D(su_debug_log(
+   "%p:     going down by depth=%d with scope_ix=%d save_ix=%d\n",
+    ud, depth, PL_scopestack_ix, PL_savestack_ix));
 
- if (size <= SU_SAVE_DESTRUCTOR_SIZE) {
-  pad = 0;
- } else {
-  I32 extra = size - SU_SAVE_DESTRUCTOR_SIZE;
-  pad = extra / SU_SAVE_PLACEHOLDER_SIZE;
-  if (extra % SU_SAVE_PLACEHOLDER_SIZE)
-   ++pad;
- }
- offset = SU_SAVE_DESTRUCTOR_SIZE + SU_SAVE_PLACEHOLDER_SIZE * pad;
- SU_D(su_debug_log("%p: size=%d pad=%d offset=%d\n", ud, size, pad, offset));
+ /* Artificially increase the position of each savestack frame boundary
+  * to make space to squeeze in a 'size' sized entry (first one) or a
+  * SU_SAVE_DESTRUCTOR_SIZE sized entry (higher ones). In addition, make
+  * sure that each boundary is higher than the previous, so that *every*
+  * scope exit triggers a call to leave_scope(). Each scope exit will call
+  * the su_pop() destructor, which is responsible for: freeing any
+  * savestack entries below the artificially raised floor; then pushing a
+  * new destructor in that space. On the final pop, the "real" savestack
+  * action is pushed rather than another destructor.
+  *
+  * On older perls, savestack frame boundaries are specified by a range of
+  * scopestack entries (one per ENTER). Each scope entry typically does
+  * one or two ENTERs followed by a PUSHBLOCK. Thus the
+  * cx->blku_oldscopesp field set by the PUSHBLOCK points to the next free
+  * slot, which is one above the last of the ENTERs. In the debugging
+  * output we indicate that by bracketing the ENTERs directly preceding
+  * that context push with dashes, e.g.:
+  *
+  *   13b98d8:     ------------------
+  *   13b98d8:                 ENTER origin[0] scope[3] savestack=3+3
+  *   13b98d8:                 ENTER origin[1] scope[4] savestack=9+3
+  *   13b98d8:     cx=1  LOOP_LAZYIV
+  *   13b98d8:     ------------------
+  *
+  * In addition to context stack pushes, other activities can push ENTERs
+  * too, such as grep expr and XS sub calls.
+  *
+  * For newer perls (SU_HAS_NEW_CXT), a context push no longer does any
+  * ENTERs; instead the old savestack position is stored in the new
+  * cx->blk_oldsaveix field; thus this field specifies an additional
+  * savestack frame boundary point in addition to the scopestack entries,
+  * and will also need adjusting.
+  *
+  * We record the original and modified position of each boundary in the
+  * origin array.
+  *
+  * The passed cxix argument represents the scope we wish to inject into;
+  * we have to adjust all the savestack frame boundaries above (but not
+  * including) that context. 
+  */
 
- depth = PL_scopestack_ix - cxstack[cxix].blk_oldscopesp;
- SU_D(su_debug_log("%p: going down to depth %d\n", ud, depth));
+ Newx(origin, depth, su_ud_origin_elem);
 
- /* We need to bump all the intermediary stack markers just in case an
-  * exception is thrown before the target scope is reached. Indeed, in this
-  * case there might be arbitrary many scope frames flushed at the same time,
-  * and since we cannot know in advance whether this will happen or not, we
-  * have to make sure the final frame is protected for the actual action. But
-  * of course, in order to do that, we also need to bump all the previous stack
-  * markers. If not for this, it should have been possible to just bump the two
-  * next frames in su_pop(). */
+ cur_cx_ix  = cxix;
+ cur_scope_ix = cxstack[cxix].blk_oldscopesp;
+#ifdef SU_HAS_NEW_CXT
+ XSH_D(su_debug_log("%p:     cx=%-2d %-11s\n",
+      ud, cur_cx_ix, SU_CXNAME(cxstack+cur_cx_ix)));
+ cur_cx_ix++;
+#endif
 
- Newx(origin, depth + 1, I32);
- base = PL_scopestack_ix - depth;
- origin[0] = PL_scopestack[base];
- PL_scopestack[base] += size;
- for (i = 1; i < depth; ++i) {
-  I32 j = i + base;
-  /* origin[depth - i] == PL_scopestack[PL_scopestack_ix - i] */
-  origin[i] = PL_scopestack[j];
-  PL_scopestack[j] += offset;
- }
- origin[depth] = PL_savestack_ix;
+ for (i = 0; cur_scope_ix < PL_scopestack_ix; i++) {
+  I32 *ixp;
+  I32 offset;
 
- SU_UD_PAD(ud)    = pad;
- SU_UD_DEPTH(ud)  = depth;
- SU_UD_ORIGIN(ud) = origin;
+#ifdef SU_HAS_NEW_CXT
 
- /* Make sure the first destructor fires by pushing enough fake slots on the
-  * stack. */
- if (PL_savestack_ix + SU_SAVE_DESTRUCTOR_SIZE
-                                       <= PL_scopestack[PL_scopestack_ix - 1]) {
-  dMY_CXT;
-  do {
-   SU_D(su_debug_log("%p: push a fake slot      at scope_ix=%2d  save_ix=%2d\n",
-                      ud,                   PL_scopestack_ix, PL_savestack_ix));
-   SU_SAVE_PLACEHOLDER();
-  } while (PL_savestack_ix + SU_SAVE_DESTRUCTOR_SIZE
-                                        <= PL_scopestack[PL_scopestack_ix - 1]);
- }
- SU_D(su_debug_log("%p: push first destructor at scope_ix=%2d  save_ix=%2d\n",
-                    ud,                     PL_scopestack_ix, PL_savestack_ix));
- SAVEDESTRUCTOR_X(su_pop, ud);
+  if (   cur_cx_ix <= cxstack_ix
+      && cur_scope_ix == cxstack[cur_cx_ix].blk_oldscopesp
+  )
+   ixp = &(cxstack[cur_cx_ix++].blk_oldsaveix);
+  else
+   ixp = &PL_scopestack[cur_scope_ix++]; /* an ENTER pushed after cur context */
 
- SU_D({
-  for (i = 0; i <= depth; ++i) {
-   I32 j = PL_scopestack_ix  - i;
-   su_debug_log("%p: depth=%2d scope_ix=%2d saved_floor=%2d new_floor=%2d\n",
-                 ud,         i,           j, origin[depth - i],
-                                   i == 0 ? PL_savestack_ix : PL_scopestack[j]);
+#else
+
+  XSH_D({
+   if (cur_cx_ix <= cxstack_ix) {
+    if (cur_scope_ix == cxstack[cur_cx_ix].blk_oldscopesp) {
+     su_debug_log(
+       "%p:     cx=%-2d %s\n%p:     ------------------\n",
+       ud, cur_cx_ix, SU_CXNAME(cxstack+cur_cx_ix), ud);
+     cur_cx_ix++;
+    }
+    else if (cur_scope_ix + su_cxt_enter_count[CxTYPE(cxstack+cur_cx_ix)]
+             == cxstack[cur_cx_ix].blk_oldscopesp)
+     su_debug_log("%p:     ------------------\n", ud);
+   }
+  });
+  ixp = &PL_scopestack[cur_scope_ix++];
+
+#endif
+
+  if (i == 0)
+   offset = size;
+  else {
+   /* we have three constraints to satisfy:
+    * 1) Each adjusted offset must be at least SU_SAVE_DESTRUCTOR_SIZE
+    *    above its unadjusted boundary, so that there is space to inject a
+    *    destructor into the outer scope.
+    * 2) Each adjusted boundary must be at least SU_SAVE_DESTRUCTOR_SIZE
+    *    higher than the previous adjusted boundary, so that a new
+    *    destructor can be added below the Nth adjusted frame boundary,
+    *    but be within the (N-1)th adjusted frame and so be triggered on
+    *    the next scope exit;
+    * 3) If the adjustment needs to be greater than SU_SAVE_DESTRUCTOR_SIZE,
+    *    then it should be greater by an amount of at least the minimum
+    *    pad side, so a destructor and padding can be pushed.
+    */
+   I32 pad;
+   offset = SU_SAVE_DESTRUCTOR_SIZE; /* rule 1 */
+   pad = (origin[i-1].orig_ix + origin[i-1].offset) + offset - (*ixp + offset);
+   if (pad > 0) { /* rule 2 */
+    if (pad < SU_SAVE_ALLOC_SIZE + 1) /* rule 3 */
+     pad = SU_SAVE_ALLOC_SIZE + 1;
+    offset += pad;
+   }
   }
- });
 
- return depth;
+  origin[i].offset = offset;
+  origin[i].orig_ix = *ixp;
+  *ixp += offset;
+
+#ifdef SU_HAS_NEW_CXT
+  XSH_D({
+   if (ixp == &PL_scopestack[cur_scope_ix-1])
+    su_debug_log(
+     "%p:           ENTER       origin[%d] scope[%d] savestack=%d+%d\n",
+      ud, i, cur_scope_ix, origin[i].orig_ix, origin[i].offset);
+   else
+    su_debug_log(
+     "%p:     cx=%-2d %-11s origin[%d] scope[%d] savestack=%d+%d\n",
+      ud, cur_cx_ix-1, SU_CXNAME(cxstack+cur_cx_ix-1),
+      i, cur_scope_ix, origin[i].orig_ix, origin[i].offset);
+  });
+#else
+  XSH_D(su_debug_log(
+    "%p:                 ENTER origin[%d] scope[%d] savestack=%d+%d\n",
+     ud, i, cur_scope_ix, origin[i].orig_ix, origin[i].offset));
+#endif
+
+ }
+
+ assert(i == depth);
+
+ SU_UD_DEPTH(ud)  = depth;
+ SU_UD_ORIGIN(ud) = origin;
+
+ su_ss_push_destructor(aTHX_ ud, depth-1, 1);
 }
 
+
 /* --- Unwind stack -------------------------------------------------------- */
 
 static void su_unwind(pTHX_ void *ud_) {
- dMY_CXT;
- I32 cxix  = MY_CXT.unwind_storage.cxix;
- I32 items = MY_CXT.unwind_storage.items;
+ dXSH_CXT;
+ I32 cxix  = XSH_CXT.unwind_storage.cxix;
+ I32 items = XSH_CXT.unwind_storage.items;
  I32 mark;
 
  PERL_UNUSED_VAR(ud_);
 
- PL_stack_sp = MY_CXT.unwind_storage.savesp;
-#if SU_HAS_PERL(5, 19, 4)
+ PL_stack_sp = XSH_CXT.unwind_storage.savesp;
+#if XSH_HAS_PERL(5, 19, 4)
  {
   I32 i;
   SV **sp = PL_stack_sp;
@@ -1237,28 +1358,28 @@ static void su_unwind(pTHX_ void *ud_) {
   dounwind(cxix);
 
  mark = PL_markstack[cxstack[cxix].blk_oldmarksp];
- *PL_markstack_ptr = PL_stack_sp - PL_stack_base - items;
+ PUSHMARK(PL_stack_sp - items);
 
- SU_D({
+ XSH_D({
   I32 gimme = GIMME_V;
   su_debug_log("%p: cx=%d gimme=%s items=%d sp=%d oldmark=%d mark=%d\n",
-                &MY_CXT, cxix,
+                &XSH_CXT, cxix,
                 gimme == G_VOID ? "void" : gimme == G_ARRAY ? "list" : "scalar",
                 items, PL_stack_sp - PL_stack_base, *PL_markstack_ptr, mark);
  });
 
- PL_op = (OP *) &(MY_CXT.unwind_storage.return_op);
+ PL_op = (OP *) &(XSH_CXT.unwind_storage.return_op);
  PL_op = PL_op->op_ppaddr(aTHX);
 
  *PL_markstack_ptr = mark;
 
- MY_CXT.unwind_storage.proxy_op.op_next = PL_op;
- PL_op = &(MY_CXT.unwind_storage.proxy_op);
+ XSH_CXT.unwind_storage.proxy_op.op_next = PL_op;
+ PL_op = &(XSH_CXT.unwind_storage.proxy_op);
 }
 
 /* --- Yield --------------------------------------------------------------- */
 
-#if SU_HAS_PERL(5, 10, 0)
+#if XSH_HAS_PERL(5, 10, 0)
 # define SU_RETOP_SUB(C)   ((C)->blk_sub.retop)
 # define SU_RETOP_EVAL(C)  ((C)->blk_eval.retop)
 # define SU_RETOP_LOOP(C)  ((C)->blk_loop.my_op->op_lastop->op_next)
@@ -1270,11 +1391,11 @@ static void su_unwind(pTHX_ void *ud_) {
 #endif
 
 static void su_yield(pTHX_ void *ud_) {
- dMY_CXT;
+ dXSH_CXT;
  PERL_CONTEXT *cx;
  const char   *which = ud_;
- I32 cxix      = MY_CXT.yield_storage.cxix;
- I32 items     = MY_CXT.yield_storage.items;
+ I32 cxix      = XSH_CXT.yield_storage.cxix;
+ I32 items     = XSH_CXT.yield_storage.items;
  opcode  type  = OP_NULL;
  U8      flags = 0;
  OP     *next;
@@ -1288,7 +1409,7 @@ static void su_yield(pTHX_ void *ud_) {
    OP *o = NULL;
    /* Is this actually a given/when block? This may occur only when yield was
     * called with HERE (or nothing) as the context. */
-#if SU_HAS_PERL(5, 10, 0)
+#if XSH_HAS_PERL(5, 10, 0)
    if (cxix > 0) {
     PERL_CONTEXT *prev = cx - 1;
     U8       prev_type = CxTYPE(prev);
@@ -1327,8 +1448,13 @@ static void su_yield(pTHX_ void *ud_) {
      case CXt_EVAL:
       o = SU_RETOP_EVAL(cx2);
       break;
-#if SU_HAS_PERL(5, 11, 0)
+#if XSH_HAS_PERL(5, 11, 0)
+# if XSH_HAS_PERL(5, 23, 8)
+     case CXt_LOOP_ARY:
+     case CXt_LOOP_LIST:
+# else
      case CXt_LOOP_FOR:
+# endif
      case CXt_LOOP_PLAIN:
      case CXt_LOOP_LAZYSV:
      case CXt_LOOP_LAZYIV:
@@ -1368,8 +1494,13 @@ static void su_yield(pTHX_ void *ud_) {
    type = CxTRYBLOCK(cx) ? OP_LEAVETRY : OP_LEAVEEVAL;
    next = SU_RETOP_EVAL(cx);
    break;
-#if SU_HAS_PERL(5, 11, 0)
+#if XSH_HAS_PERL(5, 11, 0)
+# if XSH_HAS_PERL(5, 23, 8)
+  case CXt_LOOP_ARY:
+  case CXt_LOOP_LIST:
+# else
   case CXt_LOOP_FOR:
+# endif
   case CXt_LOOP_PLAIN:
   case CXt_LOOP_LAZYSV:
   case CXt_LOOP_LAZYIV:
@@ -1379,7 +1510,7 @@ static void su_yield(pTHX_ void *ud_) {
    type = OP_LEAVELOOP;
    next = SU_RETOP_LOOP(cx);
    break;
-#if SU_HAS_PERL(5, 10, 0)
+#if XSH_HAS_PERL(5, 10, 0)
   case CXt_GIVEN:
 cxt_given:
    type = OP_LEAVEGIVEN;
@@ -1387,7 +1518,7 @@ cxt_given:
    break;
   case CXt_WHEN:
 cxt_when:
-#if SU_HAS_PERL(5, 15, 1)
+#if XSH_HAS_PERL(5, 15, 1)
    type   = OP_LEAVEWHEN;
 #else
    type   = OP_BREAK;
@@ -1405,8 +1536,8 @@ cxt_when:
    break;
  }
 
- PL_stack_sp = MY_CXT.yield_storage.savesp;
-#if SU_HAS_PERL(5, 19, 4)
+ PL_stack_sp = XSH_CXT.yield_storage.savesp;
+#if XSH_HAS_PERL(5, 19, 4)
  {
   I32 i;
   SV **sp = PL_stack_sp;
@@ -1427,16 +1558,16 @@ cxt_when:
 
  flags |= OP_GIMME_REVERSE(cx->blk_gimme);
 
- MY_CXT.yield_storage.leave_op.op_type   = type;
- MY_CXT.yield_storage.leave_op.op_ppaddr = PL_ppaddr[type];
- MY_CXT.yield_storage.leave_op.op_flags  = flags;
- MY_CXT.yield_storage.leave_op.op_next   = next;
+ XSH_CXT.yield_storage.leave_op.op_type   = type;
+ XSH_CXT.yield_storage.leave_op.op_ppaddr = PL_ppaddr[type];
+ XSH_CXT.yield_storage.leave_op.op_flags  = flags;
+ XSH_CXT.yield_storage.leave_op.op_next   = next;
 
- PL_op = (OP *) &(MY_CXT.yield_storage.leave_op);
+ PL_op = (OP *) &(XSH_CXT.yield_storage.leave_op);
  PL_op = PL_op->op_ppaddr(aTHX);
 
- MY_CXT.yield_storage.proxy_op.op_next = PL_op;
- PL_op = &(MY_CXT.yield_storage.proxy_op);
+ XSH_CXT.yield_storage.proxy_op.op_next = PL_op;
+ PL_op = &(XSH_CXT.yield_storage.proxy_op);
 }
 
 /* --- Uplevel ------------------------------------------------------------- */
@@ -1448,35 +1579,35 @@ static su_uplevel_ud *su_uplevel_storage
 #define su_uplevel_storage_new(I) su_uplevel_storage_new(aTHX_ (I))
  su_uplevel_ud *sud;
  UV depth;
- dMY_CXT;
+ dXSH_CXT;
 
- sud = MY_CXT.uplevel_storage.root;
+ sud = XSH_CXT.uplevel_storage.root;
  if (sud) {
-  MY_CXT.uplevel_storage.root = sud->next;
-  MY_CXT.uplevel_storage.count--;
+  XSH_CXT.uplevel_storage.root = sud->next;
+  XSH_CXT.uplevel_storage.count--;
  } else {
   sud = su_uplevel_ud_new();
  }
 
- sud->next = MY_CXT.uplevel_storage.top;
- MY_CXT.uplevel_storage.top = sud;
+ sud->next = XSH_CXT.uplevel_storage.top;
+ XSH_CXT.uplevel_storage.top = sud;
 
  depth = su_uid_depth(cxix);
- su_uid_storage_dup(&sud->tmp_uid_storage, &MY_CXT.uid_storage, depth);
- sud->old_uid_storage = MY_CXT.uid_storage;
- MY_CXT.uid_storage   = sud->tmp_uid_storage;
+ su_uid_storage_dup(&sud->tmp_uid_storage, &XSH_CXT.uid_storage, depth);
+ sud->old_uid_storage = XSH_CXT.uid_storage;
+ XSH_CXT.uid_storage  = sud->tmp_uid_storage;
 
  return sud;
 }
 
-#if SU_HAS_PERL(5, 13, 7)
+#if XSH_HAS_PERL(5, 13, 7)
 
 static void su_uplevel_storage_delete(pTHX_ su_uplevel_ud *sud) {
 #define su_uplevel_storage_delete(S) su_uplevel_storage_delete(aTHX_ (S))
- dMY_CXT;
+ dXSH_CXT;
 
- sud->tmp_uid_storage = MY_CXT.uid_storage;
- MY_CXT.uid_storage   = sud->old_uid_storage;
+ sud->tmp_uid_storage = XSH_CXT.uid_storage;
+ XSH_CXT.uid_storage   = sud->old_uid_storage;
  {
   su_uid *map;
   STRLEN  i, alloc;
@@ -1485,14 +1616,14 @@ static void su_uplevel_storage_delete(pT
   for (i = 0; i < alloc; ++i)
    map[i].flags &= ~SU_UID_ACTIVE;
  }
- MY_CXT.uplevel_storage.top = sud->next;
+ XSH_CXT.uplevel_storage.top = sud->next;
 
- if (MY_CXT.uplevel_storage.count >= SU_UPLEVEL_STORAGE_SIZE) {
+ if (XSH_CXT.uplevel_storage.count >= SU_UPLEVEL_STORAGE_SIZE) {
   su_uplevel_ud_delete(sud);
  } else {
-  sud->next = MY_CXT.uplevel_storage.root;
-  MY_CXT.uplevel_storage.root = sud;
-  MY_CXT.uplevel_storage.count++;
+  sud->next = XSH_CXT.uplevel_storage.root;
+  XSH_CXT.uplevel_storage.root = sud;
+  XSH_CXT.uplevel_storage.count++;
  }
 }
 
@@ -1521,7 +1652,7 @@ static int su_uplevel_goto_static(const 
  return 0;
 }
 
-#if SU_UPLEVEL_HIJACKS_RUNOPS
+#if !defined(SU_HAS_NEW_CXT) && SU_UPLEVEL_HIJACKS_RUNOPS
 
 static int su_uplevel_goto_runops(pTHX) {
 #define su_uplevel_goto_runops() su_uplevel_goto_runops(aTHX)
@@ -1554,9 +1685,9 @@ static int su_uplevel_goto_runops(pTHX) 
 
 done:
    if (argarray) {
-    dMY_CXT;
+    dXSH_CXT;
 
-    if (MY_CXT.uplevel_storage.top->cxix == cxix) {
+    if (XSH_CXT.uplevel_storage.top->cxix == cxix) {
      AV  *args  = GvAV(PL_defgv);
      I32  items = AvFILLp(args);
 
@@ -1569,7 +1700,7 @@ done:
 
   PL_op = op = op->op_ppaddr(aTHX);
 
-#if !SU_HAS_PERL(5, 13, 0)
+#if !XSH_HAS_PERL(5, 13, 0)
   PERL_ASYNC_CHECK();
 #endif
  } while (op);
@@ -1583,7 +1714,53 @@ done:
 
 #define su_at_underscore(C) PadARRAY(PadlistARRAY(CvPADLIST(C))[CvDEPTH(C)])[0]
 
-static void su_uplevel_restore(pTHX_ void *sus_) {
+#ifdef SU_HAS_NEW_CXT
+
+static void su_uplevel_restore_new(pTHX_ void *sus_) {
+ su_uplevel_ud *sud = sus_;
+ PERL_CONTEXT *cx;
+ I32 i;
+ U8 *saved_cxtypes = sud->cxtypes;
+
+ for (i = 0; i < sud->gap; i++) {
+  PERL_CONTEXT *cx = cxstack + sud->cxix + i;
+   XSH_D(su_debug_log("su_uplevel_restore: i=%d cxix=%d type %s => %s\n",
+        i, cx-cxstack, SU_CX_TYPENAME(CxTYPE(cx)),
+        SU_CX_TYPENAME(saved_cxtypes[i] & CXTYPEMASK)));
+   cx->cx_type = saved_cxtypes[i];
+ }
+ Safefree(saved_cxtypes);
+
+ /* renamed is a copy of callback, but they share the same CvPADLIST.
+  * At this point any calls to renamed should have exited so that its
+  * depth is back to that of of callback. At this point its safe to free
+  * renamed, then undo the extra ref count that was ensuring that callback
+  * remains alive
+  */
+ assert(sud->renamed);
+ assert(sud->callback);
+
+ CvDEPTH(sud->callback)--;
+ assert(CvDEPTH(sud->callback) == CvDEPTH(sud->renamed));
+ if (!CvISXSUB(sud->renamed)) {
+  CvDEPTH(sud->renamed)   = 0;
+  CvPADLIST(sud->renamed) = NULL;
+ }
+ SvREFCNT_dec(sud->renamed);
+ SvREFCNT_dec(sud->callback);
+
+ SU_UPLEVEL_RESTORE(curcop);
+
+ su_uplevel_storage_delete(sud);
+
+ return;
+}
+
+#else
+
+/* 5.23.7 and earlier */
+
+static void su_uplevel_restore_old(pTHX_ void *sus_) {
  su_uplevel_ud *sud = sus_;
  PERL_SI *cur = sud->old_curstackinfo;
  PERL_SI *si  = sud->si;
@@ -1689,7 +1866,7 @@ found_it:
    CvDEPTH(target) = sud->target_depth - levels;
    PL_curstackinfo->si_cxix = i - 1;
 
-#if !SU_HAS_PERL(5, 13, 1)
+#if !XSH_HAS_PERL(5, 13, 1)
    /* Since $@ was maybe localized between the target frame and the uplevel
     * call, we forcefully flush the save stack to get rid of it and then
     * reset $@ to its proper value. Note that the the call to
@@ -1723,28 +1900,30 @@ found_it:
   * pointer to the current context frame across this call. This means that we
   * can't free the temporary context stack we used for the uplevel call right
   * now, or that pointer upwards would point to garbage. */
-#if SU_HAS_PERL(5, 13, 7)
+#if XSH_HAS_PERL(5, 13, 7)
  /* This issue has been fixed in perl with commit 8f89e5a9, which was made
   * public in perl 5.13.7. */
  su_uplevel_storage_delete(sud);
 #else
  /* Otherwise, we just enqueue it back in the global storage list. */
  {
-  dMY_CXT;
+  dXSH_CXT;
 
-  sud->tmp_uid_storage = MY_CXT.uid_storage;
-  MY_CXT.uid_storage   = sud->old_uid_storage;
+  sud->tmp_uid_storage = XSH_CXT.uid_storage;
+  XSH_CXT.uid_storage  = sud->old_uid_storage;
 
-  MY_CXT.uplevel_storage.top  = sud->next;
-  sud->next = MY_CXT.uplevel_storage.root;
-  MY_CXT.uplevel_storage.root = sud;
-  MY_CXT.uplevel_storage.count++;
+  XSH_CXT.uplevel_storage.top  = sud->next;
+  sud->next = XSH_CXT.uplevel_storage.root;
+  XSH_CXT.uplevel_storage.root = sud;
+  XSH_CXT.uplevel_storage.count++;
  }
 #endif
 
  return;
 }
 
+#endif
+
 static CV *su_cv_clone(pTHX_ CV *proto, GV *gv) {
 #define su_cv_clone(P, G) su_cv_clone(aTHX_ (P), (G))
  dVAR;
@@ -1764,14 +1943,14 @@ static CV *su_cv_clone(pTHX_ CV *proto, 
 #endif
 
  CvGV_set(cv, gv);
-#if SU_RELEASE && SU_HAS_PERL_EXACT(5, 21, 4)
+#if SU_RELEASE && XSH_HAS_PERL_EXACT(5, 21, 4)
  CvNAMED_off(cv);
 #endif
  CvSTASH_set(cv, CvSTASH(proto));
  /* Commit 4c74a7df, publicized with perl 5.13.3, began to add backrefs to
   * stashes. CvSTASH_set() started to do it as well with commit c68d95645
   * (which was part of perl 5.13.7). */
-#if SU_HAS_PERL(5, 13, 3) && !SU_HAS_PERL(5, 13, 7)
+#if XSH_HAS_PERL(5, 13, 3) && !XSH_HAS_PERL(5, 13, 7)
  if (CvSTASH(proto))
   Perl_sv_add_backref(aTHX_ CvSTASH(proto), MUTABLE_SV(cv));
 #endif
@@ -1806,8 +1985,124 @@ static CV *su_cv_clone(pTHX_ CV *proto, 
  return cv;
 }
 
-static I32 su_uplevel(pTHX_ CV *callback, I32 cxix, I32 args) {
-#define su_uplevel(C, I, A) su_uplevel(aTHX_ (C), (I), (A))
+
+
+#ifdef SU_HAS_NEW_CXT
+
+/* this one-shot runops "loop" is designed to be called just before
+ * execution of the first op following an uplevel()'s entersub. It gets a
+ * chance to fix up the args as seen by caller(), before immediately
+ * falling through to the previous runops loop. Note that pp_entersub is
+ * called directly by call_sv() rather than being called from a runops
+ * loop.
+ */
+
+static int su_uplevel_runops_hook_entersub(pTHX) {
+ OP *op = PL_op;
+ dXSH_CXT;
+ su_uplevel_ud *sud = XSH_CXT.uplevel_storage.top;
+
+ /* Create a new array containing a copy of the original sub's call args,
+  * then stick it in PL_curpad[0] of the current running sub so that
+  * thay will be seen by caller().
+  */
+ assert(sud);
+ if (sud->argarray) {
+  AV *av = newAV();
+  AvREAL_off(av);
+  AvREIFY_on(av);
+  av_extend(av, AvMAX(sud->argarray));
+  AvFILLp(av) = AvFILLp(sud->argarray);
+  Copy(AvARRAY(sud->argarray), AvARRAY(av), AvFILLp(av) + 1, SV *);
+
+  /* should be referenced by PL_curpad[0] and *_ */
+  assert(SvREFCNT(PL_curpad[0]) > 1);
+  SvREFCNT_dec(PL_curpad[0]);
+
+  PL_curpad[0] = (SV*)av;
+ }
+
+ /* undo the temporary runops hook and fall through to a real runops loop. */
+ assert(sud->old_runops != su_uplevel_runops_hook_entersub);
+ PL_runops = sud->old_runops;
+ CALLRUNOPS(aTHX);
+ return 0;
+}
+
+
+
+static I32 su_uplevel_new(pTHX_ CV *callback, I32 cxix, I32 args) {
+ su_uplevel_ud *sud;
+ U8 *saved_cxtypes;
+ I32 i, ret;
+ I32  gimme;
+ CV *base_cv = cxstack[cxix].blk_sub.cv;
+ dSP;
+
+ assert(CxTYPE(&cxstack[cxix]) == CXt_SUB);
+
+ ENTER;
+
+ gimme = GIMME_V;
+
+ /* At this point SP points to the top arg.
+  * Shuffle the args down by one, eliminating the CV slot */
+ Move(SP - args + 1, SP - args, args, SV*);
+ SP--;
+ PUSHMARK(SP - args);
+ PUTBACK;
+
+ sud = su_uplevel_storage_new(cxix);
+
+ sud->cxix     = cxix;
+ sud->callback = (CV*)SvREFCNT_inc_simple(callback);
+ sud->renamed  = NULL;
+ sud->gap      = cxstack_ix - cxix + 1;
+ sud->argarray = NULL;
+
+
+ Newx(saved_cxtypes, sud->gap, U8);
+ sud->cxtypes = saved_cxtypes;
+
+ SAVEDESTRUCTOR_X(su_uplevel_restore_new, sud);
+ SU_UPLEVEL_SAVE(curcop, cxstack[cxix].blk_oldcop);
+
+/* temporarily change the type of any contexts to NULL, so they're
+ * invisible to caller() etc. */
+ for (i = 0; i < sud->gap; i++) {
+  PERL_CONTEXT *cx = cxstack + cxix + i;
+  saved_cxtypes[i] = cx->cx_type; /* save type and flags */
+  XSH_D(su_debug_log("su_uplevel: i=%d cxix=%d type %-11s => %s\n",
+        i, cx-cxstack, SU_CX_TYPENAME(CxTYPE(cx)), SU_CX_TYPENAME(CXt_NULL)));
+  cx->cx_type = (CXt_NULL | CXp_SU_UPLEVEL_NULLED);
+ }
+
+ /* create a copy of the callback with a doctored name (as seen by
+  * caller). It shares the padlist with callback */
+ sud->renamed = su_cv_clone(callback, CvGV(base_cv));
+ sud->old_runops = PL_runops;
+
+
+ if (!CvISXSUB(sud->renamed) && CxHASARGS(&cxstack[cxix])) {
+  sud->argarray = (AV*)su_at_underscore(base_cv);
+  assert(PL_runops != su_uplevel_runops_hook_entersub);
+  /* set up a one-shot runops hook so that we can fake up the
+   * args as seen by caller() on return from pp_entersub */
+  PL_runops = su_uplevel_runops_hook_entersub;
+ }
+
+ CvDEPTH(callback)++; /* match what CvDEPTH(sud->renamed) is about to become */
+
+ ret = call_sv((SV*)sud->renamed, gimme);
+
+ LEAVE;
+
+ return ret;
+}
+
+#else
+
+static I32 su_uplevel_old(pTHX_ CV *callback, I32 cxix, I32 args) {
  su_uplevel_ud *sud;
  const PERL_CONTEXT *cx = cxstack + cxix;
  PERL_SI *si;
@@ -1835,7 +2130,7 @@ static I32 su_uplevel(pTHX_ CV *callback
  sud->died     = 1;
  sud->callback = NULL;
  sud->renamed  = NULL;
- SAVEDESTRUCTOR_X(su_uplevel_restore, sud);
+ SAVEDESTRUCTOR_X(su_uplevel_restore_old, sud);
 
  si = sud->si;
 
@@ -1850,7 +2145,7 @@ static I32 su_uplevel(pTHX_ CV *callback
   * target context, plus the forthcoming arguments. */
  new_mark = cx->blk_oldsp;
  av_extend(si->si_stack, new_mark + 1 + args + 1);
- Copy(PL_curstack, AvARRAY(si->si_stack), new_mark + 1, SV *);
+ Copy(AvARRAY(PL_curstack), AvARRAY(si->si_stack), new_mark + 1, SV *);
  AvFILLp(si->si_stack) = new_mark;
  SU_POISON(AvARRAY(si->si_stack) + new_mark + 1, args + 1, SV *);
 
@@ -1920,6 +2215,7 @@ static I32 su_uplevel(pTHX_ CV *callback
 
  if ((PL_op = PL_ppaddr[OP_ENTERSUB](aTHX))) {
   PERL_CONTEXT *sub_cx = cxstack + cxstack_ix;
+  AV *argarray = cx->blk_sub.argarray;
 
   /* If pp_entersub() returns a non-null OP, it means that the callback is not
    * an XSUB. */
@@ -1927,7 +2223,7 @@ static I32 su_uplevel(pTHX_ CV *callback
   sud->callback = MUTABLE_CV(SvREFCNT_inc(callback));
   CvDEPTH(callback)++;
 
-  if (CxHASARGS(cx) && cx->blk_sub.argarray) {
+  if (CxHASARGS(cx) && argarray) {
    /* The call to pp_entersub() has saved the current @_ (in XS terms,
     * GvAV(PL_defgv)) in the savearray member, and has created a new argarray
     * with what we put on the stack. But we want to fake up the same arguments
@@ -1936,9 +2232,9 @@ static I32 su_uplevel(pTHX_ CV *callback
    AV *av = newAV();
    AvREAL_off(av);
    AvREIFY_on(av);
-   av_extend(av, AvMAX(cx->blk_sub.argarray));
-   AvFILLp(av) = AvFILLp(cx->blk_sub.argarray);
-   Copy(AvARRAY(cx->blk_sub.argarray), AvARRAY(av), AvFILLp(av) + 1, SV *);
+   av_extend(av, AvMAX(argarray));
+   AvFILLp(av) = AvFILLp(argarray);
+   Copy(AvARRAY(argarray), AvARRAY(av), AvFILLp(av) + 1, SV *);
    sub_cx->blk_sub.argarray = av;
   } else {
    SvREFCNT_inc_simple_void(sub_cx->blk_sub.argarray);
@@ -1985,16 +2281,18 @@ static I32 su_uplevel(pTHX_ CV *callback
  return ret;
 }
 
+#endif
+
 /* --- Unique context ID --------------------------------------------------- */
 
 static su_uid *su_uid_storage_fetch(pTHX_ UV depth) {
 #define su_uid_storage_fetch(D) su_uid_storage_fetch(aTHX_ (D))
  su_uid *map;
  STRLEN  alloc;
- dMY_CXT;
+ dXSH_CXT;
 
- map   = MY_CXT.uid_storage.map;
- alloc = MY_CXT.uid_storage.alloc;
+ map   = XSH_CXT.uid_storage.map;
+ alloc = XSH_CXT.uid_storage.alloc;
 
  if (depth >= alloc) {
   STRLEN i;
@@ -2005,12 +2303,12 @@ static su_uid *su_uid_storage_fetch(pTHX
    map[i].flags = 0;
   }
 
-  MY_CXT.uid_storage.map   = map;
-  MY_CXT.uid_storage.alloc = depth + 1;
+  XSH_CXT.uid_storage.map   = map;
+  XSH_CXT.uid_storage.alloc = depth + 1;
  }
 
- if (depth >= MY_CXT.uid_storage.used)
-  MY_CXT.uid_storage.used = depth + 1;
+ if (depth >= XSH_CXT.uid_storage.used)
+  XSH_CXT.uid_storage.used = depth + 1;
 
  return map + depth;
 }
@@ -2018,12 +2316,12 @@ static su_uid *su_uid_storage_fetch(pTHX
 static int su_uid_storage_check(pTHX_ UV depth, UV seq) {
 #define su_uid_storage_check(D, S) su_uid_storage_check(aTHX_ (D), (S))
  su_uid *uid;
- dMY_CXT;
+ dXSH_CXT;
 
- if (depth >= MY_CXT.uid_storage.used)
+ if (depth >= XSH_CXT.uid_storage.used)
   return 0;
 
- uid = MY_CXT.uid_storage.map + depth;
+ uid = XSH_CXT.uid_storage.map + depth;
 
  return (uid->seq == seq) && (uid->flags & SU_UID_ACTIVE);
 }
@@ -2127,7 +2425,7 @@ static I32 su_context_skip_db(pTHX_ I32 
   PERL_CONTEXT *cx = cxstack + i;
 
   switch (CxTYPE(cx)) {
-#if SU_HAS_PERL(5, 17, 1)
+#if XSH_HAS_PERL(5, 17, 1)
    case CXt_LOOP_PLAIN:
 #endif
    case CXt_BLOCK:
@@ -2151,6 +2449,57 @@ static I32 su_context_skip_db(pTHX_ I32 
 }
 
 
+#ifdef SU_HAS_NEW_CXT
+
+/* convert a physical context stack index into the logical equivalent:
+ * one that ignores all the context frames hidden by uplevel().
+ * Perl-level functions use logical args (e.g. UP takes an optional logical
+ * value and returns a logical value), while we use and store *real*
+ * values internally.
+ */
+
+static I32 su_context_real2logical(pTHX_ I32 cxix) {
+# define su_context_real2logical(C) su_context_real2logical(aTHX_ (C))
+ PERL_CONTEXT *cx;
+ I32 i, gaps = 0;
+
+ for (i = 0; i <= cxix; i++) {
+  cx = cxstack + i;
+  if (cx->cx_type == (CXt_NULL | CXp_SU_UPLEVEL_NULLED))
+   gaps++;
+ }
+ XSH_D(su_debug_log("su_context_real2logical: %d => %d\n", cxix, cxix - gaps));
+ return cxix - gaps;
+}
+
+/* convert a logical context stack index (one that ignores all the context
+ * frames hidden by uplevel) into the physical equivalent
+ */
+
+static I32 su_context_logical2real(pTHX_ I32 cxix) {
+# define su_context_logical2real(C) su_context_logical2real(aTHX_ (C))
+ PERL_CONTEXT *cx;
+ I32 i, seen = -1;
+
+ for (i = 0; i <= cxstack_ix; i++) {
+  PERL_CONTEXT *cx = cxstack + i;
+  if (cx->cx_type != (CXt_NULL | CXp_SU_UPLEVEL_NULLED))
+   seen++;
+  if (seen >= cxix)
+   break;
+ }
+ XSH_D(su_debug_log("su_context_logical2real: %d => %d\n", cxix, i));
+ if (i > cxstack_ix)
+  i = cxstack_ix;
+ return i;
+}
+
+#else
+# define su_context_real2logical(C) (C)
+# define su_context_logical2real(C) (C)
+#endif
+
+
 static I32 su_context_normalize_up(pTHX_ I32 cxix) {
 #define su_context_normalize_up(C) su_context_normalize_up(aTHX_ (C))
  PERL_CONTEXT *cx;
@@ -2163,11 +2512,11 @@ static I32 su_context_normalize_up(pTHX_
   PERL_CONTEXT *prev = cx - 1;
 
   switch (CxTYPE(prev)) {
-#if SU_HAS_PERL(5, 10, 0)
+#if XSH_HAS_PERL(5, 10, 0)
    case CXt_GIVEN:
    case CXt_WHEN:
 #endif
-#if SU_HAS_PERL(5, 11, 0)
+#if XSH_HAS_PERL(5, 11, 0)
    /* That's the only subcategory that can cause an extra BLOCK context */
    case CXt_LOOP_PLAIN:
 #else
@@ -2199,11 +2548,11 @@ static I32 su_context_normalize_down(pTH
   PERL_CONTEXT *cx = next - 1;
 
   switch (CxTYPE(cx)) {
-#if SU_HAS_PERL(5, 10, 0)
+#if XSH_HAS_PERL(5, 10, 0)
    case CXt_GIVEN:
    case CXt_WHEN:
 #endif
-#if SU_HAS_PERL(5, 11, 0)
+#if XSH_HAS_PERL(5, 11, 0)
    /* That's the only subcategory that can cause an extra BLOCK context */
    case CXt_LOOP_PLAIN:
 #else
@@ -2234,8 +2583,13 @@ static I32 su_context_gimme(pTHX_ I32 cx
 
   switch (CxTYPE(cx)) {
    /* gimme is always G_ARRAY for loop contexts. */
-#if SU_HAS_PERL(5, 11, 0)
+#if XSH_HAS_PERL(5, 11, 0)
+# if XSH_HAS_PERL(5, 23, 8)
+   case CXt_LOOP_ARY:
+   case CXt_LOOP_LIST:
+# else
    case CXt_LOOP_FOR:
+# endif
    case CXt_LOOP_PLAIN:
    case CXt_LOOP_LAZYSV:
    case CXt_LOOP_LAZYIV:
@@ -2267,83 +2621,61 @@ static I32 su_context_gimme(pTHX_ I32 cx
  return G_VOID;
 }
 
-/* --- Global setup/teardown ----------------------------------------------- */
-
-static VOL U32 su_initialized = 0;
+/* --- Module setup/teardown ----------------------------------------------- */
 
-static void su_global_teardown(pTHX_ void *root) {
- if (!su_initialized)
-  return;
+static void xsh_user_global_setup(pTHX) {
+ HV *stash;
 
-#if SU_MULTIPLICITY
- if (aTHX != root)
-  return;
-#endif
+ MUTEX_INIT(&su_uid_seq_counter_mutex);
 
- SU_LOCK(&su_uid_seq_counter_mutex);
- PerlMemShared_free(su_uid_seq_counter.seqs);
+ XSH_LOCK(&su_uid_seq_counter_mutex);
+ su_uid_seq_counter.seqs = NULL;
  su_uid_seq_counter.size = 0;
- SU_UNLOCK(&su_uid_seq_counter_mutex);
-
- MUTEX_DESTROY(&su_uid_seq_counter_mutex);
+ XSH_UNLOCK(&su_uid_seq_counter_mutex);
 
- su_initialized = 0;
+ stash = gv_stashpv(XSH_PACKAGE, 1);
+ newCONSTSUB(stash, "TOP",           newSViv(0));
+ newCONSTSUB(stash, "SU_THREADSAFE", newSVuv(XSH_THREADSAFE));
 
  return;
 }
 
-XS(XS_Scope__Upper_unwind);
-XS(XS_Scope__Upper_yield);
-XS(XS_Scope__Upper_leave);
-
-#if SU_HAS_PERL(5, 9, 0)
-# define SU_XS_FILE_TYPE const char
-#else
-# define SU_XS_FILE_TYPE char
-#endif
-
-static void su_global_setup(pTHX_ SU_XS_FILE_TYPE *file) {
-#define su_global_setup(F) su_global_setup(aTHX_ (F))
- HV *stash;
-
- if (su_initialized)
-  return;
+static void xsh_user_local_setup(pTHX_ xsh_user_cxt_t *cxt) {
 
- MUTEX_INIT(&su_uid_seq_counter_mutex);
+ /* NewOp() calls calloc() which just zeroes the memory with memset(). */
+ Zero(&(cxt->unwind_storage.return_op), 1, LISTOP);
+ cxt->unwind_storage.return_op.op_type   = OP_RETURN;
+ cxt->unwind_storage.return_op.op_ppaddr = PL_ppaddr[OP_RETURN];
 
- SU_LOCK(&su_uid_seq_counter_mutex);
- su_uid_seq_counter.seqs = NULL;
- su_uid_seq_counter.size = 0;
- SU_UNLOCK(&su_uid_seq_counter_mutex);
+ Zero(&(cxt->unwind_storage.proxy_op), 1, OP);
+ cxt->unwind_storage.proxy_op.op_type   = OP_STUB;
+ cxt->unwind_storage.proxy_op.op_ppaddr = NULL;
 
- stash = gv_stashpv(__PACKAGE__, 1);
- newCONSTSUB(stash, "TOP",           newSViv(0));
- newCONSTSUB(stash, "SU_THREADSAFE", newSVuv(SU_THREADSAFE));
+ Zero(&(cxt->yield_storage.leave_op), 1, UNOP);
+ cxt->yield_storage.leave_op.op_type   = OP_STUB;
+ cxt->yield_storage.leave_op.op_ppaddr = NULL;
 
- newXSproto("Scope::Upper::unwind", XS_Scope__Upper_unwind, file, NULL);
- newXSproto("Scope::Upper::yield",  XS_Scope__Upper_yield,  file, NULL);
- newXSproto("Scope::Upper::leave",  XS_Scope__Upper_leave,  file, NULL);
+ Zero(&(cxt->yield_storage.proxy_op), 1, OP);
+ cxt->yield_storage.proxy_op.op_type   = OP_STUB;
+ cxt->yield_storage.proxy_op.op_ppaddr = NULL;
 
-#if SU_MULTIPLICITY
- call_atexit(su_global_teardown, aTHX);
-#else
- call_atexit(su_global_teardown, NULL);
-#endif
+ cxt->uplevel_storage.top   = NULL;
+ cxt->uplevel_storage.root  = NULL;
+ cxt->uplevel_storage.count = 0;
 
- su_initialized = 1;
+ cxt->uid_storage.map   = NULL;
+ cxt->uid_storage.used  = 0;
+ cxt->uid_storage.alloc = 0;
 
  return;
 }
 
-/* --- Interpreter setup/teardown ------------------------------------------ */
-
-static void su_local_teardown(pTHX_ void *param) {
+static void xsh_user_local_teardown(pTHX_ xsh_user_cxt_t *cxt) {
  su_uplevel_ud *cur;
- dMY_CXT;
 
- Safefree(MY_CXT.uid_storage.map);
+ Safefree(cxt->uid_storage.map);
 
- cur = MY_CXT.uplevel_storage.root;
+ cur = cxt->uplevel_storage.root;
  if (cur) {
   su_uplevel_ud *prev;
   do {
@@ -2356,44 +2688,21 @@ static void su_local_teardown(pTHX_ void
  return;
 }
 
-static void su_local_setup(pTHX) {
-#define su_local_setup() su_local_setup(aTHX)
- MY_CXT_INIT;
-
- MY_CXT.stack_placeholder = NULL;
-
- /* NewOp() calls calloc() which just zeroes the memory with memset(). */
- Zero(&(MY_CXT.unwind_storage.return_op), 1, LISTOP);
- MY_CXT.unwind_storage.return_op.op_type   = OP_RETURN;
- MY_CXT.unwind_storage.return_op.op_ppaddr = PL_ppaddr[OP_RETURN];
-
- Zero(&(MY_CXT.unwind_storage.proxy_op), 1, OP);
- MY_CXT.unwind_storage.proxy_op.op_type   = OP_STUB;
- MY_CXT.unwind_storage.proxy_op.op_ppaddr = NULL;
-
- Zero(&(MY_CXT.yield_storage.leave_op), 1, UNOP);
- MY_CXT.yield_storage.leave_op.op_type   = OP_STUB;
- MY_CXT.yield_storage.leave_op.op_ppaddr = NULL;
-
- Zero(&(MY_CXT.yield_storage.proxy_op), 1, OP);
- MY_CXT.yield_storage.proxy_op.op_type   = OP_STUB;
- MY_CXT.yield_storage.proxy_op.op_ppaddr = NULL;
-
- MY_CXT.uplevel_storage.top   = NULL;
- MY_CXT.uplevel_storage.root  = NULL;
- MY_CXT.uplevel_storage.count = 0;
-
- MY_CXT.uid_storage.map   = NULL;
- MY_CXT.uid_storage.used  = 0;
- MY_CXT.uid_storage.alloc = 0;
+static void xsh_user_global_teardown(pTHX) {
+ XSH_LOCK(&su_uid_seq_counter_mutex);
+ PerlMemShared_free(su_uid_seq_counter.seqs);
+ su_uid_seq_counter.size = 0;
+ XSH_UNLOCK(&su_uid_seq_counter_mutex);
 
- call_atexit(su_local_teardown, NULL);
+ MUTEX_DESTROY(&su_uid_seq_counter_mutex);
 
  return;
 }
 
 /* --- XS ------------------------------------------------------------------ */
 
+/* D is real; B is logical. Returns real. */
+
 #define SU_GET_CONTEXT(A, B, D) \
  STMT_START {                   \
   if (items > A) {              \
@@ -2405,6 +2714,7 @@ static void su_local_setup(pTHX) {
     cxix = 0;                   \
    else if (cxix > cxstack_ix)  \
     goto default_cx;            \
+   cxix = su_context_logical2real(cxix); \
   } else {                      \
 default_cx:                     \
    cxix = (D);                  \
@@ -2424,7 +2734,7 @@ default_cx:                     \
   }                        \
  } STMT_END
 
-#if SU_HAS_PERL(5, 10, 0)
+#if XSH_HAS_PERL(5, 10, 0)
 # define SU_INFO_COUNT 11
 #else
 # define SU_INFO_COUNT 10
@@ -2436,7 +2746,7 @@ XS(XS_Scope__Upper_unwind) {
 #else
  dXSARGS;
 #endif
- dMY_CXT;
+ dXSH_CXT;
  I32 cxix;
 
  PERL_UNUSED_VAR(cv); /* -W */
@@ -2451,12 +2761,12 @@ XS(XS_Scope__Upper_unwind) {
      continue;
    case CXt_EVAL:
    case CXt_FORMAT:
-    MY_CXT.unwind_storage.cxix   = cxix;
-    MY_CXT.unwind_storage.items  = items;
-    MY_CXT.unwind_storage.savesp = PL_stack_sp;
+    XSH_CXT.unwind_storage.cxix   = cxix;
+    XSH_CXT.unwind_storage.items  = items;
+    XSH_CXT.unwind_storage.savesp = PL_stack_sp;
     if (items > 0) {
-     MY_CXT.unwind_storage.items--;
-     MY_CXT.unwind_storage.savesp--;
+     XSH_CXT.unwind_storage.items--;
+     XSH_CXT.unwind_storage.savesp--;
     }
     /* pp_entersub will want to sanitize the stack after returning from there
      * Screw that, we're insane!
@@ -2480,19 +2790,19 @@ XS(XS_Scope__Upper_yield) {
 #else
  dXSARGS;
 #endif
- dMY_CXT;
+ dXSH_CXT;
  I32 cxix;
 
  PERL_UNUSED_VAR(cv); /* -W */
  PERL_UNUSED_VAR(ax); /* -Wall */
 
  SU_GET_CONTEXT(0, items - 1, su_context_here());
- MY_CXT.yield_storage.cxix   = cxix;
- MY_CXT.yield_storage.items  = items;
- MY_CXT.yield_storage.savesp = PL_stack_sp;
+ XSH_CXT.yield_storage.cxix   = cxix;
+ XSH_CXT.yield_storage.items  = items;
+ XSH_CXT.yield_storage.savesp = PL_stack_sp;
  if (items > 0) {
-  MY_CXT.yield_storage.items--;
-  MY_CXT.yield_storage.savesp--;
+  XSH_CXT.yield_storage.items--;
+  XSH_CXT.yield_storage.savesp--;
  }
  /* See XS_Scope__Upper_unwind */
  if (GIMME_V == G_SCALAR)
@@ -2509,14 +2819,14 @@ XS(XS_Scope__Upper_leave) {
 #else
  dXSARGS;
 #endif
- dMY_CXT;
+ dXSH_CXT;
 
  PERL_UNUSED_VAR(cv); /* -W */
  PERL_UNUSED_VAR(ax); /* -Wall */
 
- MY_CXT.yield_storage.cxix   = su_context_here();
- MY_CXT.yield_storage.items  = items;
- MY_CXT.yield_storage.savesp = PL_stack_sp;
+ XSH_CXT.yield_storage.cxix   = su_context_here();
+ XSH_CXT.yield_storage.items  = items;
+ XSH_CXT.yield_storage.savesp = PL_stack_sp;
  /* See XS_Scope__Upper_unwind */
  if (GIMME_V == G_SCALAR)
   PL_stack_sp = PL_stack_base + PL_markstack_ptr[1] + 1;
@@ -2530,35 +2840,22 @@ PROTOTYPES: ENABLE
 
 BOOT:
 {
- su_global_setup(file);
- su_local_setup();
+ xsh_setup();
+ newXSproto("Scope::Upper::unwind", XS_Scope__Upper_unwind, file, NULL);
+ newXSproto("Scope::Upper::yield",  XS_Scope__Upper_yield,  file, NULL);
+ newXSproto("Scope::Upper::leave",  XS_Scope__Upper_leave,  file, NULL);
 }
 
-#if SU_THREADSAFE
+#if XSH_THREADSAFE
 
 void
 CLONE(...)
 PROTOTYPE: DISABLE
-PREINIT:
- su_uid_storage new_cxt;
 PPCODE:
- {
-  dMY_CXT;
-  new_cxt.map   = NULL;
-  new_cxt.used  = 0;
-  new_cxt.alloc = 0;
-  su_uid_storage_dup(&new_cxt, &MY_CXT.uid_storage, MY_CXT.uid_storage.used);
- }
- {
-  MY_CXT_CLONE;
-  MY_CXT.uplevel_storage.top   = NULL;
-  MY_CXT.uplevel_storage.root  = NULL;
-  MY_CXT.uplevel_storage.count = 0;
-  MY_CXT.uid_storage           = new_cxt;
- }
+ xsh_clone();
  XSRETURN(0);
 
-#endif /* SU_THREADSAFE */
+#endif /* XSH_THREADSAFE */
 
 void
 HERE()
@@ -2566,7 +2863,7 @@ PROTOTYPE:
 PREINIT:
  I32 cxix;
 PPCODE:
- cxix = su_context_here();
+ cxix = su_context_real2logical(su_context_here());
  EXTEND(SP, 1);
  mPUSHi(cxix);
  XSRETURN(1);
@@ -2582,6 +2879,7 @@ PPCODE:
   --cxix;
   cxix = su_context_skip_db(cxix);
   cxix = su_context_normalize_up(cxix);
+  cxix = su_context_real2logical(cxix);
  } else {
   warn(su_stack_smash);
  }
@@ -2605,6 +2903,7 @@ PPCODE:
    case CXt_SUB:
     if (PL_DBsub && cx->blk_sub.cv == GvCV(PL_DBsub))
      continue;
+    cxix = su_context_real2logical(cxix);
     mPUSHi(cxix);
     XSRETURN(1);
   }
@@ -2626,6 +2925,7 @@ PPCODE:
    default:
     continue;
    case CXt_EVAL:
+    cxix = su_context_real2logical(cxix);
     mPUSHi(cxix);
     XSRETURN(1);
   }
@@ -2649,6 +2949,7 @@ PPCODE:
   --cxix;
   cxix = su_context_skip_db(cxix);
   cxix = su_context_normalize_up(cxix);
+  cxix = su_context_real2logical(cxix);
  }
  EXTEND(SP, 1);
  mPUSHi(cxix);
@@ -2678,6 +2979,7 @@ done:
  if (level >= 0)
   warn(su_stack_smash);
  EXTEND(SP, 1);
+ cxix = su_context_real2logical(cxix);
  mPUSHi(cxix);
  XSRETURN(1);
 
@@ -2783,7 +3085,7 @@ PPCODE:
   case CXt_EVAL:
    if (CxOLD_OP_TYPE(cx) == OP_ENTEREVAL) {
     /* eval STRING */
-#if SU_HAS_PERL(5, 17, 4)
+#if XSH_HAS_PERL(5, 17, 4)
     PUSHs(newSVpvn_flags(SvPVX(cx->blk_eval.cur_text),
                          SvCUR(cx->blk_eval.cur_text)-2,
                          SvUTF8(cx->blk_eval.cur_text)|SVs_TEMP));
@@ -2810,7 +3112,7 @@ PPCODE:
  /* warnings (9) */
  {
   SV *mask = NULL;
-#if SU_HAS_PERL(5, 9, 4)
+#if XSH_HAS_PERL(5, 9, 4)
   STRLEN *old_warnings = cop->cop_warnings;
 #else
   SV *old_warnings = cop->cop_warnings;
@@ -2819,20 +3121,20 @@ PPCODE:
    if (PL_dowarn & G_WARN_ON)
     goto context_info_warnings_on;
    else
-#if SU_HAS_PERL(5, 17, 4)
+#if XSH_HAS_PERL(5, 17, 4)
     mask = &PL_sv_undef;
 #else
     goto context_info_warnings_off;
 #endif
   } else if (old_warnings == pWARN_NONE) {
-#if !SU_HAS_PERL(5, 17, 4)
+#if !XSH_HAS_PERL(5, 17, 4)
 context_info_warnings_off:
 #endif
    mask = su_newmortal_pvn(WARN_NONEstring, WARNsize);
   } else if (old_warnings == pWARN_ALL) {
    HV *bits;
 context_info_warnings_on:
-#if SU_HAS_PERL(5, 8, 7)
+#if XSH_HAS_PERL(5, 8, 7)
    bits = get_hv("warnings::Bits", 0);
    if (bits) {
     SV **bits_all = hv_fetchs(bits, "all", FALSE);
@@ -2843,7 +3145,7 @@ context_info_warnings_on:
    if (!mask)
     mask = su_newmortal_pvn(WARN_ALLstring, WARNsize);
   } else {
-#if SU_HAS_PERL(5, 9, 4)
+#if XSH_HAS_PERL(5, 9, 4)
    mask = su_newmortal_pvn((char *) (old_warnings + 1), old_warnings[0]);
 #else
    mask = sv_mortalcopy(old_warnings);
@@ -2851,7 +3153,7 @@ context_info_warnings_on:
   }
   PUSHs(mask);
  }
-#if SU_HAS_PERL(5, 10, 0)
+#if XSH_HAS_PERL(5, 10, 0)
  /* hints hash (10) */
  {
   COPHH *hints_hash = CopHINTHASH_get(cop);
@@ -2960,7 +3262,11 @@ PPCODE:
      args = items - 2;
     }
     /* su_uplevel() takes care of extending the stack if needed. */
-    ret = su_uplevel((CV *) code, cxix, args);
+#ifdef SU_HAS_NEW_CXT
+    ret = su_uplevel_new(aTHX_ (CV *) code, cxix, args);
+#else
+    ret = su_uplevel_old(aTHX_ (CV *) code, cxix, args);
+#endif
     XSRETURN(ret);
    default:
     break;
