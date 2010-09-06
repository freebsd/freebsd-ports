--- src/http.h	2010-05-08 19:56:15 +0000
+++ src/http.h	2010-07-28 19:22:22 +0000
@@ -33,8 +33,8 @@
 
 struct url;
 
-uerr_t http_loop (struct url *, char **, char **, const char *, int *,
-		  struct url *, struct iri *);
+uerr_t http_loop (struct url *, struct url *, char **, char **, const char *,
+                  int *, struct url *, struct iri *);
 void save_cookies (void);
 void http_cleanup (void);
 time_t http_atotm (const char *);

=== modified file 'src/init.c'
