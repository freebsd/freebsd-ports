--- lib-src/sincosl.c.orig	Tue Oct  3 17:28:31 2006
+++ lib-src/sincosl.c	Tue Oct  3 17:28:33 2006
@@ -228,7 +228,7 @@
    Computed using gmp.
  */
 
-const long double sincosl_table[] = {
+static const long double sincosl_table[] = {
 
 /* x =  1.48437500000000000000000000000000000e-01L 3ffc3000000000000000000000000000 */
 /* cos(x) = 0.fd2f5320e1b790209b4dda2f98f79caaa7b873aff1014b0fbc5243766d03cb006bc837c4358 */
