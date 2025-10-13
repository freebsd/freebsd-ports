--- src/robust_predicate/expansion/mp_basic.hpp.orig	2025-10-13 12:47:59 UTC
+++ src/robust_predicate/expansion/mp_basic.hpp
@@ -69,6 +69,11 @@
     --------------------------------------------------------
      */
 
+#ifndef SINGLE_DEFINED
+using single = float;
+#define SINGLE_DEFINED
+#endif
+
 #   pragma once
 
 #   ifndef __MP_BASIC__
