--- rlparse.y.orig	Sat Jul  3 03:46:42 2004
+++ rlparse.y	Mon Aug  2 22:24:05 2004
@@ -468,7 +468,7 @@
 NoNameSep:
 	/* Nothing */ {
 		nameRef.empty();
-	}
+	};
 
 /* A qualified state reference. */
 StateRef:
@@ -483,7 +483,7 @@
 	} |
 	/* Nothing. */ {
 		nameRef.empty();
-	}
+	};
 
 /* List of names separated by :: */
 StateRefNames:
