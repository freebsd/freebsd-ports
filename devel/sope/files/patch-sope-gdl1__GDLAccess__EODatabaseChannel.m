--- sope-gdl1/GDLAccess/EODatabaseChannel.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EODatabaseChannel.m
@@ -81,7 +81,7 @@ NSString *EODatabaseChannelDidLockObject
 - (Class)privateClassForEntity:(EOEntity *)anEntity;
 - (void)privateUpdateCurrentEntityInfo;
 - (void)privateClearCurrentEntityInfo;
-- (void)privateReportError:(SEL)method:(NSString *)format, ...;
+- (void)privateReportError:(SEL)method :(NSString *)format, ...;
 @end
 
 /*
@@ -593,7 +593,7 @@ NSString *EODatabaseChannelDidLockObject
   }
   // Record object in database context
   if (![new_pkey isEqual:old_pkey]) {
-    NSLog(@"WARNING: (%@) primary key changed from %@ to %@",
+    NSLog(@"WARNING: (%s) primary key changed from %@ to %@",
           __PRETTY_FUNCTION__, old_pkey, new_pkey);
     [databaseContext forgetObject:anObj];
   }
