--- git-compat-util.h.orig	2016-03-21 10:34:43 UTC
+++ git-compat-util.h
@@ -715,8 +715,8 @@ static inline size_t st_add(size_t a, si
 		    (uintmax_t)a, (uintmax_t)b);
 	return a + b;
 }
-#define st_add3(a,b,c)   st_add((a),st_add((b),(c)))
-#define st_add4(a,b,c,d) st_add((a),st_add3((b),(c),(d)))
+#define st_add3(a,b,c)   st_add(st_add((a),(b)),(c))
+#define st_add4(a,b,c,d) st_add(st_add3((a),(b),(c)),(d))
 
 static inline size_t st_mult(size_t a, size_t b)
 {
