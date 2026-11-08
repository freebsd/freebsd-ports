--- src/pgsql/pgsql-create-schema.lisp.orig	2026-09-24 14:42:07 UTC
+++ src/pgsql/pgsql-create-schema.lisp
@@ -409,7 +409,7 @@ BEGIN
                   from replace(pg_get_expr(d.adbin, d.adrelid),
                                'nextval', 'setval'))
                || ', (select greatest(max(' || quote_ident(a.attname) || '), (select seqmin from pg_sequence where seqrelid = ('''
-               || pg_get_serial_sequence(quote_ident(nspname) || '.' || quote_ident(relname), quote_ident(a.attname)) || ''')::regclass limit 1), 1) from only '
+               || pg_get_serial_sequence(quote_ident(nspname) || '.' || quote_ident(relname), a.attname) || ''')::regclass limit 1), 1) from only '
                || quote_ident(nspname) || '.' || quote_ident(relname) || '));' as sql
          FROM pg_class c
               JOIN pg_namespace n on n.oid = c.relnamespace
