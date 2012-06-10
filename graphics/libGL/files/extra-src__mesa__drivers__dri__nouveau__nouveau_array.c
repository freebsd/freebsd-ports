--- src/mesa/drivers/dri/nouveau/nouveau_array.c.orig	2011-01-06 01:19:15.000000000 +0100
+++ src/mesa/drivers/dri/nouveau/nouveau_array.c	2012-04-28 18:27:06.000000000 +0200
@@ -29,54 +29,71 @@
 #include "nouveau_array.h"
 #include "nouveau_bufferobj.h"
 
+#define EXTRACT(in_t, out_t) extract_func_##in_t##_to_##out_t
+
+#define EXTRACT_FUNC(in_t, out_t, k)			\
+static out_t EXTRACT(in_t, out_t)			\
+(struct nouveau_array *a, int i, int j) {		\
+	in_t x = ((in_t *)(a->buf + i * a->stride))[j];	\
+							\
+	return (out_t)x / (k);				\
+}
+
+EXTRACT_FUNC(GLchar, unsigned, 1);
+EXTRACT_FUNC(GLchar, float, SCHAR_MAX);
+EXTRACT_FUNC(GLubyte, unsigned, 1);
+EXTRACT_FUNC(GLubyte, float, UCHAR_MAX);
+EXTRACT_FUNC(GLshort, unsigned, 1);
+EXTRACT_FUNC(GLshort, float, SHRT_MAX);
+EXTRACT_FUNC(GLushort, unsigned, 1);
+EXTRACT_FUNC(GLushort, float, USHRT_MAX);
+EXTRACT_FUNC(GLint, unsigned, 1);
+EXTRACT_FUNC(GLint, float, INT_MAX);
+EXTRACT_FUNC(GLuint, unsigned, 1);
+EXTRACT_FUNC(GLuint, float, UINT_MAX);
+EXTRACT_FUNC(GLfloat, unsigned, 1.0 / UINT_MAX);
+EXTRACT_FUNC(GLfloat, float, 1);
+
+#undef EXTRACT_FUNC
+
 static void
 get_array_extract(struct nouveau_array *a, extract_u_t *extract_u,
 		  extract_f_t *extract_f)
 {
-#define EXTRACT(in_t, out_t, k)						\
-	({								\
-		auto out_t f(struct nouveau_array *, int, int);		\
-		out_t f(struct nouveau_array *a, int i, int j) {	\
-			in_t x = ((in_t *)(a->buf + i * a->stride))[j];	\
-									\
-			return (out_t)x / (k);				\
-		};							\
-		f;							\
-	});
-
 	switch (a->type) {
 	case GL_BYTE:
-		*extract_u = EXTRACT(char, unsigned, 1);
-		*extract_f = EXTRACT(char, float, SCHAR_MAX);
+		*extract_u = EXTRACT(GLchar, unsigned);
+		*extract_f = EXTRACT(GLchar, float);
 		break;
 	case GL_UNSIGNED_BYTE:
-		*extract_u = EXTRACT(unsigned char, unsigned, 1);
-		*extract_f = EXTRACT(unsigned char, float, UCHAR_MAX);
+		*extract_u = EXTRACT(GLubyte, unsigned);
+		*extract_f = EXTRACT(GLubyte, float);
 		break;
 	case GL_SHORT:
-		*extract_u = EXTRACT(short, unsigned, 1);
-		*extract_f = EXTRACT(short, float, SHRT_MAX);
+		*extract_u = EXTRACT(GLshort, unsigned);
+		*extract_f = EXTRACT(GLshort, float);
 		break;
 	case GL_UNSIGNED_SHORT:
-		*extract_u = EXTRACT(unsigned short, unsigned, 1);
-		*extract_f = EXTRACT(unsigned short, float, USHRT_MAX);
+		*extract_u = EXTRACT(GLushort, unsigned);
+		*extract_f = EXTRACT(GLushort, float);
 		break;
 	case GL_INT:
-		*extract_u = EXTRACT(int, unsigned, 1);
-		*extract_f = EXTRACT(int, float, INT_MAX);
+		*extract_u = EXTRACT(GLint, unsigned);
+		*extract_f = EXTRACT(GLint, float);
 		break;
 	case GL_UNSIGNED_INT:
-		*extract_u = EXTRACT(unsigned int, unsigned, 1);
-		*extract_f = EXTRACT(unsigned int, float, UINT_MAX);
+		*extract_u = EXTRACT(GLuint, unsigned);
+		*extract_f = EXTRACT(GLuint, float);
 		break;
 	case GL_FLOAT:
-		*extract_u = EXTRACT(float, unsigned, 1.0 / UINT_MAX);
-		*extract_f = EXTRACT(float, float, 1);
+		*extract_u = EXTRACT(GLfloat, unsigned);
+		*extract_f = EXTRACT(GLfloat, float);
 		break;
 	default:
 		assert(0);
 	}
 }
+#undef EXTRACT
 
 void
 nouveau_init_array(struct nouveau_array *a, int attr, int stride,
