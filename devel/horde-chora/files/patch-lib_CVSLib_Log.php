--- lib/CVSLib/Log.php.orig	Sat Aug 11 22:59:31 2001
+++ lib/CVSLib/Log.php	Sat Feb 16 19:39:47 2002
@@ -45,7 +45,7 @@
             case CVSLIB_LOG_DATE:
                 $line = array_shift($raw);
                 if (preg_match("|^date:\s+(\d+)/(\d+)/(\d+)\s+(\d+):(\d+):(\d+);\s+author:\s+(\S+);\s+state:\s+(\S+);(\s+lines:\s+([0-9\s+-]+))?|", $line, $parts)) {
-                    $this->date = mktime($parts[4], $parts[5], $parts[6], $parts[2], $parts[3], $parts[1]);
+                    $this->date = gmmktime($parts[4], $parts[5], $parts[6], $parts[2], $parts[3], $parts[1]);
                     $this->author = $parts[7];
                     $this->state = $parts[8];
                     $this->lines = isset($parts[10])?$parts[10]:'';
