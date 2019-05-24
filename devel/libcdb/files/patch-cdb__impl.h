--- cdb_impl.h.orig	2018-06-11 23:57:47 UTC
+++ cdb_impl.h
@@ -5,7 +5,7 @@
 #ifndef	_CDB_IMPL_H
 #define	_CDB_IMPL_H
 
-#ifndef __NetBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 
 #define	__predict_false(exp)	__builtin_expect((exp) != 0, 0)
 
@@ -27,6 +27,9 @@ le32enc(void *buf, uint32_t u)
 	p[2] = (u >> 16) & 0xff;
 	p[3] = (u >> 24) & 0xff;
 }
+#endif
+
+#if !defined(__NetBSD__)
 
 void	 mi_vector_hash(const void * __restrict, size_t, uint32_t, uint32_t[3]);
 
