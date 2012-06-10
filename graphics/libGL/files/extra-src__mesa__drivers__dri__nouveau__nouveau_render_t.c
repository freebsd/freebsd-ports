--- src/mesa/drivers/dri/nouveau/nouveau_render_t.c.orig	2011-01-06 01:19:34.000000000 +0100
+++ src/mesa/drivers/dri/nouveau/nouveau_render_t.c	2012-04-28 18:27:06.000000000 +0200
@@ -97,52 +97,49 @@
 		}							\
 	} while (0)
 
-/*
- * Select an appropriate dispatch function for the given index buffer.
- */
-static dispatch_t
-get_array_dispatch(struct nouveau_array *a)
+static void
+dispatch_l(struct gl_context *ctx, unsigned int start, int delta,
+	   unsigned int n)
 {
-	if (!a->fields) {
-		auto void f(struct gl_context *, unsigned int, int, unsigned int);
-
-		void f(struct gl_context *ctx, unsigned int start, int delta,
-		       unsigned int n) {
-			struct nouveau_channel *chan = context_chan(ctx);
-			RENDER_LOCALS(ctx);
+	struct nouveau_channel *chan = context_chan(ctx);
+	RENDER_LOCALS(ctx);
 
-			EMIT_VBO(L, ctx, start, delta, n);
-		};
-
-		return f;
-
-	} else if (a->type == GL_UNSIGNED_INT) {
-		auto void f(struct gl_context *, unsigned int, int, unsigned int);
-
-		void f(struct gl_context *ctx, unsigned int start, int delta,
-		       unsigned int n) {
-			struct nouveau_channel *chan = context_chan(ctx);
-			RENDER_LOCALS(ctx);
+	EMIT_VBO(L, ctx, start, delta, n);
+}
 
-			EMIT_VBO(I32, ctx, start, delta, n);
-		};
+static void
+dispatch_i32(struct gl_context *ctx, unsigned int start, int delta,
+	     unsigned int n)
+{
+	struct nouveau_channel *chan = context_chan(ctx);
+	RENDER_LOCALS(ctx);
 
-		return f;
+	EMIT_VBO(I32, ctx, start, delta, n);
+}
 
-	} else {
-		auto void f(struct gl_context *, unsigned int, int, unsigned int);
+static void
+dispatch_i16(struct gl_context *ctx, unsigned int start, int delta,
+	     unsigned int n)
+{
+	struct nouveau_channel *chan = context_chan(ctx);
+	RENDER_LOCALS(ctx);
 
-		void f(struct gl_context *ctx, unsigned int start, int delta,
-		       unsigned int n) {
-			struct nouveau_channel *chan = context_chan(ctx);
-			RENDER_LOCALS(ctx);
-
-			EMIT_VBO(I32, ctx, start, delta, n & 1);
-			EMIT_VBO(I16, ctx, start, delta, n & ~1);
-		};
+	EMIT_VBO(I32, ctx, start, delta, n & 1);
+	EMIT_VBO(I16, ctx, start, delta, n & ~1);
+}
 
-		return f;
-	}
+/*
+ * Select an appropriate dispatch function for the given index buffer.
+ */
+static dispatch_t
+get_array_dispatch(struct nouveau_array *a)
+{
+	if (!a->fields)
+		return dispatch_l;
+	else if (a->type == GL_UNSIGNED_INT)
+		return dispatch_i32;
+	else
+		return dispatch_i16;
 }
 
 /*
