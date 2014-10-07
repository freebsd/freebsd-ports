--- make.c.orig	2014-08-07 15:26:13.000000000 +0200
+++ make.c	2014-08-07 15:27:53.000000000 +0200
@@ -69,6 +69,10 @@
 # define max( a,b ) ((a)>(b)?(a):(b))
 # endif
 
+# if defined ( OS_FREEBSD )
+# include <unistd.h> // unlink(2)
+# endif
+
 typedef struct {
 	int	temp;
 	int	updating;
@@ -169,7 +173,7 @@
 	COUNTS	*counts,	/* for reporting */
 	int	anyhow )	/* forcibly touch all (real) targets */
 {
-	TARGETS	*c, *d, *incs;
+	TARGETS	*c, *incs;
 	TARGET 	*ptime = t;
 	time_t	last, leaf, hlast;
 	int	fate;
@@ -246,7 +250,7 @@
 	    case T_BIND_MISSING:
 	    case T_BIND_PARENTS:
 		printf( "time\t--\t%s%s: %s\n",
-			spaces( depth ), t->name, target_bind[ t->binding ] );
+			spaces( depth ), t->name, target_bind[ (int)t->binding ] );
 		break;
 
 	    case T_BIND_EXISTS:
@@ -481,13 +485,13 @@
 
 	if( DEBUG_MAKEPROG )
 	    printf( "made%s\t%s\t%s%s\n",
-		flag, target_fate[ t->fate ],
+		flag, target_fate[ (int)t->fate ],
 		spaces( depth ), t->name );
 
 	if( DEBUG_CAUSES &&
 	    t->fate >= T_FATE_NEWER &&
 	    t->fate <= T_FATE_MISSING )
-		printf( "%s %s\n", target_fate[ t->fate ], t->name );
+		printf( "%s %s\n", target_fate[ (int)t->fate ], t->name );
 }
 
 /*
