--- gnats/query.c.dist	Wed Nov 25 08:15:19 1998
+++ gnats/query.c	Thu May 15 18:15:59 2003
@@ -488,7 +488,7 @@
   
   if (query_format & FORMAT_SQL)
     {
-      char *t, *q, *tempstr;
+      char *t, *q, *tempstr, *fmtstring;
 
       tempstr = (char *) xmalloc (strlen (i->synopsis) + 1);
       strcpy (tempstr, i->synopsis);
@@ -503,7 +503,12 @@
       if (q != NULL)
 	*q = '\0';
 
-      fprintf (outfile, "%1.1d|%1.1d|%-16.16s|%1.1d|%1.1d|%-16.16s|",
+#ifdef USE_WIDE_RESPONSIBLE
+      fmtstring = "%1.1d|%1.1d|%-20.20s|%1.1d|%1.1d|%-16.16s|";
+#else
+      fmtstring = "%1.1d|%1.1d|%-16.16s|%1.1d|%1.1d|%-16.16s|";
+#endif
+      fprintf (outfile, fmtstring,
 	       sql_types (i->severity, Severity), sql_types (i->priority, Priority),
 	       tempstr,
 	       sql_types (i->state, State), sql_types (i->class, Class),
