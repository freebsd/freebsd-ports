--- meshlabplugins/filter_poisson/src/Geometry.inl.orig	2013-10-31 09:51:50.000000000 +0100
+++ meshlabplugins/filter_poisson/src/Geometry.inl	2013-10-31 09:52:01.000000000 +0100
@@ -26,6 +26,8 @@
 DAMAGE.
 */
 
+#include <stdlib.h>
+
 template<class Real>
 Real Random(void){return Real(rand())/RAND_MAX;}
 
