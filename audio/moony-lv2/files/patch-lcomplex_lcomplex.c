--- lcomplex/lcomplex.c.orig	2017-05-16 21:46:21 UTC
+++ lcomplex/lcomplex.c
@@ -7,6 +7,7 @@
 */
 
 #include <complex.h>
+#include <math.h>
 
 #include "lua.h"
 #include "lauxlib.h"
@@ -78,6 +79,32 @@ static int Ltostring(lua_State *L)		/** 
  return 1;
 }
 
+// Missing C99 functions clog and cpow: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221341
+static Complex clog(Complex z) {return log(cabs(z)) + I * carg(z);}
+// from https://github.com/eblot/newlib/blob/master/newlib/libm/complex/cpow.c
+static Complex
+cpow(Complex a, Complex z)
+{
+	double complex w;
+	double x, y, r, theta, absa, arga;
+
+	x = creal(z);
+	y = cimag(z);
+	absa = cabs(a);
+	if (absa == 0.0) {
+		return (0.0 + 0.0 * I);
+	}
+	arga = carg(a);
+	r = pow(absa, x);
+	theta = x * arga;
+	if (y != 0.0) {
+		r = r * exp(-y * arga);
+		theta = theta + y * log(absa);
+	}
+	w = r * cos(theta) + (r * sin(theta)) * I;
+	return w;
+}
+
 #define A(f,e)	static int L##f(lua_State *L) { return pushcomplex(L,e); }
 #define B(f)	A(f,l_mathop(c##f)(Z(1),Z(2)))
 #define F(f)	A(f,l_mathop(c##f)(Z(1)))
