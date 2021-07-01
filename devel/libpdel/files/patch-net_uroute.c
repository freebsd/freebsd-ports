--- net/uroute.c.orig	2009-05-13 21:36:04 UTC
+++ net/uroute.c
@@ -41,9 +41,15 @@
 	((a) > 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
 #define ADVANCE(x, n)	((x) += ROUNDUP((n)->sa_len))
 
+#ifdef RTF_CLONING
 #define WRITABLE_FLAGS	(RTF_STATIC | RTF_LLINFO | RTF_REJECT | RTF_BLACKHOLE \
 			    | RTF_PROTO1 | RTF_PROTO2 | RTF_CLONING \
 			    | RTF_XRESOLVE | RTF_UP | RTF_GATEWAY)
+#else
+#define WRITABLE_FLAGS	(RTF_STATIC | RTF_REJECT | RTF_BLACKHOLE \
+			    | RTF_PROTO1 | RTF_PROTO2 \
+			    | RTF_XRESOLVE | RTF_UP | RTF_GATEWAY)
+#endif
 
 struct route_flag {
 	const char	*name;
@@ -59,15 +65,23 @@ static const	struct route_flag route_flags[] = {
 	FLAG(DYNAMIC),
 	FLAG(MODIFIED),
 	FLAG(DONE),
+#ifdef RTF_CLONING
 	FLAG(CLONING),
+#endif
 	FLAG(XRESOLVE),
+#ifdef RTF_LLINFO
 	FLAG(LLINFO),
+#endif
 	FLAG(STATIC),
 	FLAG(BLACKHOLE),
 	FLAG(PROTO2),
 	FLAG(PROTO1),
+#ifdef RTF_PRCLONING
 	FLAG(PRCLONING),
+#endif
+#ifdef RTF_WASCLONED
 	FLAG(WASCLONED),
+#endif
 	FLAG(PROTO3),
 	FLAG(PINNED),
 	FLAG(LOCAL),
