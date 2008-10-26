--- srvrsnpp.c.orig	1998-10-25 14:55:05.000000000 -0500
+++ srvrsnpp.c	2008-10-24 11:00:36.226381386 -0400
@@ -523,6 +523,7 @@
 	char		*errmsg;
 	char		*a;
 	char		*b;
+	char		*m;
 	int		i;
 	int		badarg;
 	int		gotpager;
@@ -701,7 +702,16 @@
 
 				p->created = time(NULL);
 				(void)sprintf(buff, "%d", pagecount++);
-				(void)strcat(p->messageid, buff);
+				m = (void *)malloc(sizeof(*m) * (strlen(p->messageid) + strlen(buff) + 1));
+				if ( m == NULL ) {
+					message("554 Message failed (out of memory)");
+					qpage_log(LOG_ERR, "snpp(): cannot allocate memory for p->messageid");
+					clear_page(p, TRUE);
+					break;
+				}
+				(void)sprintf(m, "%s%s", p->messageid, buff);
+				my_free(p->messageid);
+				p->messageid = m;
 
 				qpage_log(LOG_ALERT, "page submitted, id=%s, from=%s",
 					p->messageid,
