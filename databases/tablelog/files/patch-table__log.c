--- table_log.c.orig	2007-05-16 23:14:04 UTC
+++ table_log.c
@@ -22,6 +22,8 @@
 #include "utils/formatting.h"
 #include "utils/builtins.h"
 #include <utils/lsyscache.h>
+#include <utils/rel.h>
+#include <utils/timestamp.h>
 #include <funcapi.h>
 
 /* for PostgreSQL >= 8.2.x */
@@ -71,7 +73,11 @@ int count_columns (TupleDesc tupleDesc) {
   int i;
 
   for (i = 0; i < tupleDesc->natts; ++i) {
+#if PG_VERSION_NUM < 110000
     if (!tupleDesc->attrs[i]->attisdropped) {
+#else
+    if (!tupleDesc->attrs[i].attisdropped) {
+#endif
       ++count;
     }
   }
@@ -298,7 +304,11 @@ static void __table_log (TriggerData *trigdata, char *
     col_nr++;
     found_col = 0;
     do {
+#if PG_VERSION_NUM < 110000
       if (trigdata->tg_relation->rd_att->attrs[col_nr - 1]->attisdropped) {
+#else
+      if (trigdata->tg_relation->rd_att->attrs[col_nr - 1].attisdropped) {
+#endif
         /* this column is dropped, skip it */
         col_nr++;
         continue;
@@ -343,7 +353,11 @@ static void __table_log (TriggerData *trigdata, char *
     col_nr++;
     found_col = 0;
     do {
+#if PG_VERSION_NUM < 110000
       if (trigdata->tg_relation->rd_att->attrs[col_nr - 1]->attisdropped) {
+#else
+      if (trigdata->tg_relation->rd_att->attrs[col_nr - 1].attisdropped) {
+#endif
         /* this column is dropped, skip it */
         col_nr++;
         continue;
@@ -370,7 +384,11 @@ static void __table_log (TriggerData *trigdata, char *
     col_nr++;
     found_col = 0;
     do {
+#if PG_VERSION_NUM < 110000
       if (trigdata->tg_relation->rd_att->attrs[col_nr - 1]->attisdropped) {
+#else
+      if (trigdata->tg_relation->rd_att->attrs[col_nr - 1].attisdropped) {
+#endif
         /* this column is dropped, skip it */
         col_nr++;
         continue;
