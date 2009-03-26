--- src/af/xap/unix/xap_UnixTableWidget.cpp.orig	2008-08-13 00:22:24.000000000 +0200
+++ src/af/xap/unix/xap_UnixTableWidget.cpp	2009-03-10 19:42:33.000000000 +0100
@@ -123,7 +123,9 @@ abi_table_resize(AbiTable* table)
 	g_return_if_fail(table);
 
 	if (table->selected_rows == 0 && table->selected_cols == 0)
-		text = g_strdup(table->szCancel);
+		// RIVERA changed as suggested by uwog (OSX X11 was crashing)
+		//text = g_strdup(table->szCancel);
+		text = (table->szCancel ? g_strdup(table->szCancel) : NULL);
 	else
 	{
 		UT_UTF8String prText =  "%d x %d ";
