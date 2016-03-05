--- matlib/mat.hh.orig	2003-01-05 19:19:33 UTC
+++ matlib/mat.hh
@@ -91,36 +91,6 @@ template<typename T> void mmul(T *c, con
                 memcpy(c, r, d1 * d3 * sizeof(c[0]));
 }
 
-template<typename T> void mdet(const T *c, unsigned int d)
-{
-        T *c2;
-        unsigned int i, j, k, l;
-        T det = 0, dr;
-
-        if (!d)
-                return 0;
-        if (d == 1)
-                return c[0];
-        if (d == 2)
-                return c[0] * c[3] - c[1] * c[2];
-        c2 = alloca(sizeof(T)*(d-1)*(d-1));
-        for (i = 0; i < d; i++) {
-                for (j = k = 0; j < d; j++) {
-                        if (j == i)
-                                continue;
-                        for (l = 0; l < d-1; l++)
-                                c2[l*(d-1)+k] = c[(l+1)*d+j];
-                        k++;
-                }
-                dr = mdet(c2, d-1);
-                if (i & 1)
-                        det -= dr * c[i];
-                else
-                        det += dr * c[i];
-        }
-        return det;
-}
-
 /* Transpose a matrix (a el C^{d1 x d2}, b el C^{d2 x d1}) */
 template<typename T> void mtranspose(T *b, const T *a, unsigned int d1, unsigned int d2)
 {
@@ -440,23 +410,6 @@ template<typename T> void mlusolve(T *x,
 	}
 }
 
-template<typename T> void minv(T *ainv, const T *a, unsigned int d)
-{
-	T *u, *y;
-	unsigned int *p;
-	unsigned int k;
-
-	u = alloca(d * d * sizeof(u[0]));
-	p = alloca((d-1) * sizeof(p[0]));
-	mlufact(u, p, a, d);
-	for (k = 0; k < d; k++) {
-		y = &ainv[k*d];
-		memset(y, 0, d * sizeof(y[0]));
-		y[k] = T(1);
-		mlusolve(y, y, u, p, d);
-	}
-	mtranspose(ainv, ainv, d, d);
-}
 
 /*
  * Gauss-Seidel iterative solver
