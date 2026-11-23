--- contrib/jemalloc/src/extent_dss.c.orig	2026-11-10 11:00:25 UTC
+++ contrib/jemalloc/src/extent_dss.c
@@ -37,7 +37,7 @@ extent_dss_sbrk(intptr_t increment) {

 static void *
 extent_dss_sbrk(intptr_t increment) {
-#ifdef JEMALLOC_DSS
+#if 0
	return sbrk(increment);
 #else
	not_implemented();
