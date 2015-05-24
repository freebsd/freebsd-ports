--- Core/HLE/sceRtc.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/HLE/sceRtc.cpp
@@ -459,7 +459,7 @@ static int sceRtcConvertLocalTimeToUTC(u
 	{
 		u64 srcTick = Memory::Read_U64(tickLocalPtr);
 		// TODO : Let the user select his timezone / daylight saving instead of taking system param ?
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if 1 // #else block uses undeclared `timezone'
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		srcTick -= time->tm_gmtoff*1000000ULL;
@@ -482,7 +482,7 @@ static int sceRtcConvertUtcToLocalTime(u
 	{
 		u64 srcTick = Memory::Read_U64(tickUTCPtr);
 		// TODO : Let the user select his timezone / daylight saving instead of taking system param ?
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if 1 // #else block uses undeclared `timezone'
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		srcTick += time->tm_gmtoff*1000000ULL;
@@ -1015,7 +1015,7 @@ static int sceRtcFormatRFC2822LocalTime(
 	}
 
 	int tz_seconds;
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if 1 // #else block uses undeclared `timezone'
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		tz_seconds = time->tm_gmtoff;
@@ -1050,7 +1050,7 @@ static int sceRtcFormatRFC3339LocalTime(
 	}
 
 	int tz_seconds;
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if 1 // #else block uses undeclared `timezone'
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		tz_seconds = time->tm_gmtoff;
