--- src/type.c.orig	Fri Jan 21 12:05:35 2005
+++ src/type.c	Fri Jan 21 12:05:47 2005
@@ -1165,7 +1165,7 @@
                         break;
         case QUAL     : snd(snd(t)) = freshSig(snd(snd(t)));
                         break;
-        case NULL     : 
+        case NIL      : 
 	case OFFSET   : 
 	case INTCELL  : 
 	case TYCON    :
