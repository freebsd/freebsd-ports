--- src/include/catalog/pg_proc.h.orig	Tue Feb 24 23:17:16 2004
+++ src/include/catalog/pg_proc.h	Tue Feb 24 23:28:44 2004
@@ -3117,7 +3117,8 @@
 DATA(insert OID = 2307 (  opaque_out		PGNSP PGUID 12 f f t f i 1 2275 "2282"	opaque_out - _null_ ));
 DESCR("(internal)");
 
-
+DATA(insert OID = 2400 (  pgr_current_replicator	PGNSP PGUID 12 f f t f v 0 25 "" pgr_current_replicator - _null_ ));
+DESCR("Current replication server");
 /*
  * Symbolic values for provolatile column: these indicate whether the result
  * of a function is dependent *only* on the values of its explicit arguments,
