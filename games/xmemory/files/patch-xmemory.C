--- xmemory.C.orig	1996-07-18 20:10:08.000000000 +0500
+++ xmemory.C	2013-06-11 20:09:44.078362688 +0400
@@ -196,10 +196,11 @@ char *def_disp[MAX_PLAYERS] = {
 	"", "", "", "", "", "", "", "", "", ""
 };
 
+int
 main( int argc, char **argv )
 {
 int i;
-long	timefield;
+time_t	timefield;
 char	main_display[30];
 char	*main_p;
 char *filename;
