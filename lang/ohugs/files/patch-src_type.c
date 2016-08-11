--- src/type.c.orig	2000-12-06 09:23:55 UTC
+++ src/type.c
@@ -1165,7 +1165,7 @@ Type t; {
                         break;
         case QUAL     : snd(snd(t)) = freshSig(snd(snd(t)));
                         break;
-        case NULL     : 
+        case NIL      : 
 	case OFFSET   : 
 	case INTCELL  : 
 	case TYCON    :
