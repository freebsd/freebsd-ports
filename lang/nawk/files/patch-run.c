--- run.c.orig	Mon Oct 30 13:26:57 2000
+++ run.c	Mon Apr 30 00:00:26 2001
@@ -1483,15 +1483,15 @@
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
