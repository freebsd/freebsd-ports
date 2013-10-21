--- src/rcskeys.c
+++ freebsd/gnu/usr.bin/rcs/lib/rcskeys.c
@@ -67,14 +66,22 @@
 libId(keysId, "$Id: rcskeys.c,v 5.4 1995/06/16 06:19:24 eggert Exp $")
 
 
-char const *const Keyword[] = {
+char const *Keyword[] = {
     /* This must be in the same order as rcsbase.h's enum markers type. */
 	0,
 	AUTHOR, DATE, HEADER, IDH,
-	LOCKER, LOG, NAME, RCSFILE, REVISION, SOURCE, STATE
+	LOCKER, LOG, NAME, RCSFILE, REVISION, SOURCE, STATE, CVSHEADER,
+	NULL
 };
 
-
+/* Expand all keywords by default */
+static int ExpandKeyword[] = {
+	false,
+	true, true, true, true,
+	true, true, true, true, true, true, true, true,
+	true
+};
+enum markers LocalIdMode = Id;
 
 	enum markers
 trymatch(string)
@@ -87,8 +94,12 @@ trymatch(string)
         register int j;
 	register char const *p, *s;
 	for (j = sizeof(Keyword)/sizeof(*Keyword);  (--j);  ) {
+		if (!ExpandKeyword[j])
+			continue;
 		/* try next keyword */
 		p = Keyword[j];
+		if (p == NULL)
+			continue;
 		s = string;
 		while (*p++ == *s++) {
 			if (!*p)
@@ -104,3 +115,72 @@ trymatch(string)
         return(Nomatch);
 }
 
+	void
+setIncExc(arg)
+	char const *arg;
+/* Sets up the ExpandKeyword table according to command-line flags */
+{
+	char *key;
+	char *copy, *next;
+	int include = 0, j;
+
+	copy = strdup(arg);
+	next = copy;
+	switch (*next++) {
+	    case 'e':
+		include = false;
+		break;
+	    case 'i':
+		include = true;
+		break;
+	    default:
+		free(copy);
+		return;
+	}
+	if (include)
+		for (j = sizeof(Keyword)/sizeof(*Keyword);  (--j);  )
+			ExpandKeyword[j] = false;
+	key = strtok(next, ",");
+	while (key) {
+		for (j = sizeof(Keyword)/sizeof(*Keyword);  (--j);  ) {
+			if (Keyword[j] == NULL)
+				continue;
+			if (!strcmp(key, Keyword[j]))
+				ExpandKeyword[j] = include;
+		}
+		key = strtok(NULL, ",");
+	}
+	free(copy);
+	return;
+}
+
+	void
+setRCSLocalId(string)
+	char const *string;
+/* function: sets local RCS id and RCSLOCALID envariable */
+{
+	static char local_id[keylength+1];
+	char *copy, *next, *key;
+	int j;
+
+	copy = strdup(string);
+	next = copy;
+	key = strtok(next, "=");
+	if (strlen(key) > keylength)
+		faterror("LocalId is too long");
+	VOID strcpy(local_id, key);
+	Keyword[LocalId] = local_id;
+
+	/* options? */
+	while (key = strtok(NULL, ",")) {
+		if (!strcmp(key, Keyword[Id]))
+			LocalIdMode=Id;
+		else if (!strcmp(key, Keyword[Header]))
+			LocalIdMode=Header;
+		else if (!strcmp(key, Keyword[CVSHeader]))
+			LocalIdMode=CVSHeader;
+		else
+			error("Unknown LocalId mode");
+	}
+	free(copy);
+}
