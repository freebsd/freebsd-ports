--- src/dnshistory.h.orig	2020-08-28 19:46:38 UTC
+++ src/dnshistory.h
@@ -163,7 +163,7 @@ typedef struct {
  *                              GLOBALS                                 *
  ************************************************************************/
 /*-- Date/Time --*/
-time_t current_day;                             /* The current day, check to see if we need to update a record in this run
+extern time_t current_day;                             /* The current day, check to see if we need to update a record in this run
                                                    Also see SAME_RUN */
 
 /*-- DB Setup --*/
