--- ofxdump/ofxdump.cpp.orig	Thu Jan 15 05:47:52 2004
+++ ofxdump/ofxdump.cpp	Tue Aug 10 02:09:27 2004
@@ -204,39 +204,39 @@
   
   if(data.transactiontype_valid==true){
     switch(data.transactiontype){
-    case data.OFX_CREDIT: strncpy(dest_string, "CREDIT: Generic credit", sizeof(dest_string));
+    case OfxTransactionData::OFX_CREDIT: strncpy(dest_string, "CREDIT: Generic credit", sizeof(dest_string));
       break;
-    case data.OFX_DEBIT: strncpy(dest_string, "DEBIT: Generic debit", sizeof(dest_string));
+    case OfxTransactionData::OFX_DEBIT: strncpy(dest_string, "DEBIT: Generic debit", sizeof(dest_string));
       break;
-    case data.OFX_INT: strncpy(dest_string, "INT: Interest earned or paid (Note: Depends on signage of amount)", sizeof(dest_string));
+    case OfxTransactionData::OFX_INT: strncpy(dest_string, "INT: Interest earned or paid (Note: Depends on signage of amount)", sizeof(dest_string));
       break;
-    case data.OFX_DIV: strncpy(dest_string, "DIV: Dividend", sizeof(dest_string));
+    case OfxTransactionData::OFX_DIV: strncpy(dest_string, "DIV: Dividend", sizeof(dest_string));
       break;
-    case data.OFX_FEE: strncpy(dest_string, "FEE: FI fee", sizeof(dest_string));
+    case OfxTransactionData::OFX_FEE: strncpy(dest_string, "FEE: FI fee", sizeof(dest_string));
       break;
-    case data.OFX_SRVCHG: strncpy(dest_string, "SRVCHG: Service charge", sizeof(dest_string));
+    case OfxTransactionData::OFX_SRVCHG: strncpy(dest_string, "SRVCHG: Service charge", sizeof(dest_string));
       break;
-    case data.OFX_DEP: strncpy(dest_string, "DEP: Deposit", sizeof(dest_string));
+    case OfxTransactionData::OFX_DEP: strncpy(dest_string, "DEP: Deposit", sizeof(dest_string));
       break;
-    case data.OFX_ATM: strncpy(dest_string, "ATM: ATM debit or credit (Note: Depends on signage of amount)", sizeof(dest_string));
+    case OfxTransactionData::OFX_ATM: strncpy(dest_string, "ATM: ATM debit or credit (Note: Depends on signage of amount)", sizeof(dest_string));
       break;
-    case data.OFX_POS: strncpy(dest_string, "POS: Point of sale debit or credit (Note: Depends on signage of amount)", sizeof(dest_string));
+    case OfxTransactionData::OFX_POS: strncpy(dest_string, "POS: Point of sale debit or credit (Note: Depends on signage of amount)", sizeof(dest_string));
       break;
-    case data.OFX_XFER: strncpy(dest_string, "XFER: Transfer", sizeof(dest_string));
+    case OfxTransactionData::OFX_XFER: strncpy(dest_string, "XFER: Transfer", sizeof(dest_string));
       break;
-    case data.OFX_CHECK: strncpy(dest_string, "CHECK: Check", sizeof(dest_string));
+    case OfxTransactionData::OFX_CHECK: strncpy(dest_string, "CHECK: Check", sizeof(dest_string));
       break;
-    case data.OFX_PAYMENT: strncpy(dest_string, "PAYMENT: Electronic payment", sizeof(dest_string));
+    case OfxTransactionData::OFX_PAYMENT: strncpy(dest_string, "PAYMENT: Electronic payment", sizeof(dest_string));
       break;
-    case data.OFX_CASH: strncpy(dest_string, "CASH: Cash withdrawal", sizeof(dest_string));
+    case OfxTransactionData::OFX_CASH: strncpy(dest_string, "CASH: Cash withdrawal", sizeof(dest_string));
       break;
-    case data.OFX_DIRECTDEP: strncpy(dest_string, "DIRECTDEP: Direct deposit", sizeof(dest_string));
+    case OfxTransactionData::OFX_DIRECTDEP: strncpy(dest_string, "DIRECTDEP: Direct deposit", sizeof(dest_string));
       break;
-    case data.OFX_DIRECTDEBIT: strncpy(dest_string, "DIRECTDEBIT: Merchant initiated debit", sizeof(dest_string));
+    case OfxTransactionData::OFX_DIRECTDEBIT: strncpy(dest_string, "DIRECTDEBIT: Merchant initiated debit", sizeof(dest_string));
       break;
-    case data.OFX_REPEATPMT: strncpy(dest_string, "REPEATPMT: Repeating payment/standing order", sizeof(dest_string));
+    case OfxTransactionData::OFX_REPEATPMT: strncpy(dest_string, "REPEATPMT: Repeating payment/standing order", sizeof(dest_string));
       break;
-    case data.OFX_OTHER: strncpy(dest_string, "OTHER: Other", sizeof(dest_string));
+    case OfxTransactionData::OFX_OTHER: strncpy(dest_string, "OTHER: Other", sizeof(dest_string));
       break;
     default : strncpy(dest_string, "Unknown transaction type", sizeof(dest_string));
       break;
@@ -273,9 +273,9 @@
   if(data.fi_id_correction_action_valid==true){
     cout<<"    Action to take on the corrected transaction: ";
     switch(data.fi_id_correction_action){
-    case data.DELETE : cout<<"DELETE\n";
+    case OfxTransactionData::DELETE : cout<<"DELETE\n";
       break;
-    case data.REPLACE : cout<<"REPLACE\n";
+    case OfxTransactionData::REPLACE : cout<<"REPLACE\n";
       break;
     default:
       cout<<"ofx_proc_transaction(): This should not happen!\n";
@@ -284,43 +284,43 @@
   if(data.invtransactiontype_valid==true){
     cout<<"    Investment transaction type: ";
     switch(data.invtransactiontype){
-    case data.OFX_BUYDEBT: strncpy(dest_string, "BUYDEBT (Buy debt security)", sizeof(dest_string));
+    case OfxTransactionData::OFX_BUYDEBT: strncpy(dest_string, "BUYDEBT (Buy debt security)", sizeof(dest_string));
       break;
-     case data.OFX_BUYMF: strncpy(dest_string, "BUYMF (Buy mutual fund)", sizeof(dest_string));
+     case OfxTransactionData::OFX_BUYMF: strncpy(dest_string, "BUYMF (Buy mutual fund)", sizeof(dest_string));
       break;
-    case data.OFX_BUYOPT: strncpy(dest_string, "BUYOPT (Buy option)", sizeof(dest_string));
+    case OfxTransactionData::OFX_BUYOPT: strncpy(dest_string, "BUYOPT (Buy option)", sizeof(dest_string));
       break;
-    case data.OFX_BUYOTHER: strncpy(dest_string, "BUYOTHER (Buy other security type)", sizeof(dest_string));
+    case OfxTransactionData::OFX_BUYOTHER: strncpy(dest_string, "BUYOTHER (Buy other security type)", sizeof(dest_string));
       break;
-    case data.OFX_BUYSTOCK: strncpy(dest_string, "BUYSTOCK (Buy stock))", sizeof(dest_string));
+    case OfxTransactionData::OFX_BUYSTOCK: strncpy(dest_string, "BUYSTOCK (Buy stock))", sizeof(dest_string));
       break;
-    case data.OFX_CLOSUREOPT: strncpy(dest_string, "CLOSUREOPT (Close a position for an option)", sizeof(dest_string));
+    case OfxTransactionData::OFX_CLOSUREOPT: strncpy(dest_string, "CLOSUREOPT (Close a position for an option)", sizeof(dest_string));
       break;
-    case data.OFX_INCOME: strncpy(dest_string, "INCOME (Investment income is realized as cash into the investment account)", sizeof(dest_string));
+    case OfxTransactionData::OFX_INCOME: strncpy(dest_string, "INCOME (Investment income is realized as cash into the investment account)", sizeof(dest_string));
       break;
-    case data.OFX_INVEXPENSE: strncpy(dest_string, "INVEXPENSE (Misc investment expense that is associated with a specific security)", sizeof(dest_string));
+    case OfxTransactionData::OFX_INVEXPENSE: strncpy(dest_string, "INVEXPENSE (Misc investment expense that is associated with a specific security)", sizeof(dest_string));
       break;
-    case data.OFX_JRNLFUND: strncpy(dest_string, "JRNLFUND (Journaling cash holdings between subaccounts within the same investment account)", sizeof(dest_string));
+    case OfxTransactionData::OFX_JRNLFUND: strncpy(dest_string, "JRNLFUND (Journaling cash holdings between subaccounts within the same investment account)", sizeof(dest_string));
       break;
-    case data.OFX_MARGININTEREST: strncpy(dest_string, "MARGININTEREST (Margin interest expense)", sizeof(dest_string));
+    case OfxTransactionData::OFX_MARGININTEREST: strncpy(dest_string, "MARGININTEREST (Margin interest expense)", sizeof(dest_string));
       break;
-    case data.OFX_REINVEST: strncpy(dest_string, "REINVEST (Reinvestment of income)", sizeof(dest_string));
+    case OfxTransactionData::OFX_REINVEST: strncpy(dest_string, "REINVEST (Reinvestment of income)", sizeof(dest_string));
       break;
-    case data.OFX_RETOFCAP: strncpy(dest_string, "RETOFCAP (Return of capital)", sizeof(dest_string));
+    case OfxTransactionData::OFX_RETOFCAP: strncpy(dest_string, "RETOFCAP (Return of capital)", sizeof(dest_string));
       break;
-    case data.OFX_SELLDEBT: strncpy(dest_string, "SELLDEBT (Sell debt security.  Used when debt is sold, called, or reached maturity)", sizeof(dest_string));
+    case OfxTransactionData::OFX_SELLDEBT: strncpy(dest_string, "SELLDEBT (Sell debt security.  Used when debt is sold, called, or reached maturity)", sizeof(dest_string));
       break;
-    case data.OFX_SELLMF: strncpy(dest_string, "SELLMF (Sell mutual fund)", sizeof(dest_string));
+    case OfxTransactionData::OFX_SELLMF: strncpy(dest_string, "SELLMF (Sell mutual fund)", sizeof(dest_string));
       break;
-    case data.OFX_SELLOPT: strncpy(dest_string, "SELLOPT (Sell option)", sizeof(dest_string));
+    case OfxTransactionData::OFX_SELLOPT: strncpy(dest_string, "SELLOPT (Sell option)", sizeof(dest_string));
       break;
-    case data.OFX_SELLOTHER: strncpy(dest_string, "SELLOTHER (Sell other type of security)", sizeof(dest_string));
+    case OfxTransactionData::OFX_SELLOTHER: strncpy(dest_string, "SELLOTHER (Sell other type of security)", sizeof(dest_string));
       break;
-    case data.OFX_SELLSTOCK: strncpy(dest_string, "SELLSTOCK (Sell stock)", sizeof(dest_string));
+    case OfxTransactionData::OFX_SELLSTOCK: strncpy(dest_string, "SELLSTOCK (Sell stock)", sizeof(dest_string));
       break;
-    case data.OFX_SPLIT: strncpy(dest_string, "SPLIT (Stock or mutial fund split)", sizeof(dest_string));
+    case OfxTransactionData::OFX_SPLIT: strncpy(dest_string, "SPLIT (Stock or mutial fund split)", sizeof(dest_string));
       break;
-    case data.OFX_TRANSFER: strncpy(dest_string, "TRANSFER (Transfer holdings in and out of the investment account)", sizeof(dest_string));
+    case OfxTransactionData::OFX_TRANSFER: strncpy(dest_string, "TRANSFER (Transfer holdings in and out of the investment account)", sizeof(dest_string));
       break;
     default: strncpy(dest_string, "ERROR, this investment transaction type is unknown.  This is a bug in ofxdump", sizeof(dest_string));
       break;
