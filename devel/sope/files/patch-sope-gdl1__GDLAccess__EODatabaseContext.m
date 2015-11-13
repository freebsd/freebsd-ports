--- sope-gdl1/GDLAccess/EODatabaseContext.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EODatabaseContext.m
@@ -118,7 +118,7 @@ static inline void _checkTxInProgress(EO
   if (self->transactionNestingLevel == 0) {
     [NSException raise:NSInternalInconsistencyException
 		 format:
-              @"EODatabaseContext:%x: No transaction in progress "
+              @"EODatabaseContext:%@: No transaction in progress "
               @"in %s", self, _function];
   }
 }
@@ -264,7 +264,7 @@ static inline void _checkTxInProgress(EO
       (unsigned)transactionNestingLevel) {
     [NSException raise:NSInternalInconsistencyException
 		 format:
-              @"EODatabaseContext:%x:transaction nesting levels do not match: "
+              @"EODatabaseContext:%@:transaction nesting levels do not match: "
               @"database has %d, adaptor has %d, "
               @"in [EODatabaseContext beginTransaction]",
               self, transactionNestingLevel, 
@@ -295,7 +295,7 @@ static inline void _checkTxInProgress(EO
       (unsigned)self->transactionNestingLevel) {
     [NSException raise:NSInternalInconsistencyException
 		 format:
-              @"EODatabaseContext:%x:transaction nesting levels do not match: "
+              @"EODatabaseContext:%@:transaction nesting levels do not match: "
               @"database has %d, adaptor has %d, "
               @"in [EODatabaseContext commitTransaction]",
               self, transactionNestingLevel, 
@@ -325,7 +325,7 @@ static inline void _checkTxInProgress(EO
       (unsigned)self->transactionNestingLevel) {
     [NSException raise:NSInternalInconsistencyException
 		 format:
-              @"EODatabaseContext:%x:transaction nesting levels do not match: "
+              @"EODatabaseContext:%@:transaction nesting levels do not match: "
               @"database has %d, adaptor has %d, "
               @"in [EODatabaseContext rollbackTransaction]",
               self, transactionNestingLevel, 
@@ -385,7 +385,7 @@ static inline void _checkTxInProgress(EO
   if ([self transactionNestingLevel]) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-        @"EODatabaseContext:%x: Cannot change update strategy "
+        @"EODatabaseContext:%@: Cannot change update strategy "
         @"when context has a transaction open, "
         @"in [EODatabaseContext setUpdateStrategy]",
         self];
@@ -483,14 +483,14 @@ static inline void _checkTxInProgress(EO
   if (_object == nil) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot forget null object, "
+              @"EODatabaseContext:%@: Cannot forget null object, "
               @"in [EODatabaseContext forgetObject]",
               self];
   }
   if ([EOFault isFault:_object]) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot forget forget a fault object, "
+              @"EODatabaseContext:%@: Cannot forget forget a fault object, "
               @"in [EODatabaseContext forgetObject]",
               self];
   }
@@ -532,14 +532,14 @@ static inline void _checkTxInProgress(EO
   if (_object == nil) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot record null object, "
+              @"EODatabaseContext:%@: Cannot record null object, "
               @"in [EODatabaseContext recordObject:primaryKey:entity:snapshot:]",
               self];
   }
   if ((_entity == nil) && self->isUniquingObjects) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot record object with null entity "
+              @"EODatabaseContext:%@: Cannot record object with null entity "
               @"when uniquing objects, "
               @"in [EODatabaseContext recordObject:primaryKey:entity:snapshot:]",
               self];
@@ -550,7 +550,7 @@ static inline void _checkTxInProgress(EO
   if ((_key == nil) && self->isUniquingObjects) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot record object with null key "
+              @"EODatabaseContext:%@: Cannot record object with null key "
               @"when uniquing objects, "
               @"in [EODatabaseContext recordObject:primaryKey:entity:snapshot:]",
               self];
@@ -558,7 +558,7 @@ static inline void _checkTxInProgress(EO
   if ((snapshot == nil) && isKeepingSnapshots && ![EOFault isFault:_object]) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot record object with null snapshot "
+              @"EODatabaseContext:%@: Cannot record object with null snapshot "
               @"when keeping snapshots, "
               @"in [EODatabaseContext recordObject:primaryKey:entity:snapshot:]"
               @": snapshot=%s keepsSnapshots=%s isFault=%s",
@@ -665,14 +665,14 @@ static inline void _checkTxInProgress(EO
   if (_object == nil) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot record null object as locked, "
+              @"EODatabaseContext:%@: Cannot record null object as locked, "
               @"in [EODatabaseContext recordLockedObject:]",
               self];
   }
   if ([EOFault isFault:_object]) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-              @"EODatabaseContext:%x: Cannot record a fault object as locked, "
+              @"EODatabaseContext:%@: Cannot record a fault object as locked, "
               @"in [EODatabaseContext recordLockedObject:]",
               self];
   }
@@ -695,14 +695,14 @@ static inline void _checkTxInProgress(EO
   if (_object == nil) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-               @"EODatabaseContext:%x: Cannot record null object as updatetd, "
+               @"EODatabaseContext:%@: Cannot record null object as updatetd, "
                @"in [EODatabaseContext recordUpdatedObject:]",
                self];
   }
   if ([EOFault isFault:_object]) {
     [NSException raise:NSInvalidArgumentException
 		 format:
-               @"EODatabaseContext:%x: Cannot record fault object as updated, "
+               @"EODatabaseContext:%@: Cannot record fault object as updated, "
                @"in [EODatabaseContext recordUpdatedObject:]",
                self];
   }
@@ -728,7 +728,7 @@ static inline void _checkTxInProgress(EO
   return [NSString stringWithFormat:
 		     @"<%@[0x%p]: #channels=%i tx-nesting=%i>",
                      NSStringFromClass([self class]), self,
-                     [self->channels count],
+                     (int)[self->channels count],
                      [self transactionNestingLevel]];
 }
 
