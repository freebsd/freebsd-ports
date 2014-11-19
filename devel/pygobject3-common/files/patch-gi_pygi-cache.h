From 3b70f5bc8e59e49795fcaa7b285aeff0c4565a04 Mon Sep 17 00:00:00 2001
From: Simon Feltman <sfeltman@src.gnome.org>
Date: Mon, 27 Oct 2014 20:19:23 -0700
Subject: Remove redefinitions of function and vfunc cache typedefs

https://bugzilla.gnome.org/show_bug.cgi?id=737874

diff --git a/gi/pygi-cache.h b/gi/pygi-cache.h
index 093dde2..0361f00 100644
--- gi/pygi-cache.h
+++ gi/pygi-cache.h
@@ -197,7 +197,7 @@ struct _PyGICallableCache
                                      GICallableInfo *callable_info);
 };
 
-typedef struct _PyGIFunctionCache {
+struct _PyGIFunctionCache {
     PyGICallableCache callable_cache;
 
     /* An invoker with ffi_cif already setup */
@@ -207,13 +207,13 @@ typedef struct _PyGIFunctionCache {
                          PyGIInvokeState *state,
                          PyObject *py_args,
                          PyObject *py_kwargs);
-} PyGIFunctionCache;
+} ;
 
-typedef struct _PyGIVFuncCache {
+struct _PyGIVFuncCache {
     PyGIFunctionWithInstanceCache fwi_cache;
 
     GIBaseInfo *info;
-} PyGIVFuncCache;
+};
 
 
 gboolean
-- 
cgit v0.10.1

