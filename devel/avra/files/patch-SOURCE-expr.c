--- SOURCE/expr.c.orig	Thu Jun 10 21:01:40 2004
+++ SOURCE/expr.c	Mon Feb 14 21:30:15 2005
@@ -241,7 +241,7 @@
 }
 
 
-int log2(int value)
+int do_log2(int value)
 {
 	int i = 0;
 
@@ -271,7 +271,7 @@
 		case FUNCTION_EXP2:
 			return(1 << value);
 		case FUNCTION_LOG2:
-			return(log2(value));
+			return(do_log2(value));
 		default:
 			return(0);
 	}
