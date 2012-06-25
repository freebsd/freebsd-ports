--- ../svxlink-11.05.orig/svxlink/trx/SwDtmfDecoder.cpp	2010-05-16 09:32:17.000000000 -0700
+++ svxlink/trx/SwDtmfDecoder.cpp	2012-05-28 10:27:56.000000000 -0700
@@ -37,6 +37,7 @@
 #include <cstdlib>
 
 #include <stdint.h>
+#define exp10f(x) exp((x)*log(10))
 
 
 
