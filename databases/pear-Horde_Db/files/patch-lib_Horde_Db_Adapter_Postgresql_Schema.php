--- lib/Horde/Db/Adapter/Postgresql/Schema.php.orig	2017-02-27 10:00:17 UTC
+++ lib/Horde/Db/Adapter/Postgresql/Schema.php
@@ -3,12 +3,15 @@
  * Copyright 2007 Maintainable Software, LLC
  * Copyright 2008-2017 Horde LLC (http://www.horde.org/)
  *
+ * See the enclosed file LICENSE for license information (BSD). If you
+ * did not receive this file, see http://www.horde.org/licenses/bsd.
+ *
  * @author     Mike Naberezny <mike@maintainable.com>
  * @author     Derek DeVries <derek@maintainable.com>
  * @author     Chuck Hagenbuch <chuck@horde.org>
  * @author     Jan Schneider <jan@horde.org>
- * @license    http://www.horde.org/licenses/bsd
  * @category   Horde
+ * @license    http://www.horde.org/licenses/bsd
  * @package    Db
  * @subpackage Adapter
  */
@@ -21,8 +24,10 @@
  * @author     Derek DeVries <derek@maintainable.com>
  * @author     Chuck Hagenbuch <chuck@horde.org>
  * @author     Jan Schneider <jan@horde.org>
- * @license    http://www.horde.org/licenses/bsd
  * @category   Horde
+ * @copyright  2007 Maintainable Software, LLC
+ * @copyright  2008-2017 Horde LLC
+ * @license    http://www.horde.org/licenses/bsd
  * @package    Db
  * @subpackage Adapter
  */
@@ -1057,13 +1062,32 @@ class Horde_Db_Adapter_Postgresql_Schema extends Horde
                 $quotedSequence = $this->quoteSequenceName($sequence);
                 $quotedTable = $this->quoteTableName($table);
                 $quotedPk = $this->quoteColumnName($pk);
-
-                $sql = sprintf('SELECT setval(%s, (SELECT COALESCE(MAX(%s) + (SELECT increment_by FROM %s), (SELECT min_value FROM %s)) FROM %s), false)',
-                               $quotedSequence,
-                               $quotedPk,
-                               $sequence,
-                               $sequence,
-                               $quotedTable);
+                if ($this->postgresqlVersion() >= 100000) {
+                    $sql = sprintf('
+                        SELECT setval(
+                            %s,
+                            (SELECT COALESCE(
+                                MAX(%s) + (SELECT increment_by FROM pg_sequences WHERE schemaname=ANY(CURRENT_SCHEMAS(false)) AND sequencename=%s),
+                                (SELECT min_value FROM pg_sequences WHERE schemaname=ANY(CURRENT_SCHEMAS(false)) AND sequencename=%s)
+                             ) FROM %s),
+                             false
+                         )',
+                         $quotedSequence,
+                         $quotedPk,
+                         $quotedSequence,
+                         $quotedSequence,
+                         $quotedTable
+                    );
+                } else {
+                    $sql = sprintf(
+                        'SELECT setval(%s, (SELECT COALESCE(MAX(%s) + (SELECT increment_by FROM %s), (SELECT min_value FROM %s)) FROM %s), false)',
+                        $quotedSequence,
+                        $quotedPk,
+                        $sequence,
+                        $sequence,
+                        $quotedTable
+                    );
+                }
                 $this->selectValue($sql, 'Reset sequence');
             } else {
                 if ($this->_logger) {
@@ -1138,9 +1162,7 @@ class Horde_Db_Adapter_Postgresql_Schema extends Horde
     {
         if (!$this->_version) {
             try {
-                $version = $this->selectValue('SELECT version()');
-                if (preg_match('/PostgreSQL (\d+)\.(\d+)\.(\d+)/', $version, $matches))
-                    $this->_version = ($matches[1] * 10000) + ($matches[2] * 100) + $matches[3];
+                $this->_version = $this->selectValue('SHOW server_version_num');
             } catch (Exception $e) {
                 return 0;
             }
