--- lang/tcl/tcl_seq.c.orig	2013-09-09 15:35:07 UTC
+++ lang/tcl/tcl_seq.c
@@ -555,9 +555,10 @@ tcl_SeqGetFlags(interp, objc, objv, seq)
 		for (i = 0; seq_flags[i].flag != 0; i++)
 			if (LF_ISSET(seq_flags[i].flag)) {
 				if (strlen(buf) > 0)
-					(void)strncat(buf, " ", sizeof(buf));
-				(void)strncat(
-				    buf, seq_flags[i].arg, sizeof(buf));
+					(void)strncat(buf, " ",
+					    sizeof(buf) - (strlen(buf) + 1));
+				(void)strncat(buf, seq_flags[i].arg,
+				    sizeof(buf) - (strlen(buf) + 1));
 			}
 
 		res = NewStringObj(buf, strlen(buf));
