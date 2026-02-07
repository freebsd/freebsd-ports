--- builtin.c.orig	2019-10-06 06:19:40 UTC
+++ builtin.c
@@ -1037,7 +1037,7 @@ streng *std_time( tsd_t *TSD, cparamboxptr parms )
          break ;
 
       case 'L':
-         answer->len = sprintf(answer->value, "%02d:%02d:%02d.%06ld", tmdata.tm_hour, tmdata.tm_min, tmdata.tm_sec, unow );
+         answer->len = sprintf(answer->value, "%02d:%02d:%02d.%06ld", tmdata.tm_hour, tmdata.tm_min, tmdata.tm_sec, (long) unow );
          break ;
 
       case 'M':
@@ -1066,7 +1066,7 @@ streng *std_time( tsd_t *TSD, cparamboxptr parms )
 
       case 'T':
          rnow = mktime( &tmdata );
-         answer->len = sprintf(answer->value, "%ld", rnow );
+         answer->len = sprintf(answer->value, "%ld", (long) rnow );
          break ;
 
       default:
@@ -1302,7 +1302,7 @@ streng *std_date( tsd_t *TSD, cparamboxptr parms )
       case 'T':
          tmdata.tm_year -= 1900;
          rnow = mktime( &tmdata );
-         answer->len = sprintf(answer->value, "%ld", rnow );
+         answer->len = sprintf(answer->value, "%ld", (long) rnow );
          break ;
 
       case 'U':
