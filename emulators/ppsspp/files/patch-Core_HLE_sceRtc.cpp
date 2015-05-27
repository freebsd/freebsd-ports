--- Core/HLE/sceRtc.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/HLE/sceRtc.cpp
@@ -459,12 +459,10 @@ static int sceRtcConvertLocalTimeToUTC(u
 	{
 		u64 srcTick = Memory::Read_U64(tickLocalPtr);
 		// TODO : Let the user select his timezone / daylight saving instead of taking system param ?
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if !defined(_MSC_VER) && !defined(_AIX) && !defined(__sgi) && !defined(__hpux)
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		srcTick -= time->tm_gmtoff*1000000ULL;
-#else
-		srcTick -= -timezone * 1000000ULL;
 #endif
 		Memory::Write_U64(srcTick, tickUTCPtr);
 	}
@@ -482,12 +480,10 @@ static int sceRtcConvertUtcToLocalTime(u
 	{
 		u64 srcTick = Memory::Read_U64(tickUTCPtr);
 		// TODO : Let the user select his timezone / daylight saving instead of taking system param ?
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if !defined(_MSC_VER) && !defined(_AIX) && !defined(__sgi) && !defined(__hpux)
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		srcTick += time->tm_gmtoff*1000000ULL;
-#else
-		srcTick += -timezone * 1000000ULL;
 #endif
 		Memory::Write_U64(srcTick, tickLocalPtr);
 	}
@@ -1015,12 +1011,10 @@ static int sceRtcFormatRFC2822LocalTime(
 	}
 
 	int tz_seconds;
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if !defined(_MSC_VER) && !defined(_AIX) && !defined(__sgi) && !defined(__hpux)
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		tz_seconds = time->tm_gmtoff;
-#else
-		tz_seconds = -timezone;
 #endif
 
 	DEBUG_LOG(SCERTC, "sceRtcFormatRFC2822LocalTime(%08x, %08x)", outPtr, srcTickPtr);
@@ -1050,12 +1044,10 @@ static int sceRtcFormatRFC3339LocalTime(
 	}
 
 	int tz_seconds;
-#if defined(__GLIBC__) || defined(BLACKBERRY) || defined(__SYMBIAN32__)
+#if !defined(_MSC_VER) && !defined(_AIX) && !defined(__sgi) && !defined(__hpux)
 		time_t timezone = 0;
 		tm *time = localtime(&timezone);
 		tz_seconds = time->tm_gmtoff;
-#else
-		tz_seconds = -timezone;
 #endif
 
 	DEBUG_LOG(SCERTC, "sceRtcFormatRFC3339LocalTime(%08x, %08x)", outPtr, srcTickPtr);
