--- sort/sort.c.orig	2024-12-27 22:10:51 UTC
+++ sort/sort.c
@@ -108,7 +108,7 @@ void	done(char*);
 void	dokey_m(Key*, uchar*, uchar*, Field*);
 void	dokey_r(Key*, uchar*, uchar*, Field*);
 void	done(char*);
-int	kcmp(Key*, Key*);
+int	kcmp2(Key*, Key*);
 void	makemapd(Field*);
 void	makemapm(Field*);
 void	mergefiles(int, int, Biobuf*);
@@ -202,7 +202,7 @@ dofile(Biobuf *b)
 			l = newline(b);
 			if(l == 0)
 				break;
-			n = kcmp(ol->key, l->key);
+			n = kcmp2(ol->key, l->key);
 			if(n > 0 || (n == 0 && args.uflag)) {
 				fprint(2, "sort: -c file not in sort\n"); /**/
 				done("order");
@@ -448,7 +448,7 @@ mergefiles(int t, int n, Biobuf *b)
 			break;
 		for(;;) {
 			l = m->line;
-			if(args.uflag && ok && kcmp(ok, l->key) == 0) {
+			if(args.uflag && ok && kcmp2(ok, l->key) == 0) {
 				free(l->key);
 				free(l);
 			} else {
@@ -467,7 +467,7 @@ mergefiles(int t, int n, Biobuf *b)
 			}
 			m->line = l;
 			m->key = l->key;
-			if(nn > 1 && kcmp(mmp[0]->key, mmp[1]->key) > 0)
+			if(nn > 1 && kcmp2(mmp[0]->key, mmp[1]->key) > 0)
 				break;
 		}
 	}
@@ -485,7 +485,7 @@ int
 }
 
 int
-kcmp(Key *ka, Key *kb)
+kcmp2(Key *ka, Key *kb)
 {
 	int n, m;
 
@@ -511,7 +511,7 @@ printout(Biobuf *b)
 	ok = 0;
 	for(n=args.nline; n>0; n--) {
 		l = *lp++;
-		if(args.uflag && ok && kcmp(ok, l->key) == 0)
+		if(args.uflag && ok && kcmp2(ok, l->key) == 0)
 			continue;
 		lineout(b, l);
 		ok = l->key;
