--- tcl.c.orig	2004-01-22 13:25:48 UTC
+++ tcl.c
@@ -26,50 +26,42 @@
 static int nest[32]; /* = = class, 1 = namespace */
 static int inproc = 0;
 
-static Token lbraceToken	= {LBRACE, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token rbraceToken	= {RBRACE, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token xcontToken		= {XCONT, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token ostartToken	= {OSTART, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token startToken		= {START, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token contToken		= {CONT, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token econtToken		= {ECONT, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token emToken		= {EM, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token nospToken		= {NOSP, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
+static Token lbraceToken	= {.type = LBRACE, .ckind = CNSTWORD};
+static Token rbraceToken	= {.type = RBRACE, .ckind = CNSTWORD};
+static Token xcontToken		= {.type = XCONT, .ckind = CNSTWORD};
+static Token ostartToken	= {.type = OSTART, .ckind = CNSTWORD};
+static Token startToken		= {.type = START, .ckind = CNSTWORD};
+static Token contToken		= {.type = CONT, .ckind = CNSTWORD};
+static Token econtToken		= {.type = ECONT, .ckind = CNSTWORD};
+static Token emToken		= {.type = EM, .ckind = CNSTWORD};
+static Token nospToken		= {.type = NOSP, .ckind = CNSTWORD};
 static Token *olsToken		= &emToken;
-static Token spToken		= {SP, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token lbrackToken	= {LBRACK, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token rbrackToken	= {RBRACK, CNSTWORD, 0, (char *) 0, 0, (Token *) 0, (Token *) 0};
-static Token msgcatToken	= {CONST, CNSTWORD, 0, "::msgcat::mc", 12, (Token *) 0, (Token *) 0};
+static Token spToken		= {.type = SP, .ckind = CNSTWORD};
+static Token lbrackToken	= {.type = LBRACK, .ckind = CNSTWORD};
+static Token rbrackToken	= {.type = RBRACK, .ckind = CNSTWORD};
+static Token msgcatToken	= {.type = CONST, .ckind = CNSTWORD, .text = "::msgcat::mc", .length = 12};
 
-static Token dqStart		= {DQSTART, CNSTWORD, 0, (char *) 0, 0, noToken, noToken};
-static Token dqEnd		= {DQEND, CNSTWORD, 0, (char *) 0, 0, noToken, noToken};
-static Token thenToken		= {CONST, CNSTWORD, 0, "then", 4, noToken, noToken};
-static Token procToken		= {CONST, CNSTWORD, 0, "proc", 4, noToken, noToken};
-static Token elseToken		= {CONST, CNSTWORD, 0, "else", 4, noToken, noToken};
-static Token elseifToken	= {CONST, CNSTWORD, 0, "elseif", 6, noToken, noToken};
-static Token methodToken	= {CONST, CNSTWORD, 0, "method", 6, noToken, noToken};
-static Token semiToken		= {SEMI, CNSTWORD, 0, ";", 1, noToken, noToken};
-static Token argsToken		= {SEMI, CNSTWORD, 0, "args", 4, noToken, noToken};
-static Token argvToken		= {SEMI, CNSTWORD, 0, "argv", 4, noToken, noToken};
-static Token argv0Token		= {SEMI, CNSTWORD, 0, "argv0", 5, noToken, noToken};
-static Token platfToken		= {SEMI, CNSTWORD, 0, "tcl_platform", 12, noToken, noToken};
+static Token dqStart		= {.type = DQSTART, .ckind = CNSTWORD};
+static Token dqEnd		= {.type = DQEND, .ckind = CNSTWORD};
+static Token thenToken		= {.type = CONST, .ckind = CNSTWORD, .text = "then", .length = 4};
+static Token procToken		= {.type = CONST, .ckind = CNSTWORD, .text = "proc", .length = 4};
+static Token elseToken		= {.type = CONST, .ckind = CNSTWORD, .text = "else", .length = 4};
+static Token elseifToken	= {.type = CONST, .ckind = CNSTWORD, .text = "elseif", .length = 6};
+static Token methodToken	= {.type = CONST, .ckind = CNSTWORD, .text = "method", .length = 6};
+static Token semiToken		= {.type = SEMI, .ckind = CNSTWORD, .text = ";", .length = 1};
+static Token argsToken		= {.type = SEMI, .ckind = CNSTWORD, .text = "args", .length = 4};
+static Token argvToken		= {.type = SEMI, .ckind = CNSTWORD, .text = "argv", .length = 4};
+static Token argv0Token		= {.type = SEMI, .ckind = CNSTWORD, .text = "argv0", .length = 5};
+static Token platfToken		= {.type = SEMI, .ckind = CNSTWORD, .text = "tcl_platform", .length = 12};
 
 List *blocks  = noList;
 
-static CheckIt **noChecks = (CheckIt **) 0;
-
-extern void setIndent(void);
-extern void outdent(void);
-extern int isVarToken(Token *);
-extern int isSwitch(Token *);
-extern int isSingleCall(Token *, char *);
-extern int tokEqual(Token *, char *);
-
 /*
  * If there are no more tokens, print a useful message to the user and
  * exit.
  */
-void failIfNullToken(Token *token, char *part, char *command, int ln)
+static void failIfNullToken(const Token *token, const char *part,
+    const char *command, int ln)
 {
     char msg[1024];
 
@@ -77,11 +69,11 @@ void failIfNullToken(Token *token, char *part, char *c
     {
 	if (ln == 0)
 	{
-	    sprintf(msg, "Missing \"%s\" part in call of %s", part, command);
+	    snprintf(msg, sizeof msg, "Missing \"%s\" part in call of %s", part, command);
 	}
 	else
 	{
-	    sprintf(msg, "Missing \"%s\" part in call of %s, starting line %d",
+	    snprintf(msg, sizeof msg, "Missing \"%s\" part in call of %s, starting line %d",
 	      part, command, ln);
 	}
 	fail(token, msg);
@@ -92,7 +84,8 @@ void failIfNullToken(Token *token, char *part, char *c
  * If there are more tokens after this one, print a useful warning to
  * the user.
  */
-void warnIfArgsAfter(Token *token, char *part, char *command)
+static void warnIfArgsAfter(const Token *token, const char *part,
+    const char *command)
 {
     char msg[1024];
 
@@ -106,25 +99,25 @@ void warnIfArgsAfter(Token *token, char *part, char *c
 	{
 	    if (*part != '\0')
 	    {
-		sprintf(msg, "Extra arguments after \"%s\" part in call of %s",
+		snprintf(msg, sizeof msg, "Extra arguments after \"%s\" part in call of %s",
 		  part, command);
 	    }
 	    else
 	    {
-		sprintf(msg, "Extra arguments in call of `%s'", command);
+		snprintf(msg, sizeof msg, "Extra arguments in call of `%s'", command);
 	    }
 	    warn(token, msg);
 	    if (token->next != noToken && token->next->text != (char *) 0 &&
 	      token->next->text[0] != '\0')
 	    {
-		sprintf(msg, "Extra token is `%s'", token->next->text);
+		snprintf(msg, sizeof msg, "Extra token is `%s'", token->next->text);
 		warn(token->next, msg);
 	    }
 	}
     }
 }
 
-void warnExpr(Token *cmd, char *txt)
+static void warnExpr(const Token *cmd, const char *txt)
 {
     if (doTest(HEXPR) && cmd != noToken && cmd->type != LIST)
     {
@@ -132,21 +125,14 @@ void warnExpr(Token *cmd, char *txt)
     }
 }
 
-void warnFor(Token *token, char *cmd, char *txt)
+void warnFor(const Token *token, const char *cmd, const char *txt)
 {
     char msg[1024];
 
-    sprintf(msg, txt, cmd);
+    snprintf(msg, sizeof msg, txt, cmd);
     warn(token, msg);
 }
 
-static void warnIFor(Token *token, int val, char *txt)
-{
-    char msg[1024];
-
-    sprintf(msg, txt, val);
-    warn(token, msg);
-}
 /*
  * reset various variables so that multiple file processing doesn't get
  * screwed up
@@ -170,7 +156,7 @@ void clearState(void)
     setVar(&platfToken, VGLOBAL, 1);
 }
 
-static int isNumber(char *cp)
+static int isNumber(const char *cp)
 {
     if (*cp == '-' || *cp == '+')
     {
@@ -187,9 +173,9 @@ static int isNumber(char *cp)
     return 1;    
 }
 
-static int tokIsLevel(Token *tp)
+static int tokIsLevel(const Token *tp)
 {
-    char *cp;
+    const char *cp;
     if (tp == noToken || !(tp->type == CONST || tp->type == LIST) || tp->text == (char *) 0)
     {
 	return 0;
@@ -207,7 +193,7 @@ static int tokIsLevel(Token *tp)
     return isNumber(cp);
 }
 
-static int oneLine(Token *seq, int semis)
+static int oneLine(const Token *seq, int semis)
 {
     while (seq != noToken)
     {
@@ -221,7 +207,7 @@ static int oneLine(Token *seq, int semis)
     return 1;
 }
 
-static int checkSpecial(char *val)
+static int checkSpecial(const char *val)
 {
     char ch;
 
@@ -238,17 +224,17 @@ static int checkSpecial(char *val)
     return 1;
 }
 
-static void checkUnquoted(Token *str)
+static void checkUnquoted(const Token *str)
 {
     char msg[128];
     if (noquotes && str->type == CONST && str->ckind == CNSTWORD && !isNumber(str->text))
     {
-        sprintf(msg, "Unquoted constant - \"%s\"", str->text);
+        snprintf(msg, sizeof msg, "Unquoted constant - \"%s\"", str->text);
         warn(str, msg);
     }
 }
 
-static void checkType(Token *cmd, int flags)
+static void checkType(const Token *cmd, int flags)
 {
     if (cmd->type == CONST)
     {
@@ -266,7 +252,7 @@ static void checkType(Token *cmd, int flags)
     }
 }
 
-static int single(Token * tp)
+static int single(const Token * tp)
 {
     if (tp != noToken && tp->next == noToken)
     {
@@ -285,13 +271,13 @@ static int single(Token * tp)
     return 0;
 }
 
-static int sconstant(Token *tp)
+static int sconstant(const Token *tp)
 {
     return (tp != noToken && tp->next == noToken
 	&& (tp->type == CONST || tp->type == LIST) && !checkSpecial(tp->text));
 }
 
-static int constantString(Token * tp, int any)
+static int constantString(const Token * tp, int any)
 {
     Token *sq;
     if (tp == noToken) return 0;
@@ -312,12 +298,12 @@ static int constantString(Token * tp, int any)
     }
 }
 
-void loopstart(int inf, int cond)
+static void loopstart(int inf, int cond)
 {
     pushBlock(noToken, inf, -1, cond);
 }
 
-void loopend(void)
+static void loopend(void)
 {
     Blox *bp = lpeek(blocks);
     int il = bp->infloop, su = (bp->breaks == 0);
@@ -329,7 +315,7 @@ void loopend(void)
     }
 }
 
-static void msgsave(Token *tp, int any)
+static void msgsave(const Token *tp, int any)
 {
     char filename[128];
 
@@ -362,10 +348,11 @@ static void msgsave(Token *tp, int any)
     }
 }
 
-void sptclop(Token *hd)
+static void doUser(Token *hd, Token *cmd, const ConfigData *cpt, int nostart);
+
+static void sptclop(Token *hd)
 {
     List *cpt = config;
-    extern void doUser(Token *hd, Token *cmd, ConfigData *cpt, int nostart);
     ConfigData *cdp;
 
     while (cpt != noList)
@@ -528,7 +515,7 @@ typedef enum flags_e {
     SPACEOUT	= 020
 } PressFlags;
 
-static void press(Token *v , PressFlags flags, CheckIt **checkp)
+static void press(Token *v , PressFlags flags)
 {
     Input *idx;
     Token *token = noToken, *lst = noToken;
@@ -601,7 +588,7 @@ done :
 		switch (token->type)
 		{
 		case SEMI :
-		    if (flags && SEMIS)
+		    if (flags & SEMIS)
 		    {
 			output(&semiToken, 1);
 		    }
@@ -640,7 +627,7 @@ done :
     }
 }
 
-void etcetera(Token *cmd, int v)
+static void etcetera(Token *cmd, int v)
 {
     while (cmd != noToken)
     {
@@ -649,7 +636,7 @@ void etcetera(Token *cmd, int v)
     }
 }
 
-void catbin(Token *tp)
+static void catbin(Token *tp)
 {
     int sem, oln;
     Token *sols;
@@ -692,7 +679,8 @@ static void handleVar(Token *hd, Token *cmd, int flags
     enum VarType vt;
     VarData *vp = (VarData *) 0;
     char msg[1024];
-    Token *ap = noToken, *ac;
+    Token *ap = noToken;
+    const Token *ac;
     int array = 0;
 
     if (isVarToken(cmd))
@@ -828,7 +816,7 @@ void makeCall (Token *prc, Token *arg)
     }
 }
 
-Token *doswitch(Token *cmd, Token *leadin)
+static Token *doswitch(Token *cmd, Token *leadin)
 {
     Token *tp, *bod;
     int ln = leadin->lineNo, eopt = 0, dflt = 0, srtp = 1;
@@ -951,7 +939,7 @@ Token *doswitch(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doif(Token *cmd, Token *leadin)
+static Token *doif(Token *cmd, Token *leadin)
 {
     Token *tp, *then;
     int efl = ADDBRACES, ln = leadin->lineNo, cfl = ADDBRACES | PAREN;
@@ -963,7 +951,7 @@ Token *doif(Token *cmd, Token *leadin)
     {
 	cfl |= SPACEOUT;
     }
-    press(cmd, cfl, noChecks);
+    press(cmd, cfl);
     if (putThen) { output(&thenToken, 0); }
     then = cmd->next;
     if (tokEqual(then, "then")) { then = then->next; }
@@ -979,7 +967,7 @@ Token *doif(Token *cmd, Token *leadin)
 	tp = tp->next;
 	failIfNullToken(tp, "condition", "elseif", ln);
         warnExpr(tp, "elseif condition not braced.");
-	press(tp, efl | PAREN, noChecks);
+	press(tp, efl | PAREN);
 	tp = tp->next;
 	failIfNullToken(tp, "body", "elseif", ln);
 	body(tp, 0, 0);
@@ -1019,9 +1007,9 @@ Token *doif(Token *cmd, Token *leadin)
 }
 
 
-int isNSName(Token *cmd)
+static int isNSName(const Token *cmd)
 {
-    char *cp;
+    const char *cp;
     int cols = 0;
 
     if (!constant(cmd) || cmd->text == (char *) 0) { return 0; }
@@ -1053,7 +1041,7 @@ int isNSName(Token *cmd)
     return 0;
 }
 
-static Token *doProc(Token *tag, Token *cmd, Token *leadin, int checkNS)
+static Token *doProc(Token *tag, Token *cmd, Token *leadin)
 {
     int ln = leadin->lineNo, inns;
     Token *token, *tok2, *tok3;
@@ -1176,15 +1164,15 @@ static Token *doProc(Token *tag, Token *cmd, Token *le
 
 static Token *doproc(Token *cmd, Token *leadin)
 {
-    return doProc(&procToken, cmd, leadin, 1);
+    return doProc(&procToken, cmd, leadin);
 }
 
 static Token *domethod(Token *cmd, Token *leadin)
 {
-    return doProc(&methodToken, cmd, leadin, 0);
+    return doProc(&methodToken, cmd, leadin);
 }
 
-static Token *dodestructor(Token *cmd, Token *leadin)
+static Token *dodestructor(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     if (!nest[0])
     {
@@ -1199,7 +1187,7 @@ static Token *dodestructor(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doconstructor(Token *cmd, Token *leadin)
+static Token *doconstructor(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     if (!nest[0])
     {
@@ -1208,7 +1196,7 @@ Token *doconstructor(Token *cmd, Token *leadin)
     else
     {
 	failIfNullToken(cmd, "args", "constructor", 0);
-	press(cmd, NOBRACE | ADDBRACES, noChecks);
+	press(cmd, NOBRACE | ADDBRACES);
 	cmd = cmd->next;
 	failIfNullToken(cmd, "body", "constructor", 0);
 	body(cmd, 0, 0);
@@ -1217,7 +1205,7 @@ Token *doconstructor(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doreturn(Token *cmd, Token *leadin)
+static Token *doreturn(Token *cmd, Token *leadin)
 {
     Blox *pr = (Blox *) lpeek(blocks);
 
@@ -1266,7 +1254,7 @@ Token *doreturn(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doregexp(Token *cmd, Token *leadin)
+static Token *doregexp(Token *cmd, Token *leadin)
 {
     int eopt = 0;
     int ln = cmd->lineNo, paramCount = 0;
@@ -1311,7 +1299,7 @@ Token *doregexp(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doregsub(Token *cmd, Token *leadin)
+static Token *doregsub(Token *cmd, Token *leadin)
 {
     int eopt = 0;
     int ln = cmd->lineNo, paramCount = 0;
@@ -1360,7 +1348,7 @@ Token *doregsub(Token *cmd, Token *leadin)
     return cmd->next;
 }
 
-Token *dobind(Token *cmd, Token *leadin)
+static Token *dobind(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     Token *np;
     if (!doBind || pragma & NOFORMAT)
@@ -1386,7 +1374,7 @@ Token *dobind(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doitcl_class(Token *cmd, Token *leadin)
+static Token *doitcl_class(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     failIfNullToken(cmd, "className", "itcl_class", 0);
     output(cmd, 1);
@@ -1399,7 +1387,7 @@ Token *doitcl_class(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *docvar(Token *cmd, Token *prt)
+static Token *docvar(Token *cmd, Token *prt)
 {
     if (!nest[0])
     {
@@ -1411,14 +1399,14 @@ Token *docvar(Token *cmd, Token *prt)
 	output(cmd, 1);
 	if ((cmd = cmd->next) != noToken)
 	{
-	    press(cmd, NOBRACE | ADDBRACES, noChecks);
+	    press(cmd, NOBRACE | ADDBRACES);
 	    warnIfArgsAfter(cmd, "init", prt->text);
 	}
     }
     return noToken;
 }
 
-Token *dopublic(Token *cmd, Token *leadin)
+static Token *dopublic(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     if (!nest[0])
     {
@@ -1430,7 +1418,7 @@ Token *dopublic(Token *cmd, Token *leadin)
 	output(cmd, 1);
 	if ((cmd = cmd->next) != noToken)
 	{
-	    press(cmd, NOBRACE | ADDBRACES, noChecks);
+	    press(cmd, NOBRACE | ADDBRACES);
 	    if ((cmd = cmd->next) != noToken)
 	    {
 		body(cmd, 0, 0);
@@ -1441,11 +1429,11 @@ Token *dopublic(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doprotected(Token *cmd, Token *leadin) { return docvar(cmd, leadin); }
+static Token *doprotected(Token *cmd, Token *leadin) { return docvar(cmd, leadin); }
 
-Token *docommon(Token *cmd, Token *leadin) { return docvar(cmd, leadin); }
+static Token *docommon(Token *cmd, Token *leadin) { return docvar(cmd, leadin); }
 
-static void checkVar(Token *cmd, char *nm)
+static void checkVar(Token *cmd, const char *nm)
 {
     List *bp = blocks;
     Blox *xp;
@@ -1524,7 +1512,7 @@ static void addForVars(Token *cmd)
     }
 }
 
-Token *doforeach(Token *cmd, Token *leadin)
+static Token *doforeach(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     failIfNullToken(cmd, "varName", "foreach", 0);
     loopstart(0, 0);
@@ -1534,7 +1522,7 @@ Token *doforeach(Token *cmd, Token *leadin)
 	addForVars(cmd);
 	cmd = cmd->next;
 	failIfNullToken(cmd, "list", "foreach", 0);
-	press(cmd, NOBRACE, noChecks);
+	press(cmd, NOBRACE);
 	cmd = cmd->next;
     }
     while (cmd != noToken && cmd->next != noToken && cmd->next->type != SCOMMENT);
@@ -1546,7 +1534,7 @@ Token *doforeach(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doloop(Token *cmd, Token *leadin)
+static Token *doloop(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     Token *tp;
     if (!tclX)
@@ -1556,15 +1544,15 @@ Token *doloop(Token *cmd, Token *leadin)
     else
     {
 	failIfNullToken(cmd, "var", "loop", 0);
-	press(cmd, NOBRACE | ADDBRACES, noChecks);	/* var */
+	press(cmd, NOBRACE | ADDBRACES);	/* var */
 	tp = cmd->next;
 	failIfNullToken(tp, "first", "loop", 0);
 	warnExpr(cmd, "Unbracketed loop \"first\"");
-	press(tp, ADDBRACES, noChecks);			/* first */
+	press(tp, ADDBRACES);			/* first */
 	tp = tp->next;
 	failIfNullToken(tp, "limit", "loop", 0);
 	warnExpr(cmd, "Unbracketed loop \"limit\"");
-	press(tp, ADDBRACES, noChecks);			/* limit */
+	press(tp, ADDBRACES);			/* limit */
 
 	tp = tp->next;
 	failIfNullToken(tp, "body", "loop", 0);
@@ -1572,7 +1560,7 @@ Token *doloop(Token *cmd, Token *leadin)
 	if (tp->next != noToken)
 	{
 	    warnExpr(cmd, "Unbracketed loop \"incr\"");
-	    press(tp, NOBRACE | ADDBRACES, noChecks);		/* incr */
+	    press(tp, NOBRACE | ADDBRACES);		/* incr */
 	    tp = tp->next;
 	}
 	loopstart(0, 0);
@@ -1584,7 +1572,7 @@ Token *doloop(Token *cmd, Token *leadin)
     return noToken;
 } 
 
-Token *doexpr(Token *cmd, Token *leadin)
+static Token *doexpr(Token *cmd, Token *leadin __attribute__((__unused__)))
 {
     if (!doExpr)
     {
@@ -1599,7 +1587,7 @@ Token *doexpr(Token *cmd, Token *leadin)
 	else if (cmd->next == noToken)
 	{
 	    warnExpr(cmd, "expr body not braced.");
-	    press(cmd, ADDBRACES | PAREN, noChecks); /* */
+	    press(cmd, ADDBRACES | PAREN); /* */
 	}
 	else
 	{
@@ -1610,7 +1598,7 @@ Token *doexpr(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *dounset(Token *cmd, Token *leadin)
+static Token *dounset(Token *cmd, Token *leadin)
 {
     int pCount = 1;
 
@@ -1641,7 +1629,7 @@ Token *dounset(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *doupvar(Token *cmd, Token *leadin)
+static Token *doupvar(Token *cmd, Token *leadin)
 {
     int paramCount = 0;
     int ln = leadin->lineNo;
@@ -1672,7 +1660,7 @@ Token *doupvar(Token *cmd, Token *leadin)
     return noToken;
 }
 
-Token *dovariable(Token *cmd, Token *leadin)
+static Token *dovariable(Token *cmd, Token *leadin)
 {
     int paramCount = 1;
 
@@ -1776,7 +1764,7 @@ static int valuecheck(ParamData *pdp, Token *cmd)
     return 0;
 }
 
-void doBasic(ConfigData *cpt, Token *hd, Token *cmd)
+static void doBasic(const ConfigData *cpt, Token *hd, Token *cmd)
 {
     List *sp, *llp, *lp;
     ParamData *pt, *pdp;
@@ -1793,7 +1781,7 @@ void doBasic(ConfigData *cpt, Token *hd, Token *cmd)
 	pt = (ParamData *) lpeek(lp);
 	if (pt != (ParamData *) 0 && pt->values != noList)
 	{
-	    ptpar = (int) lpeek(pt->values);
+	  ptpar = (int)(size_t) lpeek(pt->values);
 	}
 	else
 	{
@@ -1850,7 +1838,7 @@ void doBasic(ConfigData *cpt, Token *hd, Token *cmd)
 	    }
 	    else
 	    {
-		press(cmd, NOBRACE | ADDBRACES | SEMIS, noChecks); /* */
+		press(cmd, NOBRACE | ADDBRACES | SEMIS); /* */
 	    }
 	    break;
 
@@ -1862,7 +1850,7 @@ void doBasic(ConfigData *cpt, Token *hd, Token *cmd)
 	    else
 	    {
 		warnExpr(cmd, "Unbracketed expression");
-		press(cmd, ptpar, noChecks); /* */
+		press(cmd, ptpar); /* */
 	    }
 	    break;
 
@@ -1883,7 +1871,7 @@ void doBasic(ConfigData *cpt, Token *hd, Token *cmd)
 		{
 		    ptpar |= SPACEOUT;
 		}
-		press(cmd, ptpar, noChecks);
+		press(cmd, ptpar);
 		loopstart(infloop, 1);
 	    }
 	    break;
@@ -2085,7 +2073,7 @@ void doBasic(ConfigData *cpt, Token *hd, Token *cmd)
 	pt = (ParamData *) lpeek(lp);
 	if ((sp = pt->values) != noList)
 	{
-	    ptpar = (int) lpeek(sp);
+	  ptpar = (int)(size_t) lpeek(sp);
 	}
 	else
 	{
@@ -2140,7 +2128,8 @@ void doBasic(ConfigData *cpt, Token *hd, Token *cmd)
     }
 }
 
-void doUser(Token *hd, Token *cmd, ConfigData *cpt, int nostart)
+static void doUser(Token *hd, Token *cmd,
+    const ConfigData *cpt, int nostart)
 {
     if (isUnreachable())
     {
