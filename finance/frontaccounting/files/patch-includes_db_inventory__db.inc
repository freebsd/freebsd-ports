--- includes/db/inventory_db.inc.orig	2026-04-28 11:25:37 UTC
+++ includes/db/inventory_db.inc
@@ -232,7 +232,7 @@ function get_deliveries_from_trans($stock_id, $move_id
         WHERE stock_id=".db_escape($stock_id)." AND qty < 0 AND
             trans_id>='$move_id' GROUP BY stock_id";
 	$result = db_query($sql, "The deliveries could not be updated");
-	$row = db_fetch_row($result);
+	$row = db_fetch_row($result) ?: array(0, 0);
 	
     $sql = "SELECT IF(type=".ST_SUPPRECEIVE." OR type=".ST_SUPPCREDIT.", price, standard_cost)
         FROM ".TB_PREF."stock_moves
@@ -247,7 +247,7 @@ function get_deliveries_from_trans($stock_id, $move_id
 		WHERE stock_id=".db_escape($stock_id)." AND
 			trans_id<'$move_id' GROUP BY stock_id";
 	$result = db_query($sql, "The deliveries could not be updated");
-	$qoh = db_fetch_row($result);
+	$qoh = db_fetch_row($result) ?: array(0);
 
 	$qty = $row[0] - $qoh[0]; //QOH prior to -ve stock is subtracted
 	$final_cost = $row[1] - $qoh[0]*$cost[0];
