--- reporting/includes/fpdi/fpdi_pdf_parser.php.orig	2026-04-28 11:25:37 UTC
+++ reporting/includes/fpdi/fpdi_pdf_parser.php
@@ -333,6 +333,8 @@ class fpdi_pdf_parser extends pdf_parser {
     			return false;
     		} else {
                 $res = $this->_getPageRotation($obj[1][1]['/Parent']);
+                if ($res === false)
+                    return false;
                 if ($res[0] == PDF_TYPE_OBJECT)
                     return $res[1];
                 return $res;
