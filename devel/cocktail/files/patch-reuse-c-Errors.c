--- ../../work/cocktail-9309//./reuse/c/Errors.c	Tue Feb 15 14:26:34 1994
+++ ./reuse/c/Errors.c	Wed Mar 31 22:35:06 2004
@@ -69,7 +69,8 @@
 static int	MessageCount;
 static bool	IsStore		= false;
 static void (*	HandleMessage) ARGS((bool IsErrorCode, int ErrorCode, int ErrorClass, tPosition Position, int InfoClass, char * Info)) = WriteMessage;
-static FILE *	Out			= stderr;
+static FILE *	Out = NULL;
+/*			= stderr; */
 
 void ErrorMessage
 # if defined __STDC__ | defined __cplusplus
@@ -122,6 +123,7 @@
    (Position, ErrorClass) tPosition Position; int ErrorClass;
 # endif
 {
+   if (Out==NULL) {Out = stderr;}
    WritePosition (Out, Position);
    (void) fputs (": ", Out);
    switch (ErrorClass) {
@@ -143,6 +145,7 @@
    (ErrorCode) int ErrorCode;
 # endif
 {
+   if (Out==NULL) {Out = stderr;}
    switch (ErrorCode) {
    case xxNoText	: break;
    case xxSyntaxError	: (void) fputs ("syntax error"		, Out); break;
@@ -163,6 +166,7 @@
 {
    int i;
    if (InfoClass == xxNone) return;
+   if (Out==NULL) {Out = stderr;}
    (void) fputs (": ", Out);
    switch (InfoClass) {
    case xxInteger	: (void) fprintf (Out, "%d", * (int *) Info); break;
