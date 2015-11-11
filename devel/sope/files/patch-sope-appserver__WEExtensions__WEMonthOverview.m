--- sope-appserver/WEExtensions/WEMonthOverview.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/WEMonthOverview.m
@@ -510,7 +510,7 @@ _takeValuesInCell(WEMonthOverview *self,
   /* fill up remaining slots with empty arrays */
   for (i = 0; i < MatrixSize; i++) {
     if (self->matrix[i] == nil)
-      self->matrix[i] = [[NSArray alloc] init];
+      self->matrix[i] = (id)[[NSArray alloc] init];
   }
 }
 
