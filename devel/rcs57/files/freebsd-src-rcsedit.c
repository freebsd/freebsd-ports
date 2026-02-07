--- src/rcsedit.c
+++ freebsd/gnu/usr.bin/rcs/lib/rcsedit.c
@@ -1050,12 +1049,17 @@ keyreplace(marker, delta, delimstuffed, 
 		aputs(date2str(date,datebuf), out);
                 break;
 	    case Id:
+	    case LocalId:
 	    case Header:
-		escape_string(out,
-			marker==Id || RCSv<VERSION(4)
-			? basefilename(RCSname)
-			: getfullRCSname()
-		);
+	    case CVSHeader:
+		if (marker == Id || RCSv < VERSION(4) ||
+		    (marker == LocalId && LocalIdMode == Id))
+			escape_string(out, basefilename(RCSname));
+		else if (marker == CVSHeader ||
+		    (marker == LocalId && LocalIdMode == CVSHeader))
+			escape_string(out, getfullCVSname());
+		else
+			escape_string(out, getfullRCSname());
 		aprintf(out, " %s %s %s %s",
 			delta->num,
 			date2str(date, datebuf),
@@ -1503,6 +1507,9 @@ makedirtemp(isworkfile)
 	register size_t dl;
 	register struct buf *bn;
 	register char const *name = isworkfile ? workname : RCSname;
+#	if has_mktemp
+	int fd;
+#	endif
 
 	dl = basefilename(name) - name;
 	bn = &dirtpname[newRCSdirtp_index + isworkfile];
@@ -1521,10 +1528,12 @@ makedirtemp(isworkfile)
 	catchints();
 #	if has_mktemp
 		VOID strcpy(tp, "XXXXXX");
-		if (!mktemp(np) || !*np)
+		fd = mkstemp(np);
+		if (fd < 0 || !*np)
 		    faterror("can't make temporary pathname `%.*s_%cXXXXXX'",
 			(int)dl, name, '0'+isworkfile
 		    );
+		close(fd);
 #	else
 		/*
 		 * Posix 1003.1-1990 has no reliable way
