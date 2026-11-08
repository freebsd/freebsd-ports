--- t/18.t.orig	2026-08-22 22:01:49 UTC
+++ t/18.t
@@ -41,7 +41,7 @@
 } (1 .. 20);
 my $CacheCount = @Caches;
 
-my $FdCount = scalar(() = glob "/proc/$$/fd/*");
+my $FdCount = scalar(`/usr/bin/fstat -p $$ | wc -l` - 1);
 ok($FdCount > $CacheCount, "More fd's than caches: $FdCount > $CacheCount");
 
 pipe(my $ReadPipeFh, my $WritePipeFh)
