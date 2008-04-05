--- abiword/trunk/src/af/xap/unix/xap_UnixTableWidget.cpp	2007/03/04 23:35:03	20016
+++ src/af/xap/unix/xap_UnixTableWidget.cpp	2007/09/21 04:03:45	21991
@@ -123,7 +123,9 @@
 	g_return_if_fail(table);
 
 	if (table->selected_rows == 0 && table->selected_cols == 0)
-		text = g_strdup_printf(table->szCancel);
+		// RIVERA changed as suggested by uwog (OSX X11 was crashing)
+		//text = g_strdup_printf(table->szCancel);
+		text = (table->szCancel ? g_strdup_printf(table->szCancel) : NULL);
 	else
 	{
 		UT_UTF8String prText =  "%d x %d ";
