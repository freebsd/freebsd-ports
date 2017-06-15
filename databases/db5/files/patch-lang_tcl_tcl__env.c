--- lang/tcl/tcl_env.c.orig	2013-09-09 15:35:07 UTC
+++ lang/tcl/tcl_env.c
@@ -2864,9 +2864,10 @@ env_GetFlags(interp, objc, objv, dbenv)
 		for (i = 0; open_flags[i].flag != 0; i++)
 			if (LF_ISSET(open_flags[i].flag)) {
 				if (strlen(buf) > 0)
-					(void)strncat(buf, " ", sizeof(buf));
-				(void)strncat(
-				    buf, open_flags[i].arg, sizeof(buf));
+					(void)strncat(buf, " ",
+					    sizeof(buf) - (strlen(buf) + 1));
+				(void)strncat(buf, open_flags[i].arg,
+				    sizeof(buf) - (strlen(buf) + 1));
 			}
 
 		res = NewStringObj(buf, strlen(buf));
@@ -2930,9 +2931,10 @@ env_GetOpenFlag(interp, objc, objv, dben
 		for (i = 0; open_flags[i].flag != 0; i++)
 			if (LF_ISSET(open_flags[i].flag)) {
 				if (strlen(buf) > 0)
-					(void)strncat(buf, " ", sizeof(buf));
-				(void)strncat(
-				    buf, open_flags[i].arg, sizeof(buf));
+					(void)strncat(buf, " ",
+					    sizeof(buf) - (strlen(buf) + 1));
+				(void)strncat(buf, open_flags[i].arg,
+				    sizeof(buf) - (strlen(buf) + 1));
 			}
 
 		res = NewStringObj(buf, strlen(buf));
@@ -2982,9 +2984,10 @@ tcl_EnvGetEncryptFlags(interp, objc, obj
 		for (i = 0; encrypt_flags[i].flag != 0; i++)
 			if (LF_ISSET(encrypt_flags[i].flag)) {
 				if (strlen(buf) > 0)
-					(void)strncat(buf, " ", sizeof(buf));
-				(void)strncat(
-				    buf, encrypt_flags[i].arg, sizeof(buf));
+					(void)strncat(buf, " ",
+					    sizeof(buf) - (strlen(buf) + 1));
+				(void)strncat(buf, encrypt_flags[i].arg,
+				    sizeof(buf) - (strlen(buf) + 1));
 			}
 
 		res = NewStringObj(buf, strlen(buf));
