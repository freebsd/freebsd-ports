--- src/rtc_tc8521.c.orig	2020-12-01 19:49:05 UTC
+++ src/rtc_tc8521.c
@@ -167,7 +167,7 @@ static void tc8521_set_nvrram(uint8_t *nvrram, struct 
 	{
 		nvrram[TC8521_HOUR1]    = (cur_time_tm->tm_hour % 12) % 10;	
 		nvrram[TC8521_HOUR10]   = ((cur_time_tm->tm_hour % 12) / 10) 
-					 | (cur_time_tm->tm_hour >= 12) ? 2 : 0;
+					 | ((cur_time_tm->tm_hour >= 12) ? 2 : 0);
 	}
 	nvrram[TC8521_WEEKDAY] = cur_time_tm->tm_wday;
 	nvrram[TC8521_DAY1]    = cur_time_tm->tm_mday % 10;
