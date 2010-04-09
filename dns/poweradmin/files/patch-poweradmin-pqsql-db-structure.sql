--- docs/poweradmin-pgsql-db-structure.sql.orig	2010-03-14 17:18:54.000000000 +0200
+++ docs/poweradmin-pgsql-db-structure.sql	2010-03-14 17:28:38.000000000 +0200
@@ -63,3 +63,20 @@
 );
 
 CREATE INDEX zone_domain_owner ON zones(domain_id, owner);
+
+CREATE TABLE zone_templ (
+  id SERIAL PRIMARY KEY,
+  name varchar(128) NOT NULL,
+  descr text NOT NULL,
+  owner integer default 0
+);
+
+CREATE TABLE zone_templ_records (
+  id SERIAL PRIMARY KEY,
+  zone_templ_id integer NOT NULL,
+  name varchar(255) NOT NULL,
+  type varchar(6) NOT NULL,
+  content varchar(255) NOT NULL,
+  ttl integer default NULL,
+  prio integer default NULL 
+);
