--- frink.h.orig	2004-01-22 14:01:52 UTC
+++ frink.h
@@ -99,3 +99,17 @@ extern List *config;
 
 extern List *skiplist;
 extern List *blocks;
+
+void dumpConf(const ConfigData *, FILE*);
+void readconfig(const char *fileName);
+void stringconfig(const char *line);
+void initOutput(void);
+void setIndent(void);
+void outdent(void);
+int isVarToken(const Token *);
+int isSwitch(const Token *);
+int isSingleCall(const Token *, const char *);
+int tokEqual(const Token *, const char *);
+void flushOutput(void);
+void clearState(void);
+void warnFor(const Token *token, const char *cmd, const char *txt);
