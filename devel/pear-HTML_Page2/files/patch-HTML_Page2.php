--- HTML/Page2.php.orig	2023-03-25 19:41:07 UTC
+++ HTML/Page2.php
@@ -1647,6 +1647,7 @@ class HTML_Page2 extends HTML_Common
                 $strHtml .= ' profile="'.$this->_profile.'"';
             }
 
+            $strHtml .= ' lang="' . $this->_language . '"';
             $strHtml .= '>' . $lnEnd;
 
         }
