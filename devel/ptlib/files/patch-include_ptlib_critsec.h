--- include/ptlib/critsec.h.orig	2013-02-20 02:12:17 UTC
+++ include/ptlib/critsec.h
@@ -40,11 +40,7 @@
 #if P_HAS_ATOMIC_INT
 
 #if defined(__GNUC__)
-#  if __GNUC__ >= 4 && __GNUC_MINOR__ >= 2
 #     include <ext/atomicity.h>
-#  else
-#     include <bits/atomicity.h>
-#  endif
 #endif
 
 #if P_NEEDS_GNU_CXX_NAMESPACE
