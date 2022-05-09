--- libraries/adodb/drivers/adodb-postgres64.inc.php.orig	2020-11-07 06:09:12 UTC
+++ libraries/adodb/drivers/adodb-postgres64.inc.php
@@ -122,6 +122,11 @@ WHERE relkind in ('r','v') AND (c.relname='%s' or c.re
 	// changes the metaColumnsSQL, adds columns: attnum[6]
 	}
 	
+	function __construct()
+	{
+	// changes the metaColumnsSQL, adds columns: attnum[6]
+	}
+	
 	function ServerInfo()
 	{
 		if (isset($this->version)) return $this->version;
