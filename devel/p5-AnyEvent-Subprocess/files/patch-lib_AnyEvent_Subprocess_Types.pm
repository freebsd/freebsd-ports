--- lib/AnyEvent/Subprocess/Types.pm.orig	2011-02-25 19:36:55 UTC
+++ lib/AnyEvent/Subprocess/Types.pm
@@ -39,7 +39,7 @@ coerce SubprocessCode, from ArrayRef[Str], via {
 subtype CodeList, as ArrayRef[CodeRef];
 coerce CodeList, from CodeRef, via { [$_] };
 
-enum WhenToCallBack, qw/Readable Line/;
+enum WhenToCallBack, [qw/Readable Line/];
 
 1;
 
