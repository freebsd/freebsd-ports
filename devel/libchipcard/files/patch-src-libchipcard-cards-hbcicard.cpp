--- src/libchipcard/cards/hbcicard.cpp.orig	2007-10-12 09:54:53.000000000 +0200
+++ src/libchipcard/cards/hbcicard.cpp	2007-10-12 09:53:18.000000000 +0200
@@ -684,8 +684,8 @@
   case k_HBCICARD_TYPE_1:
     return _hash2mac1(hash,mac);
   default:
-    DBG_INFO("LIBCHIPCARD: unknown chip card type (%8x) (%d).",
-	     (unsigned int)this,
+    DBG_INFO("LIBCHIPCARD: unknown chip card type (%p) (%d).",
+	     this,
 	    _type);
     return false;
   }

