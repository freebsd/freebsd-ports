--- src/cgen.c.orig	Thu Apr  7 20:17:27 2005
+++ src/cgen.c	Sun Apr 17 20:21:22 2005
@@ -102,6 +102,7 @@
 void	CG_genpids( NODE_T * );
 void	CG_genpdecl( NODE_T * );
 char	*CG_gentemp( int );
+void	CG_gennull( void );
 
 static	int	getdims( NODE_T *, int, int, int *, NODE_T *[] );
 static	NODE_T	*mk_arraysize( int, NODE_T *[], int );
@@ -115,6 +116,10 @@
 static	void	CG_debug( char [], NODE_T *, int );
 
 FILE	*tmpfile();
+
+void	CG_gennull( )
+{
+}
 
 int	CG_init( char cfname[], int aopt )
 {
