--- mapm/two_cmds.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ mapm/two_cmds.c	2008-04-03 19:58:42.000000000 +0000
@@ -698,11 +698,11 @@
 
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
 
