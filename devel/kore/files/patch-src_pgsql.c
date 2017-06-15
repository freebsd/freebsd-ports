Backports of

https://github.com/jorisvink/kore/commit/c071d64bdddacbe1b69d238e14994d666a86f7cf
so compiling on FreeBSD 10.x/i386 succeeds.  Without it the build will fail with:

src/pgsql.c:222:6: error: variable 'args' is used uninitialized whenever 'if' condition is false [-Werror,-Wsometimes-uninitialized]
        if (count > 0)
            ^~~~~~~~~
src/pgsql.c:225:63: note: uninitialized use occurs here
        ret = kore_pgsql_v_query_params(pgsql, query, result, count, args);
                                                                     ^~~~
src/pgsql.c:222:2: note: remove the 'if' if its condition is always true
        if (count > 0)
        ^~~~~~~~~~~~~~
src/pgsql.c:220:15: note: initialize the variable 'args' to silence this warning
        va_list         args;
                            ^
                             = NULL
1 error generated.

and https://github.com/jorisvink/kore/commit/7eced6f035c83c02680d9b58371851f8662a0e8a
so that compiling with Clang 3.9 succeeds.  Without it the build will fail with:

src/pgsql.c:222:17: error: passing an object that undergoes default argument promotion to 'va_start'
      has undefined behavior [-Werror,-Wvarargs]
        va_start(args, count);
                       ^
src/pgsql.c:217:45: note: parameter of type 'u_int8_t' (aka 'unsigned char') is declared here
    const char *query, int result, u_int8_t count, ...)
 
--- src/pgsql.c.orig	2016-08-01 07:59:32 UTC
+++ src/pgsql.c
@@ -151,7 +151,7 @@ kore_pgsql_query(struct kore_pgsql *pgsq
 
 int
 kore_pgsql_v_query_params(struct kore_pgsql *pgsql,
-    const char *query, int result, u_int8_t count, va_list args)
+    const char *query, int result, int count, va_list args)
 {
 	u_int8_t	i;
 	char		**values;
@@ -214,18 +214,16 @@ cleanup:
 
 int
 kore_pgsql_query_params(struct kore_pgsql *pgsql,
-    const char *query, int result, u_int8_t count, ...)
+    const char *query, int result, int count, ...)
 {
 	int		ret;
 	va_list		args;
 
-	if (count > 0)
-		va_start(args, count);
+	va_start(args, count);
 
 	ret = kore_pgsql_v_query_params(pgsql, query, result, count, args);
 
-	if (count > 0)
-		va_end(args);
+	va_end(args);
 
 	return (ret);
 }
