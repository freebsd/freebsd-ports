--- sope-appserver/NGObjWeb/WOSessionStore.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOSessionStore.m
@@ -49,7 +49,7 @@
   WOSession *session;
   *(&session) = nil;
   
-  SYNCHRONIZED(self) { // this must become a condition lock !!!
+  SYNCHRONIZED((id)self) { // this must become a condition lock !!!
     if (![self->checkedOutSessions containsObject:_sid]) {
       if ((session = [self restoreSessionWithID:_sid]))
         [self->checkedOutSessions addObject:_sid];
@@ -66,7 +66,7 @@
   NSString *sid;
   *(&sid) = [[_context session] sessionID];
   
-  SYNCHRONIZED(self) { // this must become a condition lock !!!
+  SYNCHRONIZED((id)self) { // this must become a condition lock !!!
     [self saveSessionForContext:_context];
     
     if ([self->checkedOutSessions containsObject:sid])
