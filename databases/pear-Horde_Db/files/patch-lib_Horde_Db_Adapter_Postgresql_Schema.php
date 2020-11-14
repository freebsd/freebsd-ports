--- lib/Horde/Db/Adapter/Postgresql/Schema.php.orig	2017-02-27 11:00:17.000000000 +0100
+++ lib/Horde/Db/Adapter/Postgresql/Schema.php	2020-10-28 00:40:32.469743000 +0100
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
@@ -383,12 +388,13 @@ class Horde_Db_Adapter_Postgresql_Schema
     {
         /* @todo See if we can get this from information_schema instead */
         return $this->selectAll('
-            SELECT a.attname, format_type(a.atttypid, a.atttypmod), d.adsrc, a.attnotnull
-              FROM pg_attribute a LEFT JOIN pg_attrdef d
-                ON a.attrelid = d.adrelid AND a.attnum = d.adnum
-             WHERE a.attrelid = ' . $this->quote($tableName) . '::regclass
-               AND a.attnum > 0 AND NOT a.attisdropped
-             ORDER BY a.attnum', $name);
+          SELECT a.attname, format_type(a.atttypid, a.atttypmod),
+            pg_get_expr(d.adbin, d.adrelid) AS adsrc, a.attnotnull
+          FROM pg_attribute a
+          LEFT JOIN pg_attrdef d ON a.attrelid = d.adrelid AND a.attnum = d.adnum
+          WHERE a.attrelid = ' . $this->quote($tableName) . '::regclass
+            AND a.attnum > 0 AND NOT a.attisdropped
+          ORDER BY a.attnum;', $name);
     }
 
     /**
@@ -1057,13 +1063,32 @@ class Horde_Db_Adapter_Postgresql_Schema
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
@@ -1103,28 +1128,20 @@ class Horde_Db_Adapter_Postgresql_Schema
         $result = $this->selectOne($sql, 'PK and serial sequence');
 
         if (!$result) {
-            // If that fails, try parsing the primary key's default value.
-            // Support the 7.x and 8.0 nextval('foo'::text) as well as
-            // the 8.1+ nextval('foo'::regclass).
             $sql = "
-            SELECT attr.attname,
-              CASE
-                WHEN split_part(def.adsrc, '''', 2) ~ '.' THEN
-                  substr(split_part(def.adsrc, '''', 2),
-                         strpos(split_part(def.adsrc, '''', 2), '.')+1)
-                ELSE split_part(def.adsrc, '''', 2)
-              END AS relname
-            FROM pg_class       t
-            JOIN pg_attribute   attr ON (t.oid = attrelid)
-            JOIN pg_attrdef     def  ON (adrelid = attrelid AND adnum = attnum)
-            JOIN pg_constraint  cons ON (conrelid = adrelid AND adnum = conkey[1])
-            WHERE t.oid = '$table'::regclass
-              AND cons.contype = 'p'
-              AND def.adsrc ~* 'nextval'";
-
+              SELECT c.column_name, c.ordinal_position,
+                  pg_get_serial_sequence(t.table_name, c.column_name) as relname
+              FROM information_schema.key_column_usage AS c
+              LEFT JOIN information_schema.table_constraints AS t
+                ON t.constraint_name = c.constraint_name
+              WHERE t.table_name = '$table' AND t.constraint_type = 'PRIMARY KEY';";
             $result = $this->selectOne($sql, 'PK and custom sequence');
         }
 
+        if (!$result) {
+            return array(null, null);
+        }
+
         // [primary_key, sequence]
         return array($result['attname'], $result['relname']);
     }
@@ -1138,9 +1155,7 @@ class Horde_Db_Adapter_Postgresql_Schema
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
