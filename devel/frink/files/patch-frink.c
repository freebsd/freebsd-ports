--- frink.c.orig	2003-10-02 20:18:05 UTC
+++ frink.c
@@ -28,6 +28,7 @@
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
+#include <unistd.h>
 
 int failed	= 0;
 int lineNumber	= 0;
@@ -39,7 +40,7 @@ int warndyn	= 0;
 int fascist	= 0;
 
 int compout	= 0;
-int resvsplit	= 0;
+static int resvsplit = 0;
 int noquotes	= 0;
 int spaceout	= 0;
 int trystrings	= 0;
@@ -80,30 +81,21 @@ int nonlelsif	= 0;
 int extract	= 0;
 int internat	= 0;
 
-char *style		= (char *) 0;
-char *pstyle		= (char *) 0;
-char *contString 	= "";
+const char *style	= NULL;
+const char *pstyle	= NULL;
+const char *contString 	= "";
 
-char *locale		= (char *) 0;
+const char *locale	= NULL;
 FILE *msgfile		= NULL;
 FILE *specfile		= NULL;
 
 int pragma		= 0;
 int praghold		= 0;
 
-char *currentfile	= (char *) 0;
+const char *currentfile	= NULL;
 
-List *skiplist = (List *) 0;
+List *skiplist = NULL;
 
-#ifndef __FreeBSD__
-extern int getopt(int, char*const*, const char*);
-#endif
-
-extern int optind;
-extern char *optarg;
-extern int fclose(FILE*);
-extern void readconfig(char *);
-extern void stringconfig(char *);
 extern void clearState(void);
 
 static void doVersion(void)
@@ -112,7 +104,7 @@ static void doVersion(void)
     exit(0);
 }
 
-static char *languages[] =
+static const char *languages[] =
 {
     "aa",	/* Afar	*/
     "ab",	/* Abkhazian	*/
@@ -256,7 +248,7 @@ static char *languages[] =
     (char *) 0
 };
 
-static char *countries[] =
+static const char *countries[] =
 {
     "AF",	/* AFGHANISTAN */
     "AL",	/* ALBANIA */
@@ -500,11 +492,11 @@ static char *countries[] =
     (char *) 0
 };
 
-static void checkLocale(char *v)
+static void checkLocale(const char *v)
 {
     int l, i, fnd = 0;;
 
-    for (i = 0; languages[i] != (char *) 0; i += 1)
+    for (i = 0; languages[i] != NULL; i += 1)
     {
 	if (strncmp(v, languages[i], 2) == 0)
 	{
@@ -624,7 +616,7 @@ static void usage(void)
 	"\n");
 }
 
-void setOption(int flag, char *value)
+static void setOption(int flag, const char *value)
 {
     int not;
     switch (flag)
@@ -749,9 +741,10 @@ static void setStyle(void)
     }
 }
 
-static void readrc(char *file)
+static void readrc(const char *file)
 {
-    char *opts[50], buff[128], *cp;
+    const char *opts[50];
+    char buff[128], *cp;
     FILE *desc;
     int leng, i;
 
@@ -793,13 +786,9 @@ static void findrc(void)
 
 static void process(FILE *desc)
 {
-    extern void flushOutput(void);
-    extern int handle(Token *line);
-    extern void streamMore(Input *);
-
     Input file;
 
-    file.text = (char *) malloc(64*1024);
+    file.atext = malloc(64*1024);
     file.stream = desc;
     file.tcall = file.texpr = 0;
     file.lineNumber = 1;
@@ -809,12 +798,12 @@ static void process(FILE *desc)
     {
     }
     flushOutput();
-    free(file.text);
+    free(file.atext);
 }
 
 static void initCmds(void)
 {
-    static char *cmdspec =
+    static const char *cmdspec =
 	"set {{var 0x0017} {ctype? 0x0001}}\n"
 	"global {{varlist 0x0150}}\n"
 	"append {{var 0x0017} any args}\n"
@@ -969,7 +958,6 @@ static void initCmds(void)
 int main(int argc, char **argv)
 {
     FILE  *desc;
-    extern void initOutput(void);
 
     initCmds();
     findrc();
