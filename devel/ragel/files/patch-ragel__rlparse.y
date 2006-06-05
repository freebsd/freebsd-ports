--- ragel/rlparse.y.orig	Mon May 15 01:28:37 2006
+++ ragel/rlparse.y	Sat May 20 14:19:21 2006
@@ -1092,7 +1092,7 @@
 	} |
 	Factor { 
 		$$ = $1;
-	}
+	};
 
 /* The highest level in precedence. Atomic machines such as references to other
  * machines, literal machines, regular expressions or Expressions in side of
