--- config.c.orig	2002-12-13 09:56:37 UTC
+++ config.c
@@ -29,14 +29,10 @@
 #include <malloc.h>
 #endif
 
-extern Token *tokenPop(Token **);
-extern void freeToken(Token *);
-extern void streamMore(Input *);
-
 List *config = noList;
 
 static struct {
-	char		*name;
+	const char	*name;
 	ParamType	code;
 } pvals[] ={
 	{"var",		PVAR},
@@ -71,10 +67,10 @@ static struct {
 	{(char *) 0,	0}
 };
 
-void dumpPdata(ParamData *pt, FILE *op)
+static void dumpPdata(ParamData *pt, FILE *op)
 {
     int i;
-    char *pad;
+    const char *pad;
     List *lp;
 
     for (i=0; pvals[i].name != (char *) 0; i += 1)
@@ -91,7 +87,7 @@ void dumpPdata(ParamData *pt, FILE *op)
 	    {
 	        while (lp != noList)
 		{
-		    fprintf(op, "%x ", (int) lp->item);
+		  fprintf(op, "%x ", (int)(size_t) lp->item);
 		    lp = lp->next;
 		}
 	        fprintf(op, "}");
@@ -104,7 +100,7 @@ void dumpPdata(ParamData *pt, FILE *op)
 
 }
 
-void dumpConf(ConfigData *cp, FILE *op)
+void dumpConf(const ConfigData *cp, FILE *op)
 {
     List *plp;
 
@@ -118,7 +114,7 @@ void dumpConf(ConfigData *cp, FILE *op)
     fprintf(op, "}\n");
 }
 
-static void pcode(ParamData *ppt, char *str)
+static void pcode(ParamData *ppt, const char *str)
 {
     int i;
 
@@ -171,8 +167,7 @@ static void param(Token *tp, List **plist)
     ParamData *ppt;
     SeqnData *sd;
     void *dp;
-    extern void dumpToken(Token *, FILE *);
-    
+ 
     ppt = newpdata();
     switch (tp->type)
     {
@@ -252,7 +247,7 @@ static void parlist(Token *tp, List **plist)
     freeToken(lp2);
 }
 
-static int handle(Token *line)
+static int confighandle(Token *line)
 {
     ConfigData *cpt;
     Token *hd, *tp;
@@ -306,11 +301,11 @@ static int handle(Token *line)
     return 1;
 }
 
-void readconfig(char *str)
+void readconfig(const char *str)
 {
     FILE *fd;
     Input file;
-    
+
     if ((fd = fopen(str, "r")) == NULL)
     {
 	fprintf(stderr, "Warning: cannot open config file\n");
@@ -319,21 +314,21 @@ void readconfig(char *str)
 /*
  * use the tokenising mechanism we already have to parse the config file
  */
-    file.text = (char *) malloc(64*1024);
+    file.atext = malloc(64*1024);
     file.stream = fd;
     file.tcall = file.texpr = 0;
     file.lineNumber = 1;
     file.lineStart = 1;
     streamMore(&file);
-    while(handle(collect(&file)))
+    while(confighandle(collect(&file)))
     {
         /* skip */
     }
-    free(file.text);  
+    free(file.atext);
     fclose(fd);
 }
 
-void stringconfig(char *str)
+void stringconfig(const char *str)
 {
     Input file;
 /*
@@ -346,7 +341,7 @@ void stringconfig(char *str)
     file.tcall = file.texpr = 0;
     file.lineNumber = 1;
     file.lineStart = 1;
-    while(handle(collect(&file)))
+    while(confighandle(collect(&file)))
     {
         /* skip */
     }
