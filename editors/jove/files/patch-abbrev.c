--- abbrev.c.orig	1996-03-07 17:34:41 UTC
+++ abbrev.c
@@ -274,7 +274,16 @@ EditAbbrevs()
 		"jabbXXXXXX"
 #endif
 		);
+#ifndef NO_MKSTEMP
+	{
+		int fd = mkstemp(tname);
+		if ( fd == -1 )
+			err( 1, "can't create temp file %s", tname );
+		close( fd );
+	}
+#else
 	(void) mktemp(tname);
+#endif
 	save_abbrevs(tname);
 	setfname(ebuf, tname);
 	read_file(tname, NO);
