--- history.php.orig	Wed Jan  2 18:05:19 2002
+++ history.php	Sat Feb 16 19:36:54 2002
@@ -197,7 +197,7 @@
             $bg = isset($branchColours[$bgbr]) ? $branchColours[$bgbr] : 'white';
             $log = $fl->logs[$rev]; 
             $author = Chora::showAuthorName($log->queryAuthor());
-            $date = gmdate('jS M Y', $log->queryDate());
+            $date = strftime('%e %b %Y', $log->queryDate());
             $lines = $log->queryChangedLines();
             include $registry->getTemplatePath() . '/history/rev.inc';
 
