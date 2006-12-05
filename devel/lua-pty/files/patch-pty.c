--- pty.c.orig	Wed Nov 29 21:26:24 2006
+++ pty.c	Wed Nov 29 21:29:38 2006
@@ -66,6 +66,15 @@
 #define WEXIT_TYPE union wait
 #endif
 
+#ifndef lua_boxpointer
+#define lua_boxpointer(L,u) \
+	(*(void **)(lua_newuserdata(L, sizeof(void *))) = (u))
+#endif
+
+#ifndef lua_unboxpointer
+#define lua_unboxpointer(L,i)   (*(void **)(lua_touserdata(L, i)))
+#endif
+
 struct lua_pty {
 	FILE		*stream;
 	pid_t		 child;
