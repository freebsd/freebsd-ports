--- src/pulsecore/refcnt.h.orig	Wed Jul 11 23:44:24 2007
+++ src/pulsecore/refcnt.h	Wed Jul 11 23:49:59 2007
@@ -36,7 +36,7 @@
   pa_atomic_inc(&p->_ref)
 
 #define PA_REFCNT_DEC(p) \
-  (pa_atomic_dec(&p->_ref)-1)
+  pa_atomic_dec(&p->_ref)
 
 #define PA_REFCNT_VALUE(p) \
   pa_atomic_load(&p->_ref)
