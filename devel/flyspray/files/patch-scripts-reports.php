--- scripts/reports.php.orig	Mon Oct  3 12:51:02 2005
+++ scripts/reports.php	Thu Oct 27 00:09:01 2005
@@ -353,9 +353,12 @@
         $date = 'from';
         $fromdate = $_REQUEST['fromdate'];
         $todate = $_REQUEST['todate'];
-
+	if (!isset($fromdate) || $fromdate=="") { $fromdate = date("d-M-Y"); }
+	if (!isset($todate) || $todate=="") { $todate = date("d-M-Y"); }
+	
         $ufromdate = strtotime($fromdate);
-        $utodate = strtotime($todate);
+	// Add 24 hours to the end to make it include that date
+        $utodate = strtotime($todate) + 86400;
 
         $wheredate = "AND h.event_date > {$ufromdate} AND h.event_date < {$utodate}";
         break;
