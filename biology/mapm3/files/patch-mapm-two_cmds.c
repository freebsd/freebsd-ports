--- mapm/two_cmds.c.orig	1993-02-09 16:35:06 UTC
+++ mapm/two_cmds.c
@@ -698,11 +698,11 @@ command three_point()
 
 	if (!print_names) {
 print("\n                    log-likelihood differences\n");
-print(  " count  markers         a-b-c  b-a-c  a-c-b\n");
+print(" count  markers         a-b-c  b-a-c  a-c-b\n");
 	    /*       12345:   1234 1234 1234 */
 	} else {
 print("\n                                     log-likelihood differences\n");
-print(  " count  markers                        a-b-c  b-a-c  a-c-b\n");
+print(" count  markers                        a-b-c  b-a-c  a-c-b\n");
 	    /*       12345:   123456789 123456789 123456789  */
 	}
 
