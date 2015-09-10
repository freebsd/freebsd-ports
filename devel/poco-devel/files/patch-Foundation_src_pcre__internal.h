--- Foundation/src/pcre_internal.h.orig	2014-12-21 23:06:53 UTC
+++ Foundation/src/pcre_internal.h
@@ -2636,6 +2636,16 @@ typedef struct {
 } ucp_type_table;
 
 
+/* renamed to avoid clashes with system pcre */
+#define _pcre_utf8_table1      _poco__pcre_utf8_table1
+#define _pcre_utf8_table1_size _poco__pcre_utf8_table1_size
+#define _pcre_utf8_table2      _poco__pcre_utf8_table2
+#define _pcre_utf8_table3      _poco__pcre_utf8_table3
+#define _pcre_utf8_table4      _poco__pcre_utf8_table4
+#define _pcre_utt              _poco__pcre_utt
+#define _pcre_utt_size         _poco__pcre_utt_size
+#define _pcre_utt_names        _poco__pcre_utt_names
+#define _pcre_OP_lengths       _poco__pcre_OP_lengths
 /* Internal shared data tables. These are tables that are used by more than one
 of the exported public functions. They have to be "external" in the C sense,
 but are not part of the PCRE public API. The data for these tables is in the
@@ -2749,6 +2759,11 @@ typedef struct {
   pcre_int32 other_case; /* offset to other case, or zero if none */
 } ucd_record;
 
+/* renamed to avoid clashes with system pcre */
+#define _pcre_ucd_records _poco__pcre_ucd_records
+#define _pcre_ucd_stage1 _poco__pcre_ucd_stage1
+#define _pcre_ucd_stage2 _poco__pcre_ucd_stage2
+#define _pcre_ucp_gentype _poco__pcre_ucp_gentype
 extern const pcre_uint32 PRIV(ucd_caseless_sets)[];
 extern const ucd_record  PRIV(ucd_records)[];
 extern const pcre_uint8  PRIV(ucd_stage1)[];
