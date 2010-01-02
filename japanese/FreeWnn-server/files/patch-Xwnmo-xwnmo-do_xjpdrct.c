Index: Xwnmo/xwnmo/do_xjpdrct.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Xwnmo/xwnmo/do_xjpdrct.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Xwnmo/xwnmo/do_xjpdrct.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Xwnmo/xwnmo/do_xjpdrct.c	20 Dec 2008 07:23:12 -0000	1.2
@@ -89,8 +89,6 @@ extern int cur_sock;
 #define sock_clr(array,pos)     (array[pos/BINTSIZE] &= ~(1<<(pos%BINTSIZE)))
 #define sock_tst(array,pos)     (array[pos/BINTSIZE] & (1<<(pos%BINTSIZE)))
 
-extern int read (), write ();
-
 extern XJpClientRec *xjp_clients;
 extern XJpClientRec *xjp_cur_client;
 extern XJpInputRec *xjp_inputs;
