retrieving revision 1.38
retrieving revision 1.39
diff -u -r1.38 -r1.39
--- tbl_relation.php.orig	2003/09/09 08:26:43	1.38
+++ tbl_relation.php		2003/10/21 17:08:20	1.39
@@ -1,5 +1,5 @@
 <?php
-/* $Id: tbl_relation.php,v 1.38 2003/09/09 08:26:43 nijel Exp $ */
+/* $Id: tbl_relation.php,v 1.39 2003/10/21 17:08:20 lem9 Exp $ */
 // vim: expandtab sw=4 ts=4 sts=4:
 
 /**
@@ -280,6 +280,9 @@
                         $selectboxall[$field_full] =  $field_v;
                         // there could be more than one segment of the primary
                         // so do not break
+
+                        // Please watch here, tbl_type is INNODB but the
+                        // resulting value of SHOW KEYS is InnoDB
                       
                         if ($tbl_type=='INNODB' && isset($curr_table[1]) && $curr_table[1]=='InnoDB') {
                         $selectboxall_innodb[$field_full] =  $field_v;
@@ -295,6 +298,13 @@
                         if ($tbl_type=='INNODB' && isset($curr_table[1]) && $curr_table[1]=='InnoDB') {
                         $selectboxall_innodb[$field_full] =  $field_v;
                         }
+
+                    // for InnoDB, any index is allowed
+                    } else if ($tbl_type=='INNODB' && isset($curr_table[1]) && $curr_table[1]=='InnoDB') {
+                        $field_full = $db . '.' . $curr_field['Table'] . '.' . $curr_field['Column_name'];
+                        $field_v    = $curr_field['Table'] . '->' . $curr_field['Column_name'];
+                        $selectboxall_innodb[$field_full] =  $field_v;
+
                     } // end if
                 } // end while over keys
             } // end if (mysql_num_rows)
