--- src/numbers.c.orig	Sat May 31 17:50:08 2003
+++ src/numbers.c	Sat May 31 18:15:24 2003
@@ -2696,13 +2696,14 @@
 #ifdef HAVE_GMP
     else
     {
-	rep_number_q *q;
+	double x, y;
+	rep_number_z *z;
 
-	q = make_number (rep_NUMBER_RATIONAL);
-	mpq_init (q->q);
-	mpq_set_d (q->q, rep_get_float (arg));
+	rationalize (arg, &x, &y);
+	z = make_number (rep_NUMBER_BIGNUM);
+	mpz_init_set_d (z->z, (x / y));
 
-	return maybe_demote (rep_VAL (q));
+	return maybe_demote (rep_VAL (z));
     }
 #else
     else
