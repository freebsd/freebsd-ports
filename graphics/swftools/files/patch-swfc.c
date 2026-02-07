--- src/swfc.c.orig	2012-04-08 17:25:26 UTC
+++ src/swfc.c
@@ -4056,7 +4056,7 @@ static int c_on_key(map_t*args)
 	if(key[0]>=32) {
 	    current_button_flags |= 0x4000 + (key[0]*0x200);
 	} else {
-	    syntaxerror("invalid character: %c"+key[0]);
+	    syntaxerror("invalid character: %c",key[0]);
 	    return 1;
 	}
     } else {
