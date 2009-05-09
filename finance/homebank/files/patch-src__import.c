--- src/import.c.orig	2009-05-01 21:57:15.000000000 +0900
+++ src/import.c	2009-05-05 05:09:06.000000000 +0900
@@ -244,7 +244,7 @@
 
 				g_free(converted_contents);
 		
-				if( isutf8 == true )
+				if( isutf8 == TRUE )
 				{
 					
 					retval = enc->charset;
@@ -509,24 +509,24 @@
 
 	DB( g_print("** ofx_proc_account_cb()\n") );
 
-	if(data.account_id_valid==true)
+	if(data.account_id_valid==TRUE)
 	{
 		DB( g_print("  account_id: %s\n", data.account_id) );
 		DB( g_print("  account_name: %s\n", data.account_name) );
 	}
 
-	//if(data.account_number_valid==true)
+	//if(data.account_number_valid==TRUE)
 	//{
 		DB( g_print("  account_number: %s\n", data.account_number) );
 	//}
 
 
-	if(data.account_type_valid==true)
+	if(data.account_type_valid==TRUE)
 	{
 		DB( g_print("  account_type: %d\n", data.account_type) );
 	}
 
-	if(data.currency_valid==true)
+	if(data.currency_valid==TRUE)
 	{
 		DB( g_print("  currency: %s\n", data.currency) );
 	}
@@ -575,7 +575,7 @@
 	DB( g_print("** ofx_proc_statement_cb()\n") );
 
 #ifdef MYDEBUG
-	if(data.ledger_balance_date_valid==true)
+	if(data.ledger_balance_date_valid==TRUE)
 	{
 	struct tm temp_tm;	
 
@@ -584,7 +584,7 @@
 	}
 #endif
 
-	if(data.ledger_balance_valid==true)
+	if(data.ledger_balance_valid==TRUE)
 	{
 		if( ctx->curr_acc != NULL && ctx->curr_acc_isnew == TRUE )
 		{	
@@ -616,7 +616,7 @@
 	newope = da_operation_malloc();
 
 // date	
-	if(data.date_posted_valid==true)
+	if(data.date_posted_valid==TRUE)
 	{
 		temp_tm = *localtime(&(data.date_posted));
 		date = g_date_new();
@@ -625,7 +625,7 @@
 		g_date_free(date);
 	}
 // amount
-	if(data.amount_valid==true)
+	if(data.amount_valid==TRUE)
 	{
 		newope->amount = data.amount;
 
@@ -633,14 +633,14 @@
 			newope->flags |= OF_INCOME;
 	}
 // check number
-	if(data.check_number_valid==true)
+	if(data.check_number_valid==TRUE)
 	{
 		newope->info = g_strdup(data.check_number);
 	}
 	//todo: reference_number ?
 
 // wording
-	if(data.name_valid==true)
+	if(data.name_valid==TRUE)
 	{
 		newope->wording = g_strdup(data.name);
 	}
@@ -648,7 +648,7 @@
 	//todo: memo ?
 
 // payment
-	if(data.transactiontype_valid==true)
+	if(data.transactiontype_valid==TRUE)
 	{
 		switch(data.transactiontype)
 		{
@@ -753,12 +753,12 @@
 
 	DB( g_print("(import) ofx import\n") );
 
-	ofx_PARSER_msg	= false;
-	ofx_DEBUG_msg	= false;
-	ofx_WARNING_msg = false;
-	ofx_ERROR_msg	= false;
-	ofx_INFO_msg	= false;
-	ofx_STATUS_msg	= false;
+	ofx_PARSER_msg	= FALSE;
+	ofx_DEBUG_msg	= FALSE;
+	ofx_WARNING_msg = FALSE;
+	ofx_ERROR_msg	= FALSE;
+	ofx_INFO_msg	= FALSE;
+	ofx_STATUS_msg	= FALSE;
 
 	LibofxContextPtr libofx_context = libofx_get_new_context();
 	ofx_set_statement_cb  (libofx_context, (LibofxProcStatementCallback)  ofx_proc_statement_cb  , &ctx);
