Index: lib/cconv.c
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/cconv.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- lib/cconv.c	7 Dec 2009 06:36:04 -0000	1.1.1.1
+++ lib/cconv.c	7 Dec 2009 06:50:44 -0000	1.3
@@ -604,6 +604,7 @@ static char	*rcsid = "$Id: cconv.c,v 10.
 #endif
 
 #include	<stdio.h>
+#include	<stdlib.h>
 #include	<X11/Xlib.h>
 #include	<X11/keysym.h>
 #include	<X11/Xutil.h>
@@ -672,8 +673,6 @@ static char	*rcsid = "$Id: cconv.c,v 10.
 
 #define ccEncodeChar(c)	((ulong)(c))
 
-#define NOMODE		0xffff
-
 #define MATCHED_CHAR	0x8080	/* $B$3$l$O(B EUC $B$H$7$F$O(B illegal $B$J%3!<%I$J$N$G(B
 				 * $BFCJL$JL\E*$KMQ$$$k(B */
 #define CCLEAR_CHAR	0x8081	/* $B>e$KF1$8(B */
@@ -688,15 +687,20 @@ typedef struct convdesc {
 	ushort	context;	/* context$BJ8;zNs(B ($B5U=g$K3JG<$5$l$k(B) */
 	ushort	result;		/* $BJQ497k2LJ8;zNs(B */
 	ushort	function;	/* function $B%Y%/%?$N%$%s%G%C%/%9(B */
+
+	struct convdesc	*next;
 } ConvDesc;
 
 /* $B%b!<%I$4$H$N%F!<%V%k(B */
-typedef struct {
-	char		*name;		/* $B%b!<%IL>(B */
+typedef struct modetable {
+	char		name[1024];	/* $B%b!<%IL>(B */
 	int		nrule;		/* $B%k!<%k$N?t(B */
-	ConvDesc	*cdbuf;		/* $B%k!<%k(B */
+	struct convdesc	*cd_head;	/* $B%k!<%k(B */
 	wchar		*prompt;	/* $B%W%m%s%W%HJ8;zNs(B */
-	ushort		fallthrough;
+
+	int		mt_index;
+	struct modetable	*fallthrough;
+	struct modetable	*next;
 } ModeTable;
 
 /* ccParseRule() $B$GFbItI=8=$KJQ49$5$l$?%k!<%k(B */
@@ -705,8 +709,8 @@ typedef struct _ccRule {
 	ccRule		next;		/* $B%k!<%k%j%9%H$N<!$NMWAG(B */
 	int		refcnt;		/* $B;2>H?t(B */
 	int		nmode;		/* $B%b!<%I$N?t(B */
-	int		initialmode;	/* $B=i4|%b!<%I(B */
-	ModeTable	*modes;		/* $B%b!<%I%F!<%V%k(B */
+	struct modetable	*initialmode;	/* $B=i4|%b!<%I(B */
+	struct modetable	*modes;	/* $B%b!<%I%F!<%V%k(B */
 	wchar		*strbuf;	/* $B%9%H%j%s%0%P%C%U%!(B */
 	ushort		*funcbuf;	/* $B%U%!%s%/%7%g%s%P%C%U%!(B */
 	int		nfunc;		/* $B%U%!%s%/%7%g%s$N?t(B */
@@ -731,8 +735,8 @@ typedef struct _ccBuf {
 	void	(*autofix)();
 	void	(*modenotify)();
 	caddr_t	client_data;
-	int	currentmode;		/* $B8=:_$N%b!<%I(B */
-	int	previousmode;		/* $B0l$DA0$N%b!<%I(B */
+	struct modetable *currentmode;		/* $B8=:_$N%b!<%I(B */
+	struct modetable *previousmode;		/* $B0l$DA0$N%b!<%I(B */
 	wchar	*context;
 	wchar	*contextend;
 	int	contextsize;
@@ -747,14 +751,6 @@ typedef struct {
 	wchar	*strp;
 } _strbufRec;
 
-#define	CDSIZE		10
-#define	MORECDSIZE	30
-typedef struct {
-	ConvDesc	*cdbuf;		/* ConvDesc $B%"%l%$(B */
-	ConvDesc	*cdend;
-	ConvDesc	*cdp;
-} _cdbufRec;
-
 #define FUNCSIZE	20
 #define MOREFUNCSIZE	20
 typedef struct {
@@ -797,7 +793,7 @@ static int newMode(ccRule, Files *, _str
 		   _funcnameRec *, int, uchar **);
 static int getDesc(ccRule, uchar *, _funcbufRec *, _funcnameRec *,
 		   ulong *, int *, wchar *, wchar *, int *);
-static int getMode(ccRule, uchar *);
+static struct modetable *getMode(ccRule, uchar *);
 static uchar *getQuote(uchar *, wchar *, int);
 static int getKey(uchar *, ulong *, int *);
 static int getmask(uchar *);
@@ -810,14 +806,12 @@ static void deleteRule(ccRule);
 static int wstrsave(_strbufRec *, wchar *);
 static int wstralloc(_strbufRec *, int);
 static void wstradjust(_strbufRec *);
-static ConvDesc *cdalloc(_cdbufRec *);
-static void cdadjust(_cdbufRec *);
 static int funcalloc(_funcbufRec *, int);
 static void funcadjust(_funcbufRec *);
 static int funcsearch(_funcnameRec *, char *);
 static void funcnameadjust(_funcnameRec *);
 static int convchar(ccBuf, ulong, int, char *, int);
-static int cconvert(ccBuf, int, ulong, int, int *, char *, int);
+static int cconvert(ccBuf, struct modetable *, ulong, int, int *, char *, int);
 static int metamatch(ulong, ulong, int);
 static int contextMatch(ccBuf, wchar *);
 static void substStr(ccBuf, wchar *, wchar *, char *, int);
@@ -841,8 +835,6 @@ static int getFunc();
 static int wstrsave();
 static int wstralloc();
 static void wstradjust();
-static ConvDesc *cdalloc();
-static void cdadjust();
 static int funcalloc();
 static void funcadjust();
 static int funcsearch();
@@ -1098,7 +1090,7 @@ char *file;
 	fnrec.funcnamebuf = NULL;
 
 	rule->nmode = 0;
-	rule->initialmode = -1;
+	rule->initialmode = NULL;
 
 	while (getline(line, sizeof(line), &files, efunc)) {
 		(void)Strcpy(tmp, line);
@@ -1191,33 +1183,42 @@ int ac;
 uchar **av;
 {
 	int		nmode;
-	ModeTable	*modes;
 	int		i;
+	struct modetable	*mtp;
+	struct modetable	*mt_head;
 
 	ac--, av++;
 
 	nmode = ac;
-	modes = (ModeTable *)Malloc(nmode * sizeof(ModeTable));
-	if (modes == NULL) {
+	if ((mt_head = malloc(sizeof(struct modetable))) == NULL) {
 		eproc(rule->errorfunc, "can't alloc memory");
 		return -1;
 	}
-	rule->modes = modes;
+	memset(mt_head, 0, sizeof(struct modetable));
+	mt_head->mt_index = -1;
+	mtp = mt_head;
 
 	for (i = 0; i < nmode; i++) {
-		if ((modes[i].name = Malloc(Strlen(av[i]) + 1)) == NULL) {
+		if ((mtp->next = malloc(sizeof(struct modetable))) == NULL) {
 			eproc(rule->errorfunc, "can't alloc memory");
-			Free(modes);
 			return -1;
 		}
-		(void)Strcpy(modes[i].name, av[i]);
-		modes[i].nrule = 0;
-		modes[i].cdbuf = NULL;
-		modes[i].prompt = NULL;
-		modes[i].fallthrough = NOMODE;
+		memset(mtp->next, 0, sizeof(struct modetable));
+		mtp->next->mt_index = mtp->mt_index + 1;
+		mtp = mtp->next;
+
+		strncpy(mtp->name, av[i], sizeof(mtp->name) -1);
+		mtp->name[sizeof(mtp->name) - 1] = '\0';
+
+		mtp->nrule = 0;
+		mtp->cd_head = NULL;
+		mtp->prompt = NULL;
+		mtp->fallthrough = NULL;
 	}
 
+	rule->modes = mt_head->next;
 	rule->nmode = nmode;
+	free(mt_head);
 	return 0;
 }
 
@@ -1238,35 +1239,39 @@ uchar **av;
 	wchar		prompt[30], context[100], result[100];
 	int		func;
 	int		ndesc = 0;
-	ModeTable	*mp;
-	ConvDesc	*cdp;
-	_cdbufRec	cdbuf;
+	struct modetable	*mtp;
+	struct convdesc	*cdp;
+	struct convdesc	*cd_head;
 	void		(*efunc)() = rule->errorfunc;
 
 	/* $B%U%)!<%^%C%H$O(B
 	 * "mode <$B%b!<%IL>(B> <"$B%W%m%s%W%HJ8;zNs(B"> [fallthrough <$B%b!<%IL>(B>]
 	 */
 	/* $B%b!<%I$N%A%'%C%/(B */
-	if ((mode = getMode(rule, av[1])) < 0) {
+	if ((mtp = getMode(rule, av[1])) == NULL) {
 		EPROC2(efunc, "illegal modename: %s", av[1]);
 		return -1;	/* No Such Mode */
 	}
-	mp = &rule->modes[mode];
 
 	if (getQuote(av[2], prompt, 0) == NULL) {
 		EPROC2(efunc, "illegal prompt: %s", av[2]);
 		return -1;
 	}
-	mp->prompt = promptsave(prompt);
-	mp->nrule = 0;
+
+	mtp->prompt = promptsave(prompt);
+	mtp->nrule = 0;
 	
 	if (ac > 4 && !Strcmp(av[3], "fallthrough")) {
-		mp->fallthrough = getMode(rule, av[4]);
+		mtp->fallthrough = getMode(rule, av[4]);
 	} else {
-		mp->fallthrough = NOMODE;
+		mtp->fallthrough = NULL;
 	}
 
-	cdbuf.cdbuf = NULL;
+	if ((cd_head = malloc(sizeof(struct convdesc))) == NULL) {
+		return -1;
+	}
+	memset(cd_head, 0, sizeof(struct convdesc));
+	cdp = cd_head;
 
 	/* $B%k!<%k$rFI$s$G%9%H%"$9$k(B */
 	while (getline(line, sizeof(line), files, efunc)) {
@@ -1277,9 +1282,11 @@ uchar **av;
 			break;
 		if (getDesc(rule, line, frec, fnrec, &inkey, &modmask,
 			    context, result, &func)) {
-			if ((cdp = cdalloc(&cdbuf)) == NULL) {
+			if ((cdp->next = malloc(sizeof(struct convdesc))) == NULL) {
 				return -1;
 			}
+			memset(cdp->next, 0, sizeof(struct convdesc));
+			cdp = cdp->next;
 
 			/* $B%k!<%k$N%9%H%"(B */
 			cdp->key = inkey;
@@ -1297,10 +1304,11 @@ uchar **av;
 	 * $B$"$j$&$k(B
 	 */
 
-	cdadjust(&cdbuf);
+	mtp->nrule = ndesc;
 
-	mp->nrule = ndesc;
-	mp->cdbuf = cdbuf.cdbuf;
+	/* cd_head is always empty. cd_head->next is the head. */
+	mtp->cd_head = cd_head->next;
+	free(cd_head);
 
 	return 0;
 }
@@ -1357,19 +1365,21 @@ int *funcp;
 	return 1;
 }
 
-static int getMode(rule, str)
+static struct modetable *getMode(rule, str)
 ccRule rule;
 uchar *str;
 {
-	ModeTable	*modes = rule->modes;
-	int	i;
+	struct modetable	*mtp = rule->modes;
 
-	for (i = 0; i < rule->nmode; i++) {
-		if (!Strcmp(str, modes[i].name))
-			return i;
+	while (mtp) {
+		if (!Strcmp(str, mtp->name)) {
+			return mtp;
+		}
+		mtp = mtp->next;
 	}
+
 	EPROC2(rule->errorfunc, "undefined mode %s", str);
-	return -1;
+	return NULL;
 }
 
 /* getQuote -- $B%/%)!<%F!<%7%g%s5-9f$G0O$^$l$?J8;zNs$rFI$s$G(B wchar $B$K$9$k(B */
@@ -1609,6 +1619,7 @@ uchar	**args;
 	ushort	*fp;
 	int	findex;
 	void	(*efunc)() = rule->errorfunc;
+	struct modetable *mtp;
 
 	findex = funcalloc(frec, n + 1);
 	fp = frec->funcbuf + findex;
@@ -1626,10 +1637,10 @@ uchar	**args;
 				fp[j++] = PREVMODE;
 				break;
 			}
-			if ((i = getMode(rule, arg)) < 0) {
+			if ((mtp = getMode(rule, arg)) == NULL) {
 				break;
 			}
-			fp[j++] = MODECHANGE | i;
+			fp[j++] = MODECHANGE | mtp->mt_index;
 			break;
 		} else if (!Strcmp(func, "redo")) {
 			fp[j++] = REDO;
@@ -1781,50 +1792,6 @@ _strbufRec *srec;
 	}
 }
 
-static ConvDesc *cdalloc(crec)
-_cdbufRec *crec;
-{
-	ConvDesc	*ret;
-
-	if (crec->cdbuf == NULL) {
-		crec->cdbuf = (ConvDesc *)Malloc(CDSIZE * sizeof(ConvDesc));
-		if (crec->cdbuf == NULL)
-			return NULL;
-		crec->cdend = crec->cdbuf + CDSIZE;
-		crec->cdp = crec->cdbuf;
-	}
-	if (crec->cdp >= crec->cdend) {
-		int	size = crec->cdend - crec->cdbuf + MORECDSIZE;
-		int	offset = crec->cdp - crec->cdbuf;
-		ConvDesc	*cdp;
-
-		cdp = (ConvDesc *)Realloc(crec->cdbuf, size * sizeof(ConvDesc));
-		if (cdp == NULL) {
-			return NULL;
-		}
-		crec->cdp = cdp + offset;
-		crec->cdbuf = cdp;
-		crec->cdend = cdp + size;
-	}
-
-	ret = crec->cdp++;
-	return ret;
-}
-
-static void cdadjust(crec)
-_cdbufRec *crec;
-{
-	int		size = crec->cdp - crec->cdbuf;
-	ConvDesc	*cdp;
-
-	if (size == 0) return;
-	cdp = (ConvDesc *)Realloc(crec->cdbuf, size * sizeof(ConvDesc));
-	if (cdp != NULL) {
-		crec->cdbuf = cdp;
-		crec->cdp = crec->cdend = cdp + size;
-	}
-}
-
 static int funcalloc(frec, n)
 _funcbufRec *frec;
 int n;
@@ -1961,13 +1928,13 @@ int len;	/* length of str */
 		/* $B%^%C%A$9$k%k!<%k$,8+$D$+$i$J$+$C$?$N$G(B
 		 * fallthrough $B$G;XDj$5$l$k%b!<%I$N%k!<%k$rC5$9(B
 		 */
-		int	tmpmode = rule->modes[buf->currentmode].fallthrough;
+		struct modetable *tmpmode = buf->currentmode->fallthrough;
 
-		while (tmpmode != NOMODE) {
+		while (tmpmode != NULL) {
 			r = cconvert(buf, tmpmode, key, mask, &func, str, len);
 			if (r >= 0)	/* $B%^%C%A$7$?(B */
 				break;
-			tmpmode = rule->modes[tmpmode].fallthrough;
+			tmpmode = tmpmode->fallthrough;
 		}
 	}
 
@@ -1985,7 +1952,7 @@ int len;	/* length of str */
 			else
 			    goto redo;	/* redo -- $B$b$&0lEY(B */
 		} else if (func & MODECHANGE) {	/* $B%+%l%s%H%b!<%I$NJQ99(B */
-			int	tmpmode = buf->currentmode;
+			struct modetable	*tmpmode = buf->currentmode;
 			
 			/* pseudo-key $B$NF~NO(B */
 			(void)convchar(buf, EXITMODE, 0, (char *)NULL, 0);
@@ -1993,7 +1960,15 @@ int len;	/* length of str */
 			if (func == PREVMODE) {
 				buf->currentmode = buf->previousmode;
 			} else {
-				buf->currentmode = func & ~MODECHANGE;
+				int index = func & ~MODECHANGE;
+				struct modetable *mtp;
+				for (mtp = rule->modes; mtp && mtp->mt_index != index; mtp = mtp->next)
+					;
+				if (mtp) {
+					buf->currentmode = mtp;
+				} else {
+					return -1;
+				}
 			}
 			buf->previousmode = tmpmode;
 			
@@ -2038,7 +2013,7 @@ int len;	/* length of str */
 
 static int cconvert(buf, mode, inkey, mask, func, str, len)
 ccBuf buf;
-int mode;	/* current mode */
+struct modetable *mode;	/* current mode */
 ulong inkey;	/* input key (raw/mapped) */
 int mask;
 int *func;	/* function */
@@ -2046,36 +2021,34 @@ char *str;
 int len;
 {
 	ccRule		rule = buf->rule;
-	ConvDesc	*entry;
+	struct convdesc	*cdp;
 	ulong		key;
 	int		n;
-	ModeTable	*modep;
+	struct modetable	*mtp = mode;
 
-	if (mode < 0 || mode >= rule->nmode)
+	if (mtp == NULL)
 		return -1;	/* No Such Mode */
 
-	modep = &rule->modes[mode];
-
-	if ((n = modep->nrule) <= 0)
+	if (mtp->nrule <= 0)
 		return -1;	/* No Rules */
 
-	for (entry = modep->cdbuf; --n >= 0; entry++) {
-		key = entry->key;
+	for (cdp = mtp->cd_head; cdp; cdp = cdp->next) {
+		key = cdp->key;
 		if (key & (ulong)METAC) {
 			/* $B%o%$%k%I%+!<%IJ8;z$N%^%C%A%s%0(B */
 			if (!metamatch(key, inkey, len == 0))
 				continue;
-		} else if (key & (ulong)RAWKEY && mask != entry->mask) {
+		} else if (key & (ulong)RAWKEY && mask != cdp->mask) {
 			continue;
 		} else if (key != inkey) {
 			continue;
 		}
 
 		/* $B%-!<$,%^%C%A$7$?(B */
-		if (contextMatch(buf, rule->strbuf + entry->context)) {
-			substStr(buf, rule->strbuf + entry->context,
-				 rule->strbuf + entry->result, str, len);
-			*func = entry->function;
+		if (contextMatch(buf, rule->strbuf + cdp->context)) {
+			substStr(buf, rule->strbuf + cdp->context,
+				 rule->strbuf + cdp->result, str, len);
+			*func = cdp->function;
 			return 0;
 		}
 	}
@@ -2347,7 +2320,6 @@ caddr_t data;		/* callback $B%G!<%?(B 
 
 	/* $B%+%l%s%H%b!<%I$N@_Dj(B */
 	buf->previousmode = buf->currentmode = rule->initialmode;
-
 	buf->modifier = 0;
 
 	return buf;
@@ -2357,7 +2329,7 @@ caddr_t data;		/* callback $B%G!<%?(B 
 void ccFreeRule(rule)
 ccRule rule;
 {
-	ModeTable	*modep;
+	struct modetable *mtp = rule->modes;
 	int		i;
 
 	if (rule == NULL) return;
@@ -2365,12 +2337,12 @@ ccRule rule;
 
 	deleteRule(rule);
 
-	for (modep = rule->modes, i = 0; i < rule->nmode; modep++, i++) {
-		Free(modep->name);
-		Free(modep->cdbuf);
-		Free(modep->prompt);
-	}
+	/* XXX */
+	Free(mtp->cd_head);
+	Free(mtp->prompt);
+
 	Free(rule->rulefile);
+	/* XXX */
 	Free(rule->modes);
 	Free(rule->strbuf);
 	Free(rule->funcbuf);
@@ -2468,14 +2440,14 @@ XKeyPressedEvent *event;	/* $B%-!<%$%Y%
 int ccGetMode(buf)
 ccBuf buf;
 {
-	return buf->currentmode;
+	return buf->currentmode->mt_index;
 }
 
 /* ccGetModePrompt -- $B8=:_$N%b!<%I$N%W%m%s%W%HJ8;zNs$rJV$9(B */
 wchar *ccGetModePrompt(buf)
 ccBuf buf;
 {
-	return buf->rule->modes[buf->currentmode].prompt;
+	return buf->currentmode->prompt;
 }
 
 /* ccGetRule -- $BJQ49%P%C%U%!$G;H$o$l$F$$$kJQ49%k!<%k$rJV$9(B */
@@ -2599,7 +2571,6 @@ ccBuf buf;
 	ccDestroyBuf(buf);
 }
 
-
 #ifdef DEBUG_CCONV
 /*
  *	Debug Functions
@@ -2625,11 +2596,11 @@ uchar *s;
 
 void dumpRules(rule, mode)
 ccRule rule;
-int mode;
+struct modetable *mode;
 {
 	int	nkey;
-	ModeTable	*modep;
-	ConvDesc	*cdp;
+	struct modetable *mtp;
+	struct convdesc	*cdp;
 	wchar		*strbuf = rule->strbuf;
 	ushort		*funcbuf = rule->funcbuf;
 	char		**funcnames;
@@ -2639,31 +2610,32 @@ int mode;
 	int	i, j;
 
 	funcnames = (char **)__builtin_alloca(rule->nfunc * sizeof(char *));
-{	char	*cp, **fnp;
-	cp = rule->funcnamebuf;
-	fnp = funcnames;
-	for (i = 0; i < rule->nfunc; i++) {
-		*fnp++ = cp;
-		while (*cp++)
-			;
+	{
+		char	*cp, **fnp;
+		cp = rule->funcnamebuf;
+		fnp = funcnames;
+		for (i = 0; i < rule->nfunc; i++) {
+			*fnp++ = cp;
+			while (*cp++)
+				;
+		}
 	}
-}
 
-	if (mode < 0 || mode >= rule->nmode) {
-		printf("No such mode %d\n", mode);
+	if (mode == NULL) {
+		printf("No such mode\n");
 		return;
 	}
-	modep = &rule->modes[mode];
+	mtp = rule->modes;
 
-	printf("mode: %s (%d) prompt: ", modep->name, mode);
-	putws(modep->prompt);
-	if (modep->fallthrough != NOMODE) {
-		printf(" fallthrough: %d", modep->fallthrough);
+	printf("mode: %s (%d) prompt: ", mtp->name, mtp->mt_index);
+	putws(mtp->prompt);
+	if (mtp->fallthrough != NULL) {
+		printf(" fallthrough: %s", mtp->fallthrough->name);
 	}
 	putchar('\n');
-	cdp = modep->cdbuf;
-	for (i = 0; i < modep->nrule; i++) {
-		printf("rule[%d]: \"", i);
+	
+	for (cdp = mtp->cd_head; cdp; cdp = cdp->next) {
+		printf("rule: \"");
 		putws(strbuf + cdp->context);
 		printf("\"\t");
 		if (cdp->key & RAWKEY) {
@@ -2763,14 +2735,15 @@ void dumpAllRules(rule)
 ccRule rule;
 {
 	int	i;
+	struct modetable *mtp;
 
 	printf("** RULE DUMP **\n");
 	printf("number of modes: %d  initialmode: %s (%d)\n\n",
 	       rule->nmode,
-	       rule->modes[rule->initialmode].name,
-	       rule->initialmode);
-	for (i = 0; i < rule->nmode; i++) {
-		dumpRules(rule, i);
+	       rule->initialmode->name,
+	       rule->initialmode->mt_index);
+	for (mtp = rule->modes; mtp; mtp = mtp->next) {
+		dumpRules(rule, mtp);
 	}
 	fflush(stdout);
 }
