--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Errors.c	Tue Feb 15 14:26:34 1994
+++ ./reuse/c/Errors.c	Fri Sep 10 13:35:02 2004
@@ -14,8 +14,11 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Juli 1992 */
 
-static char rcsid [] = "$Id: Errors.c,v 1.2 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: Errors.c,v 1.2 1993/08/18 15:01:05 grosch rel $");
 
+# include <string.h>
+# include <stdlib.h>
 # include "Errors.h"
 
 # ifdef __cplusplus
@@ -34,9 +37,9 @@
 
 # define MaxError	100
 
-static void yyExit () { rExit (1); }
+static void yyExit (NOARGS) { rExit (1); }
 
-void (* Errors_Exit) () = yyExit;
+void (* Errors_Exit) (NOARGS) = yyExit;
 
 typedef struct {
    tPosition	Position;
@@ -63,13 +66,14 @@
 static void WriteInfo	ARGS((int InfoClass, char * Info));
 static void WriteMessage ARGS((bool IsErrorCode, int ErrorCode, int ErrorClass, tPosition Position, int InfoClass, char * Info));
 static void StoreMessage ARGS((bool IsErrorCode, int ErrorCode, int ErrorClass, tPosition Position, int InfoClass, char * Info));
-static int IsLess	ARGS((tError * i, tError * j));
+static int IsLess	ARGS((const void * i, const void * j));
 
 static tError	ErrorTable [MaxError + 1];
 static int	MessageCount;
 static bool	IsStore		= false;
 static void (*	HandleMessage) ARGS((bool IsErrorCode, int ErrorCode, int ErrorClass, tPosition Position, int InfoClass, char * Info)) = WriteMessage;
-static FILE *	Out			= stderr;
+static FILE *	Out = NULL;
+/*			= stderr; */
 
 void ErrorMessage
 # if defined __STDC__ | defined __cplusplus
@@ -122,6 +126,7 @@
    (Position, ErrorClass) tPosition Position; int ErrorClass;
 # endif
 {
+   if (Out==NULL) {Out = stderr;}
    WritePosition (Out, Position);
    (void) fputs (": ", Out);
    switch (ErrorClass) {
@@ -143,6 +148,7 @@
    (ErrorCode) int ErrorCode;
 # endif
 {
+   if (Out==NULL) {Out = stderr;}
    switch (ErrorCode) {
    case xxNoText	: break;
    case xxSyntaxError	: (void) fputs ("syntax error"		, Out); break;
@@ -163,6 +169,7 @@
 {
    int i;
    if (InfoClass == xxNone) return;
+   if (Out==NULL) {Out = stderr;}
    (void) fputs (": ", Out);
    switch (InfoClass) {
    case xxInteger	: (void) fprintf (Out, "%d", * (int *) Info); break;
@@ -201,10 +208,10 @@
 # endif
 {
    int i;
-   char * Info;
+   char * Info = NULL;
    char s [256];
 
-   qsort ((char *) & ErrorTable [1], MessageCount, sizeof (tError), IsLess);
+   qsort ((char *) & ErrorTable [1], MessageCount, sizeof (tError), (&IsLess));
    Out = File;
    for (i = 1; i <= MessageCount; i ++) {
       register tError * With = & ErrorTable [i];
@@ -273,13 +280,13 @@
 
 static int IsLess
 # if defined __STDC__ | defined __cplusplus
-   (tError * i, tError * j)
+   ( const void * i, const void * j)
 # else
    (i, j) tError * i, * j;
 # endif
 {
-  register int r = Compare (i->Position, j->Position);
-  return r != 0 ? r : i->ErrorNumber - j->ErrorNumber;
+  register int r = Compare ((tPosition)(((tError*)i)->Position), (tPosition)(((tError*)j)->Position));
+  return r != 0 ? r : (int)(((tError*)i)->ErrorNumber - ((tError*)j)->ErrorNumber);
 }
 
 void StoreMessages
