--- kcdbext.h.orig	2012-05-24 16:27:59 UTC
+++ kcdbext.h
@@ -1278,7 +1278,7 @@ class IndexDB {
     if (omode_ == 0) {
       set_error(_KCCODELINE_, BasicDB::Error::INVALID, "not opened");
       *sp = 0;
-      return false;
+      return NULL;
     }
     if (!cache_) return db_.get(kbuf, ksiz, sp);
     size_t dvsiz = 0;
