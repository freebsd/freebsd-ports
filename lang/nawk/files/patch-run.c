--- run.c.orig	Mon Dec  6 06:44:42 2004
+++ run.c	Sat Feb 26 18:01:46 2005
@@ -1507,15 +1507,15 @@
 		u = (Awkfloat) system(getsval(x)) / 256;   /* 256 is unix-dep */
 		break;
 	case FRAND:
-		/* in principle, rand() returns something in 0..RAND_MAX */
-		u = (Awkfloat) (rand() % RAND_MAX) / RAND_MAX;
+		/* in principle, random() returns something in 0..RAND_MAX */
+		u = (Awkfloat) (random() % RAND_MAX) / RAND_MAX;
 		break;
 	case FSRAND:
 		if (isrec(x))	/* no argument provided */
 			u = time((time_t *)0);
 		else
 			u = getfval(x);
-		srand((unsigned int) u);
+		srandom((unsigned int) u);
 		break;
 	case FTOUPPER:
 	case FTOLOWER:
