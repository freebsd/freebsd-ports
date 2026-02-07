--- src/CReplayDataHeader.h.orig	2015-11-21 23:18:19.000000000 +0100
+++ src/CReplayDataHeader.h	2015-12-04 19:36:24.513338595 +0100
@@ -1,7 +1,7 @@
 struct ReplayDataHeader
 {
 	char map[PATH_MAX];
-	long randomSeed;
+	time_t randomSeed;
 	float version;
 	int release;
 	int skill;
