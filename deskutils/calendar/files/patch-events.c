--- events.c.orig	2020-10-18 03:01:26 UTC
+++ events.c
@@ -150,8 +150,7 @@ convert(char *input)
 }
 
 struct event *
-event_add(int year, int month, int day, char *date, int var, char *txt,
-    char *extra)
+event_add(int year, int month, int day, int var, char *txt, char *extra)
 {
 	struct event *e;
 
@@ -159,25 +158,22 @@ event_add(int year, int month, int day, char *date, in
 	 * Creating a new event:
 	 * - Create a new event
 	 * - Copy the machine readable day and month
-	 * - Copy the human readable and language specific date
 	 * - Copy the text of the event
 	 */
 	e = (struct event *)calloc(1, sizeof(struct event));
 	if (e == NULL)
 		errx(1, "event_add: cannot allocate memory");
+	e->year = year;
 	e->month = month;
 	e->day = day;
 	e->var = var;
-	e->date = convert(date);
-	if (e->date == NULL)
-		errx(1, "event_add: cannot allocate memory");
 	e->text = convert(txt);
 	if (e->text == NULL)
 		errx(1, "event_add: cannot allocate memory");
 	e->extra = NULL;
 	if (extra != NULL && extra[0] != '\0')
 		e->extra = convert(extra);
-	addtodate(e, year, month, day);
+	addtodate(e);
 	return (e);
 }
 
@@ -204,19 +200,31 @@ void
 event_print_all(FILE *fp)
 {
 	struct event *e;
+	struct tm tm;
+	char dbuf[80];
+	static int d_first;
 
+	d_first = (*nl_langinfo(D_MD_ORDER) == 'd');
+
 	while (walkthrough_dates(&e) != 0) {
+		if (e) {
 #ifdef DEBUG
-		fprintf(stderr, "event_print_allmonth: %d, day: %d\n",
-		    month, day);
+			fprintf(stderr, "event_print_all month: %d, day: %d\n",
+			    e->month, e->day);
 #endif
+			memset(&tm, 0, sizeof(struct tm));
+			tm.tm_mday = e->day;
+			tm.tm_mon = e->month - 1;
+			tm.tm_year = e->year - 1900;
+			(void)strftime(dbuf, sizeof(dbuf), d_first ? "%e %b" : "%b %e", &tm);
+		}
 
 		/*
 		 * Go through all events and print the text of the matching
 		 * dates
 		 */
 		while (e != NULL) {
-			(void)fprintf(fp, "%s%c%s%s%s%s\n", e->date,
+			(void)fprintf(fp, "%s%c%s%s%s%s\n", dbuf,
 			    e->var ? '*' : ' ', e->text,
 			    e->extra != NULL ? " (" : "",
 			    e->extra != NULL ? e->extra : "",
