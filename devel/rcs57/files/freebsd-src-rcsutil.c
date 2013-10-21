--- src/rcsutil.c
+++ freebsd/gnu/usr.bin/rcs/lib/rcsutil.c	1999-08-28 03:37:10.000000000 +0400
@@ -1231,8 +1230,15 @@ getRCSINIT(argc, argv, newargv)
 	char **argv, ***newargv;
 {
 	register char *p, *q, **pp;
+	char const *ev;
 	size_t n;
 
+	if ((ev = cgetenv("RCSLOCALID")))
+		setRCSLocalId(ev);
+
+	if ((ev = cgetenv("RCSINCEXC")))
+		setIncExc(ev);
+
 	if (!(q = cgetenv("RCSINIT")))
 		*newargv = argv;
 	else {
