--- ./src/Mixfix/token.cc.orig	2014-09-03 02:58:50.000000000 +0200
+++ ./src/Mixfix/token.cc	2014-09-03 02:59:18.000000000 +0200
@@ -632,7 +632,7 @@
 	      }
 	  }
 	}
-      result.append(c);
+      result.push_back(c);
       seenBackslash = false;
     }
   CantHappen("bad end to string");
