--- externals/phpqrcode/phpqrcode.php.orig	2025-05-01 22:56:37 UTC
+++ externals/phpqrcode/phpqrcode.php
@@ -4396,11 +4396,11 @@
                 if($col >= $this->rsblocks[0]->dataLength) {
                     $row += $this->b1;
                 }
-                $ret = $this->rsblocks[$row]->data[$col];
+                $ret = $this->rsblocks[$row]->data[(int) $col];
             } else if($this->count < $this->dataLength + $this->eccLength) {
                 $row = ($this->count - $this->dataLength) % $this->blocks;
                 $col = ($this->count - $this->dataLength) / $this->blocks;
-                $ret = $this->rsblocks[$row]->ecc[$col];
+                $ret = $this->rsblocks[$row]->ecc[(int) $col];
             } else {
                 return 0;
             }
