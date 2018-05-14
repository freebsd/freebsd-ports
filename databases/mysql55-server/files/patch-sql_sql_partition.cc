--- sql/sql_partition.cc.orig	2018-05-14 15:35:48.089983000 +0200
+++ sql/sql_partition.cc	2018-05-14 15:36:03.185749000 +0200
@@ -283,7 +283,7 @@
     }
   }
   part_info->set_up_defaults_for_partitioning(table->file,
-                                              (ulonglong)0, (uint)0);
+                                              NULL, 0U);
   DBUG_RETURN(FALSE);
 }
 
