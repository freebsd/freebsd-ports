--- src/include/catalog/pg_proc.h	27 Feb 2004 11:57:12 -0000	1.1.1.1
+++ src/include/catalog/pg_proc.h	6 Apr 2004 12:44:53 -0000	1.2
@@ -3117,6 +3117,8 @@
 DATA(insert OID = 2307 (  opaque_out		PGNSP PGUID 12 f f t f i 1 2275 "2282"	opaque_out - _null_ ));
 DESCR("(internal)");
 
+DATA(insert OID = 2400 (  pgr_current_replicator	PGNSP PGUID 12 f f t f v 0 25 "" pgr_current_replicator - _null_ ));
+DESCR("Current replication server");
 
 /*
  * Symbolic values for provolatile column: these indicate whether the result
