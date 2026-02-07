--- src/rlog.c
+++ freebsd/gnu/usr.bin/rcs/rlog/rlog.c	1999-08-28 03:37:10.000000000 +0400
@@ -222,7 +221,7 @@
 mainProg(rlogId, "rlog", "$Id: rlog.c,v 5.18 1995/06/16 06:19:24 eggert Exp $")
 {
 	static char const cmdusage[] =
-		"\nrlog usage: rlog -{bhLNRt} -ddates -l[lockers] -r[revs] -sstates -Vn -w[logins] -xsuff -zzone file ...";
+		"\nrlog usage: rlog -{bhLNRt} -v[string] -ddates -l[lockers] -r[revs] -sstates -Vn -w[logins] -xsuff -zzone file ...";
 
 	register FILE *out;
 	char *a, **newargv;
@@ -239,9 +238,12 @@ mainProg(rlogId, "rlog", "$Id: rlog.c,v 
 	int pre5;
 	int shownames;
 	int revno;
+	int versionlist;
+	char *vstring;
 
         descflag = selectflag = shownames = true;
-	onlylockflag = onlyRCSflag = false;
+	versionlist = onlylockflag = onlyRCSflag = false;
+	vstring=0;
 	out = stdout;
 	suffixes = X_DEFAULT;
 
@@ -318,6 +320,11 @@ mainProg(rlogId, "rlog", "$Id: rlog.c,v 
 			setRCSversion(*argv);
 			break;
 
+		case 'v':
+			versionlist = true;
+			vstring = a;
+			break;
+
                 default:
 		unknown:
 			error("unknown option: %s%s", *argv, cmdusage);
@@ -371,6 +378,12 @@ mainProg(rlogId, "rlog", "$Id: rlog.c,v 
 	    if (onlylockflag && !Locks)
 		continue;
 
+	    if ( versionlist ) {
+		gettree();
+		aprintf(out, "%s%s %s\n", vstring, workname, tiprev());
+		continue;
+	    }
+
 	    if ( onlyRCSflag ) {
 		aprintf(out, "%s\n", RCSname);
 		continue;
@@ -462,6 +475,7 @@ mainProg(rlogId, "rlog", "$Id: rlog.c,v 
 		putrunk();
 		putree(Head);
 	    }
+	    aputs("----------------------------\n", out);
 	    aputs("=============================================================================\n",out);
 	  }
 	Ofclose(out);
