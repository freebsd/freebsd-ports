--- inc/libofx.h.orig	Sat Feb 12 16:40:57 2005
+++ inc/libofx.h	Sat Feb 12 16:39:46 2005
@@ -38,8 +38,12 @@
 
 #ifdef __cplusplus
 #define CFCT extern "C"
+#define CFCT_start extern "C" {
+#define CFCT_end }
 #else
 #define CFCT
+#define CFCT_start
+#define CFCT_end
 #define true 1
 #define false 0
 #endif
@@ -207,7 +211,9 @@
  other events).  An OfxStatusData structure is passed to this event, as well as
  a pointer to an arbitrary data structure.
 */
-CFCT typedef int (*LibofxProcStatusCallback)(const struct OfxStatusData data, void * status_data);
+CFCT_start
+typedef int (*LibofxProcStatusCallback)(const struct OfxStatusData data, void * status_data);
+CFCT_end
 
 /**
  * \brief An abstraction of an account
@@ -264,7 +270,9 @@
  part of OfxStatementData structure passed to ofx_proc_statement event, 
  as well as a pointer to an arbitrary data structure.
 */
-CFCT typedef int (*LibofxProcAccountCallback)(const struct OfxAccountData data, void * account_data);
+CFCT_start
+typedef int (*LibofxProcAccountCallback)(const struct OfxAccountData data, void * account_data);
+CFCT_end
 
 /**
  * \brief An abstraction of a security, such as a stock, mutual fund, etc.
@@ -320,7 +328,9 @@
  An OfxSecurityData structure is passed to this event, as well as
  a pointer to an arbitrary data structure.
 */
-CFCT typedef int (*LibofxProcSecurityCallback)(const struct OfxSecurityData data, void * security_data);
+CFCT_start
+typedef int (*LibofxProcSecurityCallback)(const struct OfxSecurityData data, void * security_data);
+CFCT_end
 
 typedef enum {
     OFX_CREDIT,     /**< Generic credit */
@@ -498,7 +508,9 @@
  generated. An OfxTransactionData structure is passed to this event, as well as
  a pointer to an arbitrary data structure.
 */
-CFCT typedef int (*LibofxProcTransactionCallback)(const struct OfxTransactionData data, void * transaction_data);
+CFCT_start
+typedef int (*LibofxProcTransactionCallback)(const struct OfxTransactionData data, void * transaction_data);
+CFCT_end
 
 /** 
  * \brief An abstraction of an account statement. 
@@ -567,7 +579,9 @@
  events have been sent. An OfxStatementData is passed to this event, as well as
  a pointer to an arbitrary data structure.
 */
-CFCT typedef int (*LibofxProcStatementCallback)(const struct OfxStatementData data, void * statement_data);
+CFCT_start
+typedef int (*LibofxProcStatementCallback)(const struct OfxStatementData data, void * statement_data);
+CFCT_end
 
 /** 
     \brief NOT YET SUPPORTED
