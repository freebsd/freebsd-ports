Backport of https://github.com/jorisvink/kore/commit/c071d64bdddacbe1b69d238e14994d666a86f7cf
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

--- src/pgsql.c.orig	2016-08-01 07:59:32 UTC
+++ src/pgsql.c
@@ -219,13 +219,11 @@ kore_pgsql_query_params(struct kore_pgsq
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
