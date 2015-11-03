--- sope-appserver/WEExtensions/WETableView/WETableView.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/WETableView/WETableView.m
@@ -1525,9 +1525,9 @@ static inline void _applyState_(WETableV
         result = [self decreaseBatchSizeInContext:_ctx];
       else {
         if (self->identifier == nil) {
-          unsigned idx;
+          NSInteger idx;
       
-          idx   = [idxId unsignedIntValue];
+          idx   = [idxId integerValue];
           if (idx < [self->allObjects count] && idx >= 0) {
             _applyItems_(self, cmp, idx);
           }
