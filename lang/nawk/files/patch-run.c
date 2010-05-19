--- run.c.orig	2009-11-26 23:59:16.000000000 +0000
+++ run.c	2010-04-29 22:50:49.000000000 +0000
@@ -1504,20 +1504,78 @@
 			nextarg = nextarg->nnext;
 		}
 		break;
+	case FCOMPL:
+		u = ~((int)getfval(x));
+		break;
+	case FAND:
+		if (nextarg == 0) {
+			WARNING("and requires two arguments; returning 0");
+			u = 0;
+			break;
+		}
+		y = execute(a[1]->nnext);
+		u = ((int)getfval(x)) & ((int)getfval(y));
+		tempfree(y);
+		nextarg = nextarg->nnext;
+		break;
+	case FFOR:
+		if (nextarg == 0) {
+			WARNING("or requires two arguments; returning 0");
+			u = 0;
+			break;
+		}
+		y = execute(a[1]->nnext);
+		u = ((int)getfval(x)) | ((int)getfval(y));
+		tempfree(y);
+		nextarg = nextarg->nnext;
+		break;
+	case FXOR:
+		if (nextarg == 0) {
+			WARNING("or requires two arguments; returning 0");
+			u = 0;
+			break;
+		}
+		y = execute(a[1]->nnext);
+		u = ((int)getfval(x)) ^ ((int)getfval(y));
+		tempfree(y);
+		nextarg = nextarg->nnext;
+		break;
+	case FLSHIFT:
+		if (nextarg == 0) {
+			WARNING("or requires two arguments; returning 0");
+			u = 0;
+			break;
+		}
+		y = execute(a[1]->nnext);
+		u = ((int)getfval(x)) << ((int)getfval(y));
+		tempfree(y);
+		nextarg = nextarg->nnext;
+		break;
+	case FRSHIFT:
+		if (nextarg == 0) {
+			WARNING("or requires two arguments; returning 0");
+			u = 0;
+			break;
+		}
+		y = execute(a[1]->nnext);
+		u = ((int)getfval(x)) >> ((int)getfval(y));
+		tempfree(y);
+		nextarg = nextarg->nnext;
+		break;
 	case FSYSTEM:
 		fflush(stdout);		/* in case something is buffered already */
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
