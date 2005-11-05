--- srlow/libsrlow/SRLow.c.orig	Mon Jun 27 04:14:03 2005
+++ srlow/libsrlow/SRLow.c	Mon Jun 27 04:14:18 2005
@@ -666,8 +666,9 @@ srl_get_focused_cell (Accessible *acc_ta
 	for (i = rows; !rv && i <= rowe && count < SRL_MAX_CHILDREN_CNT; i++)
 	    for (j = cols; !rv && j <= cole && count < SRL_MAX_CHILDREN_CNT; j++)
 	    {
+		Accessible *cell;
 		count++;
-		Accessible *cell = AccessibleTable_getAccessibleAt (table, i, j);
+		cell = AccessibleTable_getAccessibleAt (table, i, j);
 		if (cell)
 		{
 		    if (srl_acc_has_state (cell, SPI_STATE_FOCUSED))
