--- libraries/display_tbl.lib.php.orig	Sat Oct 18 23:32:07 2003
+++ libraries/display_tbl.lib.php	Mon Nov  3 15:32:22 2003
@@ -541,7 +541,7 @@
             echo '<input type="hidden" name="dontlimitchars" value="' . $dontlimitchars . '" />' . "\n";
             echo $GLOBALS['strSortByKey'] . ': <select name="sql_query">&nbsp;';
             $used_index = false;
-            $local_order = str_replace('  ', ' ', $sql_order);
+            $local_order = (isset($sql_order) ? str_replace('  ', ' ', $sql_order) : '');
             while (list($key, $val) = each($indexes_data)) {
                 $asc_sort = 'ORDER BY ';
                 $desc_sort = 'ORDER BY ';
