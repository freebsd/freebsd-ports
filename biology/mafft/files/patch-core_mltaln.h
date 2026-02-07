--- core/mltaln.h.orig	2015-11-26 01:42:39 UTC
+++ core/mltaln.h
@@ -182,6 +182,8 @@ extern int conjuctionfortbfast();
 extern int fastconjuction();
 extern char seqcheck( char ** );
 
+extern int deletenewinsertions_whole_eq( int on, int an, char **oseq, char **aseq, int **deletelist );
+
 typedef struct _LocalHom
 {
 	int nokori;
