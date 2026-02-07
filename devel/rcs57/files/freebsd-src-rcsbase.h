--- src/rcsbase.h
+++ freebsd/gnu/usr.bin/rcs/lib/rcsbase.h	1999-08-28 03:37:10.000000000 +0400
@@ -427,10 +426,12 @@ struct assoc {
 #define REVISION        "Revision"
 #define SOURCE          "Source"
 #define STATE           "State"
-#define keylength 8 /* max length of any of the above keywords */
+#define CVSHEADER       "CVSHeader"
+#define keylength 9 /* max length of any of the above keywords */
 
 enum markers { Nomatch, Author, Date, Header, Id,
-	       Locker, Log, Name, RCSfile, Revision, Source, State };
+	       Locker, Log, Name, RCSfile, Revision, Source, State, CVSHeader,
+	       LocalId };
 	/* This must be in the same order as rcskeys.c's Keyword[] array. */
 
 #define DELNUMFORM      "\n\n%s\n%s\n"
@@ -501,6 +502,7 @@ RILE *rcsreadopen P((struct buf*,struct 
 char *bufenlarge P((struct buf*,char const**));
 char const *basefilename P((char const*));
 char const *getfullRCSname P((void));
+char const *getfullCVSname P((void));
 char const *maketemp P((int));
 char const *rcssuffix P((char const*));
 int pairnames P((int,char**,RILE*(*)P((struct buf*,struct stat*,int)),int,int));
@@ -531,8 +533,11 @@ extern struct buf prevauthor, prevdate, 
 int getoldkeys P((RILE*));
 
 /* rcskeys */
-extern char const *const Keyword[];
+extern char const *Keyword[];
+extern enum markers LocalIdMode;
 enum markers trymatch P((char const*));
+void setRCSLocalId(char const *);
+void setIncExc(char const *);
 
 /* rcslex */
 extern FILE *foutptr;
