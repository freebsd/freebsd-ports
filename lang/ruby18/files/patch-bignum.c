--- bignum.c.orig	Tue Feb 13 02:01:19 2007
+++ bignum.c	Wed May 23 00:37:49 2007
@@ -96,35 +96,49 @@
 }
 
 static VALUE
-bignorm(x)
+bigtrunc(x)
     VALUE x;
 {
-    if (FIXNUM_P(x)) {
-      return x;
-    }
-    else if (TYPE(x) == T_BIGNUM) {
-	long len = RBIGNUM(x)->len;
-	BDIGIT *ds = BDIGITS(x);
-
-	while (len-- && !ds[len]) ;
-	RBIGNUM(x)->len = ++len;
-
-	if (len*SIZEOF_BDIGITS <= sizeof(VALUE)) {
-	    long num = 0;
-	    while (len--) {
-		num = BIGUP(num) + ds[len];
+    long len = RBIGNUM(x)->len;
+    BDIGIT *ds = BDIGITS(x);
+
+    while (len-- && !ds[len]);
+    RBIGNUM(x)->len = ++len;
+    return x;
+}
+
+static VALUE
+bigfixize(VALUE x)
+{
+    long len = RBIGNUM(x)->len;
+    BDIGIT *ds = BDIGITS(x);
+
+    if (len*SIZEOF_BDIGITS <= sizeof(VALUE)) {
+	long num = 0;
+	while (len--) {
+	    num = BIGUP(num) + ds[len];
+	}
+	if (num >= 0) {
+	    if (RBIGNUM(x)->sign) {
+		if (POSFIXABLE(num)) return LONG2FIX(num);
 	    }
-	    if (num >= 0) {
-		if (RBIGNUM(x)->sign) {
-		    if (POSFIXABLE(num)) return LONG2FIX(num);
-		}
-		else if (NEGFIXABLE(-(long)num)) return LONG2FIX(-(long)num);
+	    else {
+		if (NEGFIXABLE(-(long)num)) return LONG2FIX(-(long)num);
 	    }
 	}
     }
     return x;
 }
 
+static VALUE
+bignorm(VALUE x)
+{
+    if (!FIXNUM_P(x) && TYPE(x) == T_BIGNUM) {
+	x = bigfixize(bigtrunc(x));
+    }
+    return x;
+}
+
 VALUE
 rb_big_norm(x)
     VALUE x;
@@ -642,10 +656,10 @@
 	j = j * 53L / 84 + 1;
 	break;
       case 4: case 5: case 6: case 7:
-	j /= 2;
+	j = (j + 1) / 2;
 	break;
       case 8: case 9:
-	j /= 3;
+	j = (j + 2) / 3;
 	break;
       case 10: case 11: case 12: case 13: case 14: case 15:
 	j = j * 28L / 93 + 1;
@@ -653,10 +667,10 @@
       case 16: case 17: case 18: case 19: case 20: case 21:
       case 22: case 23: case 24: case 25: case 26: case 27:
       case 28: case 29: case 30: case 31:
-	j /= 4;
+	j = (j + 3) / 4;
 	break;
       case 32: case 33: case 34: case 35: case 36:
-	j /= 5;
+	j = (j + 4) / 5;
 	break;
       default:
 	rb_raise(rb_eArgError, "illegal radix %d", base);
@@ -1641,10 +1655,10 @@
 		while (yy % 2 == 0) {
 		    yy /= 2;
 		    x = rb_big_mul0(x, x);
-		    if (!BDIGITS(x)[RBIGNUM(x)->len-1]) RBIGNUM(x)->len--;
+		    bigtrunc(x);
 		}
 		z = rb_big_mul0(z, x);
-		if (!BDIGITS(z)[RBIGNUM(z)->len-1]) RBIGNUM(z)->len--;
+		bigtrunc(z);
 	    }
 	    return bignorm(z);
 	}
