--- src/Meta/metaMatch.cc.orig	2018-08-27 20:58:55 UTC
+++ src/Meta/metaMatch.cc
@@ -172,7 +172,7 @@ MetaLevelOpSymbol::makeMatchSearchState2(MetaModule* m
 	    }
 	}
     }
-  return false;
+  return NULL;
 }
 
 bool
