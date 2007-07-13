--- arpc/xdr_suio.h.orig	2005-11-01 16:20:27.000000000 +0000
+++ arpc/xdr_suio.h	2007-07-12 22:38:48.000000000 +0000
@@ -26,7 +26,8 @@
 static inline suio *&
 xsuio (XDR *x)
 {
-  return (suio *&) x->x_private;
+  void *& ptr = (void *&) x->x_private;
+  return (suio *&)ptr;
 }
 
 extern "C" {
