--- builtin.c.orig	2015-03-31 04:38:58 UTC
+++ builtin.c
@@ -1039,7 +1039,7 @@ streng *std_time( tsd_t *TSD, cparamboxp
          break ;
 
       case 'L':
-         answer->len = sprintf(answer->value, "%02d:%02d:%02d.%06ld", tmdata.tm_hour, tmdata.tm_min, tmdata.tm_sec, unow );
+         answer->len = sprintf(answer->value, "%02d:%02d:%02d.%06ld", tmdata.tm_hour, tmdata.tm_min, tmdata.tm_sec, (long) unow );
          break ;
 
       case 'M':
@@ -1068,7 +1068,7 @@ streng *std_time( tsd_t *TSD, cparamboxp
 
       case 'T':
          rnow = mktime( &tmdata );
-         answer->len = sprintf(answer->value, "%ld", rnow );
+         answer->len = sprintf(answer->value, "%ld", (long) rnow );
          break ;
 
       default:
@@ -1308,7 +1308,7 @@ streng *std_date( tsd_t *TSD, cparamboxp
       case 'T':
          tmdata.tm_year -= 1900;
          rnow = mktime( &tmdata );
-         answer->len = sprintf(answer->value, "%ld", rnow );
+         answer->len = sprintf(answer->value, "%ld", (long) rnow );
          break ;
 
       case 'U':
