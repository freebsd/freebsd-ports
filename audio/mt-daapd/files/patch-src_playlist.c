--- src/playlist.c.orig	2008-04-19 21:31:30.000000000 +0200
+++ src/playlist.c	2008-07-18 16:32:13.000000000 +0200
@@ -352,7 +352,7 @@ int pl_eval_node(MP3FILE *pmp3, PL_NODE 
 	    retval = not ? r_arg : !r_arg;
 	    break;
 	case INCLUDES:
-	    r_arg=(int)strcasestr(cval,pnode->arg2.cval);
+	    r_arg=!!strcasestr(cval,pnode->arg2.cval);
 	    retval = not ? !r_arg : r_arg;
 	    break;
 	}
