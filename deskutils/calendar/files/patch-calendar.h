--- calendar.h.orig	2020-10-18 03:01:26 UTC
+++ calendar.h
@@ -122,7 +122,7 @@ extern int	year1, year2;
  * - Use event_continue() to add more text to the last added event
  * - Use event_print_all() to display them in time chronological order
  */
-struct event *event_add(int, int, int, char *, int, char *, char *);
+struct event *event_add(int, int, int, int, char *, char *);
 void	event_continue(struct event *events, char *txt);
 void	event_print_all(FILE *fp);
 struct event {
@@ -130,7 +130,6 @@ struct event {
 	int	month;
 	int	day;
 	int	var;
-	char	*date;
 	char	*text;
 	char	*extra;
 	struct event *next;
@@ -189,7 +188,7 @@ int	remember_yd(int y, int d, int *rm, int *rd);
 int	first_dayofweek_of_year(int y);
 int	first_dayofweek_of_month(int y, int m);
 int	walkthrough_dates(struct event **e);
-void	addtodate(struct event *e, int year, int month, int day);
+void	addtodate(struct event *e);
 
 /* pom.c */
 #define	MAXMOONS	18
