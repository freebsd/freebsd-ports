--- cvs.php.orig	Wed Jan  2 18:05:18 2002
+++ cvs.php	Sat Feb 16 20:29:37 2002
@@ -176,7 +176,7 @@
         }
 
         $textURL= Chora::url('co', $where, array('r'=>$rev));
-        $commitDate = gmdate('jS F Y, g:ia', $lg->date);
+        $commitDate = date('jS F Y, g:ia', $lg->date);
         $readableDate = CVSLib_File::readableTime($lg->date, true);
 
         $aid = $lg->queryAuthor();
