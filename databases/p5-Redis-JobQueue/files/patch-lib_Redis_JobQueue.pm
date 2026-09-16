--- lib/Redis/JobQueue.pm.orig	2026-09-16 14:27:32 UTC
+++ lib/Redis/JobQueue.pm
@@ -61,7 +61,7 @@ use Params::Util qw(
     _NONNEGINT
     _STRING
 );
-use Redis '1.976';
+use Redis 1.976;
 use Redis::JobQueue::Job qw(
     STATUS_CREATED
     STATUS_WORKING
