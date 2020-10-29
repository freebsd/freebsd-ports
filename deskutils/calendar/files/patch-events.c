--- events.c.orig	2020-10-18 03:01:26 UTC
+++ events.c
@@ -207,8 +207,9 @@ event_print_all(FILE *fp)
 
 	while (walkthrough_dates(&e) != 0) {
 #ifdef DEBUG
-		fprintf(stderr, "event_print_allmonth: %d, day: %d\n",
-		    month, day);
+		if (e)
+			fprintf(stderr, "event_print_all month: %d, day: %d\n",
+			    e->month, e->day);
 #endif
 
 		/*
