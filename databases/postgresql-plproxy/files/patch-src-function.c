--- src/function.c.orig	2017-10-08 08:53:35 UTC
+++ src/function.c
@@ -214,8 +214,13 @@ fn_returns_dynamic_record(HeapTuple proc
 	Form_pg_proc proc_struct;
 	proc_struct = (Form_pg_proc) GETSTRUCT(proc_tuple);
 	if (proc_struct->prorettype == RECORDOID
+#if PG_VERSION_NUM >= 110000
+		&& (heap_attisnull(proc_tuple, Anum_pg_proc_proargmodes, NULL)
+		    || heap_attisnull(proc_tuple, Anum_pg_proc_proargnames, NULL)))
+#else
 		&& (heap_attisnull(proc_tuple, Anum_pg_proc_proargmodes)
 		    || heap_attisnull(proc_tuple, Anum_pg_proc_proargnames)))
+#endif
 		return true;
 	return false;
 }
