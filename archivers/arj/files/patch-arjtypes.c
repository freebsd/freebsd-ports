--- arjtypes.c	2005-06-23 UTC
+++ arjtypes.c
@@ -138,8 +138,11 @@ static int isleapyear(int year)
 static unsigned long ts_unix2dos(const long ts)
 {
  struct tm *stm;
+ time_t _ts;
 
- stm=arj_localtime(&ts);
+ _ts = ts;
+
+ stm=arj_localtime(&_ts);
  return(get_tstamp(stm->tm_year+1900, stm->tm_mon+1, stm->tm_mday,
         stm->tm_hour, stm->tm_min, stm->tm_sec));
 }
