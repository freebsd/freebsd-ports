--- adodb-odbc.inc.php.orig	Wed Jun  6 06:17:56 2001
+++ adodb-odbc.inc.php	Thu Jun 28 10:00:41 2001
@@ -310,7 +310,7 @@
 	{
 		if ($this->_numOfRows != 0 && !$this->EOF) {		
 			$this->_currentRow++;
-			if (odbc_fetch_into($this->_queryID,0,$this->fields)) return true;
+			if (odbc_fetch_into($this->_queryID,$row=0,$this->fields)) return true;
 		}
 		$this->EOF = true;
 		return false;
@@ -318,7 +318,7 @@
 	
 	function _fetch($ignore_fields=false)
 	{
-		return odbc_fetch_into($this->_queryID,0,$this->fields);
+		return odbc_fetch_into($this->_queryID,$row=0,$this->fields);
 	}
 	
 	function _close() {
