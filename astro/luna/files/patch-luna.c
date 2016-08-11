--- luna.c.orig	2016-07-26 13:07:24 UTC
+++ luna.c
@@ -25,27 +25,43 @@
 #include	"luna.h"
 
 
-void
+int
 main(argc, argv)
 	int		argc;
 	char	**argv;
 {
-	int			aotmoon, i;
-	struct tm	*localtmp, *algotmp;
-	char		*chp;
+	int			aotmoon, tzhere,
+				i;
+	struct tm	*localtmp, algotm;
+	char		*chp, *envp, *tzname;
 
-	getoptions(argc, argv, &localtmp, &algotmp);
+	getoptions(argc, argv, &localtmp);
+	envp = getenv("TZ");
+	if ((envp = getenv("TZ")) == NULL ||
+		(chp = strchr(envp, '-')) == NULL && (chp = strchr(envp, '+')) == NULL
+	   ) {
+		tzhere = TZ_DFL;   
+	} else {
+		tzhere = atoi(chp);	
+	}
+	tzconv(&algotm, localtmp, tzhere - TZ_ALGO);
+/*printf("%d %d:%d\n", algotm.tm_mday, algotm.tm_hour, algotm.tm_min);*/
+	
 	for (i = 0; i < bdate; i++) {
 		if (extluna) {
 			aotmoon = getext(localtmp -> tm_year, localtmp -> tm_mon,
 							 localtmp -> tm_mday);
 		} else {
-			aotmoon = getmoon(algotmp -> tm_year, algotmp -> tm_yday);
+			aotmoon = getmoon(algotm.tm_year, algotm.tm_yday);
 		}
 	
+
+		if ((tzname = getenv("TZ")) == NULL) {
+			tzname = TZNAME_DFL;
+		}
 		chp = Asctime(localtmp);
 		chp[LASCTIME - 2] = 0;
-		printf("%s", chp);
+		printf("%s %3.3s", chp, tzname);
 
 		if (numonly) {
 			printf("  ");
@@ -62,10 +78,11 @@ main(argc, argv)
 
 		today = FALSE;
 		tomorrow(localtmp);
-		tomorrow(algotmp);
+		tomorrow(&algotm);
 	}
 
 	exit(0);
+/* NEVERREACHED */
 }
 
 
@@ -177,18 +194,15 @@ usage()
 
 
 void
-getoptions(argc, argv, localtmpp, algotmpp)
+getoptions(argc, argv, localtmpp)
 	int			argc;
 	char		**argv;
 	struct tm	**localtmpp;
-	struct tm	**algotmpp;
 {
-	int				argnum[3], argnumcnt,
-					tzhere;
-	char			*chp, *envp;
+	int				argnum[3], argnumcnt;
+	char			*chp;
 	register int	j, i;
 	BOOLEAN			namedmon, followname;
-	static struct tm	algotm;
 	struct tm		*localtmp;
 
 	argnumcnt = 0;
@@ -375,20 +389,7 @@ getoptions(argc, argv, localtmpp, algotm
 	localtmp -> tm_yday
 		= ymd2yday(localtmp -> tm_year, localtmp -> tm_mon,
 			localtmp -> tm_mday);
-
-	envp = getenv("TZ");
-	if ((envp = getenv("TZ")) == NULL ||
-		(chp = strchr(envp, '-')) == NULL && (chp = strchr(envp, '+')) == NULL
-	   ) {
-		tzhere = TZ_DFL;   
-	} else {
-		tzhere = atoi(chp);	
-	}
-	tzconv(&algotm, localtmp, tzhere - TZ_ALGO);
-printf("%d %d:%d\n", algotm.tm_mday, algotm.tm_hour, algotm.tm_min);
-	
 	*localtmpp = localtmp;
-	*algotmpp  = &algotm;
 
 	return;
 }
