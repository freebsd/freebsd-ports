--- includes/pgsql.h.orig	2016-08-01 07:59:32 UTC
+++ includes/pgsql.h
@@ -66,9 +66,9 @@ void	kore_pgsql_cleanup(struct kore_pgsq
 void	kore_pgsql_continue(struct http_request *, struct kore_pgsql *);
 int	kore_pgsql_query(struct kore_pgsql *, const char *);
 int	kore_pgsql_query_params(struct kore_pgsql *,
-	    const char *, int, u_int8_t, ...);
+	    const char *, int, int, ...);
 int	kore_pgsql_v_query_params(struct kore_pgsql *,
-	    const char *, int, u_int8_t, va_list);
+	    const char *, int, int, va_list);
 int	kore_pgsql_register(const char *, const char *);
 int	kore_pgsql_ntuples(struct kore_pgsql *);
 void	kore_pgsql_logerror(struct kore_pgsql *);
